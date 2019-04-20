#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QDir>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "people.h"
#include "level.h"
#include "temperature.h"
#include "ground.h"

#include "survival.h"

// Конструктор:
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Установить фиксированный размер окна:
    this->setFixedSize(QSize(width(), height()));

    // Установка иконки для окна:
    setWindowIcon(QIcon(":/MyImgRes/people-icon-256.png"));


    // Связываем элементы ввода и их метки (которые слева от них):

    ui->labelPeople->setBuddy(ui->lineEditPeople);
    ui->labelNumberOfPeople->setBuddy(ui->spinBoxNumberOfPeople);
    ui->labelLevel->setBuddy(ui->comboBoxLevel);

    ui->labelTemperature->setBuddy(ui->comboBoxTemperature);
    ui->labelTerrainConditions->setBuddy(ui->comboBoxTerrainConditions);
    ui->labelFoodCrop->setBuddy(ui->comboBoxFoodCrop);


    // Создание модели данных для выпадающего списка с
    // уровнями развития:
    QStringList levelItems;
    for (int i = 0; i < LEVEL_TYPE_COUNT; ++i)
    {
        switch (i) {
        case MINIMAL: levelItems << tr("Минимальный"); break;
        case EASY: levelItems << tr("Лёгкий"); break;
        case MIDDLE: levelItems << tr("Средний"); break;
        case HIGH: levelItems << tr("Высокий"); break;
        }
    }
    levelModel = new QStringListModel(levelItems, this);
    ui->comboBoxLevel->setModel(levelModel);


    // Создание модели данных для выпадающего списка с
    // температурными режимами:
    QStringList temperatureItems;
    temperatureItems << tr("Меньше или равно -40")
                     << tr("От -39 до -20")
                     << tr("От -19 до 0")
                     << tr("От +1 до +19")
                     << tr("От +20 до +30")
                     << tr("Больше или равно +40");
    temperatureModel = new QStringListModel(temperatureItems, this);
    ui->comboBoxTemperature->setModel(temperatureModel);

    temperatureItemsValues[0][0] =      temperatureItemsValues[0][1] = -40;
    temperatureItemsValues[1][0] = -39; temperatureItemsValues[1][1] = -20;
    temperatureItemsValues[2][0] = -19; temperatureItemsValues[2][1] =   0;
    temperatureItemsValues[3][0] =  +1; temperatureItemsValues[3][1] = +19;
    temperatureItemsValues[4][0] = +20; temperatureItemsValues[4][1] = +30;
    temperatureItemsValues[5][0] =      temperatureItemsValues[5][1] = +40;


    // Создание модели данных для выпадающего списка с
    // условиями местности:
    QStringList groundItems;
    for (int i = 0; i < GROUND_TYPE_COUNT; ++i)
    {
        switch (i) {
        case DESERT: groundItems << tr("Пустыня"); break;
        case SWAMP: groundItems << tr("Болото"); break;
        case MOUNTAINS: groundItems << tr("Горы"); break;
        case FOREST: groundItems << tr("Лес"); break;
        case PLAIN: groundItems << tr("Равнина"); break;
        }
    }
    groundModel = new QStringListModel(groundItems, this);
    ui->comboBoxTerrainConditions->setModel(groundModel);

    // Создание окна для отображения результатов:
    formResult = new FormResult(this);

    // Сделать окно с результатами модальным:
    formResult->setWindowFlags(Qt::Dialog);
    formResult->setWindowModality(Qt::WindowModal);

    // Создание окна "О программе Выживаемость народа":
    formAbout = new FormAbout(this);

    // Сделать окно "О программе Выживаемость народа" модальным:
    formAbout->setWindowFlags(Qt::Dialog);
    formAbout->setWindowModality(Qt::WindowModal);
}

