#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

const QString MainWindow::fileDialogFilterString = tr("SQLite Database Files (*.sqlite3 *.sqlite *.db *.db3 *.sl3 *.s3db *.sdb *.sqlite2 *.db2 *.sl2 *.s2db)");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUserInterfaceEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete query;
    delete model;
}

// Метод показывающий диалоговое окно для выбора файла для новой базы данных:
void MainWindow::on_actionCreateNewDatabase_triggered()
{
    QString dbFileFullPath = QFileDialog::getSaveFileName(this, tr("Save SQLite Database File"), "", MainWindow::fileDialogFilterString);
    initAppWithDatabaseFile(dbFileFullPath);
}

// Метод показывающий диалоговое окно для выбора файла для открытия созданной ранее базы данных:
void MainWindow::on_actionOpenDatabase_triggered()
{
    QString dbFileFullPath = QFileDialog::getOpenFileName(this, tr("Open SQLite Database File"), "", MainWindow::fileDialogFilterString);
    initAppWithDatabaseFile(dbFileFullPath);
}

void MainWindow::initAppWithDatabaseFile(const QString &dbFileFullPath) {
    qDebug() << "dbFileFullPath=" << dbFileFullPath;
    if (dbFileFullPath.isEmpty()) return;
    connectToDatabase(dbFileFullPath);
    createModel();
    setUserInterfaceEnabled(true);
}

// Метод для создания новой базы данных или открытия созданной ранее:
void MainWindow::connectToDatabase(const QString &dbName)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");  // соединение объекта базы данных с СУБД.
    m_db.setDatabaseName(dbName);  // определение имени базы данных.
    if (!m_db.open())  // проверка на ошибку при открытии или создании базы данных.
        throw "Can't open database!";
    query = new QSqlQuery(m_db);  // создание объекта для запроса.
    if (!m_db.tables().contains("employees"))  // если в базе не существует таблица employees
    {  // то создание таблицы employees:

        qDebug() << "В базе не существует таблица employees!";

        query->clear();  // очистка запроса.

        qDebug() << "Создание таблицы employees:" <<
        query->exec("CREATE TABLE employees(" \
            " id INTEGER PRIMARY KEY NOT NULL,  /* идентификатор */" \
            " last_name TEXT,                   /* фамилия */" \
            " first_name TEXT,                  /* имя */" \
            " occupation TEXT,                  /* род занятий (сотрудник, студент) */" \
            " year_of_admission INTEGER         /* год поступления */" \
            ");");  // исполнение запроса на добавление записи.
    }
}

void MainWindow::createModel()
{
    model = new QSqlTableModel(this, m_db);  // создание редактируемой модели базы данных.

    model->setTable("employees");  // создание модели таблицы employees.
    model->select();  // заполнение модели данными.

    // Выбор стратегии сохранения изменений в базе данных:
    model->setEditStrategy(QSqlTableModel::OnFieldChange);  // сохранение происходит при переходе к другому полю.

    ui->tableViewEmployees->setModel(model);  // соединение модели и ее табличного представления в форме.

    model->setHeaderData(0, Qt::Horizontal, tr("Код"));
    model->setHeaderData(1, Qt::Horizontal, tr("Фамилия"));
    model->setHeaderData(2, Qt::Horizontal, tr("Имя"));
    model->setHeaderData(3, Qt::Horizontal, tr("Род занятий"));
    model->setHeaderData(4, Qt::Horizontal, tr("Год поступления"));
}

// Метод для выхода из программы:
void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
    // QApplication::quit();  // QApplication наследник QCoreApplication.
}

// Метод для "включения" пользовательского интерфейса:
void MainWindow::setUserInterfaceEnabled(bool isEnanbled) {
    ui->tableViewEmployees->setEnabled(isEnanbled);
    ui->groupBoxAddRecord->setEnabled(isEnanbled);
    ui->groupBoxDeleteRecord->setEnabled(isEnanbled);
    ui->groupBoxSort->setEnabled(isEnanbled);
    ui->groupBoxFiltration->setEnabled(isEnanbled);
}

