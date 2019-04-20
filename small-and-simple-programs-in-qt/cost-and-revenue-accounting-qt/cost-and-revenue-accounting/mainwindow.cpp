#include <QFileDialog>
#include <QMap>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "profit.h"
#include "expense.h"
#include "defaultdata.h"

// Конструктор главного окна:
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  // вызов конструктора базового класса.
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Установить фиксированный размер окна:
    this->setFixedSize(QSize(width(), height()));

    // Установка иконки для главного окна:
    setWindowIcon(QIcon(":/app/icon/Ruble-RUB-icon.png"));

    // Данные по умолчанию:
    DefaultData defaultData;

    // Настройка таблицы доходов:
    setupTable(
        ui->tableViewCosts,
        &tableModelCosts,
        "Расходы",
        &cbidCosts,
        defaultData.createDefaultCostsMap()
    );

    // Настройка таблицы доходов:
    setupTable(
        ui->tableViewIncome,
        &tableModelIncome,
        "Доходы",
        &cbidIncome,
        defaultData.createDefaultProfitsMap()
    );

    // Статусная строка:
    this->statusBarContainer = new QWidget();
    this->statusBarLayout = new QHBoxLayout();
    this->statusBarLabel = new QLabel();
    this->statusBarLayout->addWidget(this->statusBarLabel);
    this->statusBarLayout->setContentsMargins(0, 0, 0, 0);
    this->statusBarContainer->setLayout(this->statusBarLayout);
    ui->statusBar->addWidget(this->statusBarContainer);


    // Создание окна "О программе Учет расходов и доходов":
    formAbout = new FormAbout(this);

    // Сделать окно "О программе Учет расходов и доходов" модальным:
    formAbout->setWindowFlags(Qt::Dialog);
    formAbout->setWindowModality(Qt::WindowModal);
}

// Метод для настройки таблиц:
void MainWindow::setupTable(
    QTableView *tableView,  // виджет таблицы.
    TableModel **tableModel,  // модель данных таблицы.
    QString tableTitle,  // заголовок таблицы.
    ComboBoxItemDelegate **cbid,  // объект для выбора месяца.
    QMap<QString, QList<Base>> itemList  // данные для модели данных таблицы.
)
{
    // Создание экземпляра модели данных для таблицы:
    *tableModel = new TableModel(tableView, tableTitle);

    (*tableModel)->setItemList(itemList);

    // Установка модели данных для таблицы:
    tableView->setModel(*tableModel);

    // Выпадающий список для выбора названия месяца для таблицы:
    *cbid = new ComboBoxItemDelegate(tableView);
    tableView->setItemDelegateForRow(MONTH_ROW_INDEX, *cbid);

    // Объединить первые две ячейки (для заголовка таблицы):
    tableView->setSpan(0, 0, 1, (*tableModel)->columnCount());

    // Скрыть "родные" заголовки таблицы, т.к. у нас будет свой заголовок в первой строке:
    tableView->horizontalHeader()->hide();
    tableView->verticalHeader()->hide();

    // Настройка ширины столбцов:
    tableView->setColumnWidth(0, tableView->width() / 2 - 1);
    tableView->setColumnWidth(1, tableView->width() / 2 - 1);
}

// Деструктор главного окна:
MainWindow::~MainWindow()
{
    // Удаление модели данных для таблицы расходов:
    if (tableModelCosts)
        delete tableModelCosts;

    // Удаление выпадающего списка для выбора названия месяца в таблице расходов:
    if (cbidCosts)
        delete cbidCosts;

    // Удаление модели данных для таблицы доходов:
    if (tableModelIncome)
        delete tableModelIncome;

    // Удаление выпадающего списка для выбора названия месяца в таблице доходов:
    if (cbidIncome)
        delete cbidIncome;

    // Удаление окна о программе:
    if (formAbout)
        delete formAbout;

    delete ui;
}

// Выход из программы:
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();  // выход.
}

// Открыть файл:
void MainWindow::on_actionOpen_triggered()
{
    // Открыть диалоговое окно для выбора файла:
    fileName = QFileDialog::getOpenFileName(
        this,
        tr("Открыть файл"),
        QString(),
        tr("JSON-файлы (*.json)")
    );

    // Если файл не выбран:
    if (fileName.isEmpty())
        return;  // то выход.

    // Показываем в статусной строке имя выбранного файла:
    this->statusBarLabel->setText(fileName);

    // Открываем JSON-файл:
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);

    // Чтение:
    QJsonDocument doc = QJsonDocument().fromJson(jsonFile.readAll());

    QJsonObject jsonObj = doc.object();

    // Обновляем модель данных таблицы расходов:
    QJsonObject jsonObjCosts = jsonObj.value("расходы").toObject();
    tableModelCosts->setDataFromJsonObject(jsonObjCosts);

    // Обновляем модель данных таблицы доходов:
    QJsonObject jsonObjIncome = jsonObj.value("доходы").toObject();
    tableModelIncome->setDataFromJsonObject(jsonObjIncome);
}

// Сохранить файл:
void MainWindow::on_actionSave_triggered()
{
    if (fileName.isEmpty()) {
        // Открыть диалоговое окно для выбора файла:
        fileName = QFileDialog::getSaveFileName(
            this,
            tr("Сохранить файл"),
            QString(),
            tr("JSON-файлы (*.json)")
        );
    }

    // Если файл не выбран, то остановиться:
    if (fileName.isEmpty()) return;

    // Показываем в статусной строке имя выбранного файла:
    this->statusBarLabel->setText(fileName);

    // Конвертируем в JSON данные таблицы расходов:
    QJsonObject jsonObjCosts = tableModelCosts->getDataAsJsonObject();

    // Конвертируем в JSON данные таблицы доходов:
    QJsonObject jsonObjIncome = tableModelIncome->getDataAsJsonObject();

    // Создаем один общий JSON-документ:

    QJsonObject jsonObj;

    jsonObj.insert("расходы", jsonObjCosts);
    jsonObj.insert("доходы", jsonObjIncome);

    QJsonDocument doc(jsonObj);

    // Сохраняем всё в файл:

    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);

    // Запись:
    jsonFile.write(doc.toJson(QJsonDocument::Indented));
}

// Обработчик события выбора пункта главного меню Справка → О программе Учет расходов и доходов…:
void MainWindow::on_actionAbout_triggered()
{
    // Показать окно:
    formAbout->show();
}