// Деструктор:
MainWindow::~MainWindow()
{
    // Удаление моделей данных для выпадающих списков:
    delete levelModel;
    delete temperatureModel;
    delete groundModel;
    delete vegetationModel;

    // Удаление дополнительных окон:
    delete formResult;
    delete formAbout;

    // Удаление временного файла являющегося справкой
    // по уровням развития:
    if (filePathLevelsDescription != nullptr)
    {
        if (QFile(*filePathLevelsDescription).remove())
        {
            qDebug() << "Файл" << *filePathLevelsDescription << "удален";
        }
        else
        {
            qDebug() << "Проблемы при удалении файла" << *filePathLevelsDescription;
        }
        delete filePathLevelsDescription;
    }

    delete ui;
}

// Обработчик события нажатия на кнопку "Рассчитать…"
void MainWindow::on_pushButtonCalculate_clicked()
{
    // Если пользователь не ввёл название народа:
    if (ui->lineEditPeople->text().trimmed().isEmpty())
    {
        // Показать ошибку:

        QMessageBox messageBox;
        messageBox.critical(this, "Ошибка!", "Введите наименование народа.");
        messageBox.setFixedSize(500, 200);

        return;  // и выйти из процедуры.
    }

    // Введенное количество людей:
    People p(ui->spinBoxNumberOfPeople->value());

    // Выбранный уровень развития:
    Level l(static_cast<LevelType>(ui->comboBoxLevel->currentIndex()));

    // Выбранный температурный режим:
    int temperatureRangeIndex = ui->comboBoxTemperature->currentIndex();
    qDebug() << "Выбранная температура ="
             << temperatureItemsValues[temperatureRangeIndex][0]
             << temperatureItemsValues[temperatureRangeIndex][1];
    Temperature t(temperatureItemsValues[temperatureRangeIndex][0],
                  temperatureItemsValues[temperatureRangeIndex][1]);

    // Выбранные условия местности:
    Ground g(static_cast<GroundType>(ui->comboBoxTerrainConditions->currentIndex()));

    // Выбранная растительность:
    Vegetation v(&g, vegetationItemsValue[ui->comboBoxFoodCrop->currentIndex()]);

    // Вычислитель:
    Survival s;

    // Добавление параметров в вычислитель:
    s.addParameter(&p);
    s.addParameter(&l);
    s.addParameter(&t);
    s.addParameter(&g);
    s.addParameter(&v);

    // Отображение результатов:

    qDebug() << "Баллы =" << s.getTotalScore();
    if (s.willSurvive())
    {
        qDebug() << "Народ" << ui->lineEditPeople->text() << "выжил :)";
        formResult->setSurvived(true);
    }
    else
    {
        qDebug() << "Народ" << ui->lineEditPeople->text() << "умер :(";
        formResult->setSurvived(false);
    }

    // Установить наименование народа в окне с результатами:
    formResult->setPeopleName(ui->lineEditPeople->text());

    formResult->show();  // показать окно с результатами.
}

// Обработчик события смены условий местности:
void MainWindow::on_comboBoxTerrainConditions_currentIndexChanged(int index)
{
    qDebug() << "Выбраны условия местности №" << index;

    // Список растительности для выбранных условий местности:
    QStringList vegetationItems;

    // Заполняем список растительности в зависимости от выбранных условий местности:
    switch (index) {
    case DESERT:
        vegetationItems << tr("Нет растительности");
        vegetationItemsValue[0] =
        vegetationItemsValue[1] =
        vegetationItemsValue[2] = NONE;
        break;
    case SWAMP:
        vegetationItems << tr("Клюква") << tr("Морошка");
        vegetationItemsValue[0] = CRANBERRY;
        vegetationItemsValue[1] = CLOUDBERRY;
        vegetationItemsValue[2] = NONE;
        break;
    case MOUNTAINS:
        vegetationItems << tr("Продукты питания") << tr("Мак") << tr("Трава и кусты");
        vegetationItemsValue[0] = FOOD_STUFFS;
        vegetationItemsValue[1] = POPPY;
        vegetationItemsValue[2] = GRASS_AND_BUSHES;
        break;
    case FOREST:
        vegetationItems << tr("Ягоды") << tr("Грибы") << tr("Продукты питания");
        vegetationItemsValue[0] = BERRIES;
        vegetationItemsValue[1] = MUSHROOMS;
        vegetationItemsValue[2] = FOOD_STUFFS;
        break;
    case PLAIN:
        vegetationItems << tr("Пшеница") << tr("Картошка") << tr("Корнеплоды");
        vegetationItemsValue[0] = WHEAT;
        vegetationItemsValue[1] = POTATO;
        vegetationItemsValue[2] = ROOT;
        break;
    }

    // Удалить модель данных для выпадающего списка с растительностью:
    if (vegetationModel != nullptr)
        delete vegetationModel;

    // Создание для выпадающего списка с растительностью
    // новой модели данных:
    vegetationModel = new QStringListModel(vegetationItems, this);

    // Установить для выпадающего списка с растительностью
    // новую модель данных:
    ui->comboBoxFoodCrop->setModel(vegetationModel);
}