// Метод для добавления записи произвольного содержания в базу данных:
void MainWindow::on_pushButtonAddRecord_clicked()
{
    query->clear();
    query->prepare("SELECT MAX(e.id) AS 'number_of_employees' FROM employees AS 'e';");
    query->exec();
    if (!query->isActive())
        QMessageBox::warning(this, tr("Database Error"), query->lastError().text());
    query->next();
    QString id = QString::number(query->value(0).toInt() + 1);

    QString lastName = ui->lineEditLastName->text();
    QString firstName = ui->lineEditFirstName->text();
    QString occupation = ui->comboBoxOccupation->currentText();
    QString yeaOfAdmission = ui->spinBoxYearOfAdmission->text();
    qDebug() << "идентификатор=" << id << "фамилия=" << lastName << " имя=" << firstName << " род_занятий=" << occupation << " год_поступления=" << yeaOfAdmission;

    if (id.isEmpty() || lastName.isEmpty() || firstName.isEmpty() || occupation.isEmpty() || yeaOfAdmission.isEmpty())
        return;

    query->clear();

    qDebug() << "Добавление строки:" <<
    query->prepare("INSERT INTO employees(id, last_name, first_name, occupation, year_of_admission) " \
                   "VALUES(:id, :last_name, :first_name, :occupation, :year_of_admission)");
    query->bindValue(":id", id);
    query->bindValue(":last_name", lastName);
    query->bindValue(":first_name", firstName);
    query->bindValue(":occupation", occupation);
    query->bindValue(":year_of_admission", yeaOfAdmission);
    query->exec();

    model->select();  // наполнить модель данными из таблицы, учитывая условия фильтрации и сортировки.
}

// Метод для удаление записи с заданным номером из базы данных:
void MainWindow::on_pushButtonDeleteRecord_clicked()
{
    if (ui->spinBoxID->text().isEmpty())
        return;

    QString id = ui->spinBoxID->text();

    query->clear();

    qDebug() << "Удаление строки:" <<
    query->exec(QString("DELETE FROM employees WHERE id = %1;").arg(id));

    model->select();  // наполнить модель данными из таблицы, учитывая условия фильтрации и сортировки.
}

// Метод для просмотра содержимого всей базы данных:
void MainWindow::on_pushButtonShowAllData_clicked()
{
    model->setFilter("");
    model->select();  // наполнить модель данными из таблицы, учитывая условия фильтрации и сортировки.
}

// Метод для просмотра содержимого базы данных с сортировкой:
void MainWindow::on_pushButtonSortData_clicked()
{
    Qt::SortOrder order;
    switch (ui->comboBoxSortOrder->currentIndex()) {
    case 0: order = Qt::AscendingOrder;  break;
    case 1: order = Qt::DescendingOrder; break;
    default: break;
    }
    model->setSort(ui->comboBoxSortColumn->currentIndex(), order);
    model->select();  // наполнить модель данными из таблицы, учитывая условия фильтрации и сортировки.
}

// Метод для вывода результатов на выборку (фильтрация):
void MainWindow::on_pushButtonFilter_clicked()
{
    QString filterString, columnName, comparisonSign, filterValue;

    switch (ui->comboBoxFilterColumn->currentIndex()) {
    case 0:
        columnName = "id";
        filterValue = ui->lineEditFilterValue->text();
        break;
    case 1:
        columnName = "last_name";
        filterValue = QString("'%1'").arg(ui->lineEditFilterValue->text());
        break;
    case 2:
        columnName = "first_name";
        filterValue = QString("'%1'").arg(ui->lineEditFilterValue->text());
        break;
    case 3:
        columnName = "occupation";
        filterValue = QString("'%1'").arg(ui->lineEditFilterValue->text());
        break;
    case 4:
        columnName = "year_of_admission";
        filterValue = ui->lineEditFilterValue->text();
        break;
    default:
        break;
    }

    switch (ui->comboBoxFilterCondition->currentIndex()) {
    case 0: comparisonSign = "=";  break;
    case 1: comparisonSign = "!="; break;
    case 2: comparisonSign = "<";  break;
    case 3: comparisonSign = "<="; break;
    case 4: comparisonSign = ">";  break;
    case 5: comparisonSign = ">="; break;
    default: break;
    }

    filterString = QString("%1%2%3").arg(columnName, comparisonSign, filterValue);
    qDebug() << "Фильтр:" << filterString;
    model->setFilter(filterString);
    model->select();  // наполнить модель данными из таблицы, учитывая условия фильтрации и сортировки.
}

// Методы для вывода результатов двух запросов на выборку (фильтрация):

// Запрос № 1:
void MainWindow::on_pushButtonYearOfAdmissionGreaterThan2010_clicked()
{
    model->setFilter("year_of_admission > 2010");
    model->select();  // наполнить модель данными из таблицы, учитывая условия фильтрации и сортировки.
}

// Запрос № 2:
void MainWindow::on_pushButtonYearOfAdmissionLessThan2011_clicked()
{
    model->setFilter("year_of_admission < 2011");
    model->select();  // наполнить модель данными из таблицы, учитывая условия фильтрации и сортировки.
}