// Выход из программы:
void MainWindow::on_actionExit_triggered()
{
    // Закрыть приложение:
    QApplication::quit();
}

// Метод для открытия файла из ресурсов приложения
// (этот метод нужен для того чтобы скопировать файл из
// ресурсов программы во временную папку, а потом уже из
// временной папки открыть его внешней программой):
void MainWindow::openFileFromRes(QString filePathInRes, QString* output_path)
{
    // Путь к папке с программой:
    qDebug() << "applicationDirPath =" << QCoreApplication::applicationDirPath();

    // Путь к временной папке:
    qDebug() << "tempPath =" << QDir::tempPath();

    // Файл и его путь:
    QFile input_file(filePathInRes);

    // Открытие файла:
    if (!input_file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Невозможно открыть файл для чтения";
        return;
    }

    // Чтение содежимого файла:
    QTextStream in(&input_file);
    QString myText = in.readAll();

    // Закрытие файла:
    input_file.close();

    // Путь к временному файлу во временной папке:
    *output_path = QDir::temp().filePath(QFileInfo(input_file).fileName());

    // Выходной временный файл:
    QFile output_file(*output_path);

    // Открытие временного файла:
    if (!output_file.open(QIODevice::WriteOnly))
    {
        // Закрытие временного файла:
        output_file.close();
        return;
    } else {
        // Копирование входного файла во временный файл:
        QTextStream out(&output_file);
        out << myText;

        // Закрытие временного файла:
        output_file.close();
    }

    // Запуск на открытие временного в операционной системе
    // (для *.html файлов откроётся браузер):
    QDesktopServices::openUrl(QUrl("file:///" + *output_path));
}

// Обработчик события выбора пункта главного меню Справка → Описание уровней:
void MainWindow::on_actionLevelsDescription_triggered()
{
    openFileFromRes(":/MyHtmlRes/levels_description.html", filePathLevelsDescription);
}

// Обработчик события изменения количества людей:
void MainWindow::on_spinBoxNumberOfPeople_valueChanged(int arg1)
{
    // В зависимости от количества населения сразу устанавливаем
    // уровень развития:

    if (arg1 <= 1000)
        ui->comboBoxLevel->setCurrentIndex(MINIMAL);
    else if (arg1 <= 10000)
        ui->comboBoxLevel->setCurrentIndex(EASY);
    else if (arg1 <= 50000)
        ui->comboBoxLevel->setCurrentIndex(MIDDLE);
    else
        ui->comboBoxLevel->setCurrentIndex(HIGH);
}

// Обработчик события выбора пункта главного меню Справка → О программе Выживаемость народа…:
void MainWindow::on_actionAbout_triggered()
{
    // Показать окно:
    formAbout->show();
}

// Обработчик события изменения названия народа:
void MainWindow::on_lineEditPeople_textChanged(const QString &arg1)
{
    if (arg1.trimmed().isEmpty())
    {
        ui->pushButtonCalculate->setEnabled(false);
    }
    else
    {
        ui->pushButtonCalculate->setEnabled(true);
    }
}
