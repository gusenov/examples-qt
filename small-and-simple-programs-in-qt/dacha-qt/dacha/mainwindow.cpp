#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtDebug>
#include <QJsonDocument>
#include <QDialog>
#include <QShowEvent>

// Конструктор:
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Установить фиксированный размер окна:
    this->setFixedSize(QSize(width(), height()));

    // Установка иконки:
    setWindowIcon(QIcon(":/icon/tea-plant-leaf-icon.png"));

    // Создание объекта для работы с JSON-файлом хранящемся в ресурсах:
    dachaData = new DachaData(":/data/data.json");
    dachaData->parseJson();  // парсинг JSON-файла.

    // Создание модели данных для выпадающего списка в котором
    // выбирается тип растения:
    modelType = new QStringListModel(dachaData->getTypeItems(), this);

    // Приложение пока ещё не инциализировано:
    isInitialized = false;
}

// Переопределение метода showEvent для того чтобы
// обработать событие, когда форма показывается пользователю:
void MainWindow::showEvent(QShowEvent *event)
{
    // Вызов метода базового класса:
    QMainWindow::showEvent(event);

    if (event->spontaneous())
        return;

    if (isInitialized)
        return;

    // Установка модели данных для выпадающего списка с типом растений:
    ui->comboBoxType->setModel(modelType);

    // Приложение инциализировано после показа формы:
    isInitialized = true;
}

// Деструктор:
MainWindow::~MainWindow()
{
    // Удаление объекта для чтения JSON-файла с данными о растениях:
    delete dachaData;

    // Удаление моделей данных для выпадающих списков
    // в которых выбираются тип растения и какое-нибудь растение
    // принадлежащее этому типу:
    if (modelType) delete modelType;
    if (modelPlant) delete modelPlant;

    delete ui;
}

// Выход из программы:
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();  // выйти из программы.
}

// Обработчик события смены выбора типа растения:
void MainWindow::on_comboBoxType_currentTextChanged(const QString &arg1)
{
    // Удаляем модель данных для выпадающего списка с растениями:
    if (modelPlant) delete modelPlant;

    // Создаём новую модель данных для выпадающего списка с растениями:
    modelPlant = new QStringListModel(dachaData->getPlantItems(arg1), this);

    // Устанавливаем созданную модель данных выпадающему списку с растениями:
    ui->comboBoxPlant->setModel(modelPlant);
}

// Обработчик события смены растения принадлежащего выбранному типу:
void MainWindow::on_comboBoxPlant_currentTextChanged(const QString &plantName)
{
    // Тип выбранного растения:
    QString type = ui->comboBoxType->currentText();

    // Словарь деталей по выбранному растению:
    QVariantMap plantMap = dachaData->getPlantMap(type, plantName);

    ui->labelSeedsValue->setText("");  // очистить поле "Посадка семян".
    ui->labelGroundValue->setText("");  // очистить поле "Высадка в грунт".
    ui->labelTermsValue->setText("");  // очистить поле "Сроки созревания".

    // Получить "Сроки" для растения:
    ui->groupBoxTime->setTitle("Сроки");
    QVariantMap timeMap = plantMap[ui->groupBoxTime->title()].toMap();

    // Если "Сроки" в файле есть, то:
    if (!timeMap.isEmpty())
    {
        // Устанавливаем соответствующие данные:

        ui->labelSeeds->setText("Посадка семян");
        ui->labelSeedsValue->setText(timeMap[ui->labelSeeds->text()].toString());

        ui->labelGround->setText("Высадка в грунт");
        ui->labelGroundValue->setText(timeMap[ui->labelGround->text()].toString());

        ui->labelTermsValue->setText(timeMap[ui->labelTerms->text()].toString());
    }

    // Иначе, если ключ "Сроки" отсутствует, то:
    else
    {
        // Если нет ключа "Сроки", тогда смотрим ключ "Сроки посадки":

        ui->groupBoxTime->setTitle("Сроки посадки");
        QVariantMap timeMap = plantMap[ui->groupBoxTime->title()].toMap();

        // Меняем заголовоки и устанавливаем соответствующие данные:

        ui->labelSeeds->setText("Осень");
        ui->labelSeedsValue->setText(timeMap[ui->labelSeeds->text()].toString());

        ui->labelGround->setText("Весна");
        ui->labelGroundValue->setText(timeMap[ui->labelGround->text()].toString());
    }

    // Если нет данных для какого-то из полей
    // "Посадка семян", "Высадка в грунт" или "Сроки созревания",
    // то скрываем эти поля:
    ui->labelSeeds->setVisible(!ui->labelSeedsValue->text().isEmpty());
    ui->labelGround->setVisible(!ui->labelGroundValue->text().isEmpty());
    ui->labelTerms->setVisible(!ui->labelTermsValue->text().isEmpty());


    // Получаем список лучших сортов:
    QStringList topList = plantMap[ui->groupBoxTop->title()].toStringList();

    // Очищаем таблицу лучших сортов от предыдущих данных:
    ui->listWidgetTop->clear();

    // Добавляем список лучших сортов в таблицу:
    ui->listWidgetTop->addItems(topList);


    // Получаем данные о соседстве:
    QVariantMap neighborhoodMap = plantMap[ui->groupBoxNeighborhood->title()].toMap();

    // Получаем данные о соседстве "В теплице":
    ui->groupBoxGreen->setTitle("В теплице");
    QVariantMap greenMap = neighborhoodMap[ui->groupBoxGreen->title()].toMap();

    // Получаем данные о соседстве "В открытом грунте":
    QVariantMap openMap = neighborhoodMap[ui->groupBoxOpen->title()].toMap();


    ui->groupBoxGreen->setVisible(true);
    if (greenMap.isEmpty())  // если нет данных о соседстве "В теплице":
    {
        if (openMap.isEmpty())  // если нет данных о соседстве "В открытом грунте":
        {
            // Убираем заголовок для группы элементов под названием "В теплице":
            ui->groupBoxGreen->setTitle("");

            // Вместо данных о соседстве "В теплице"
            // будем сразу показывать "Благоприятное" или "Неблагоприятное":
            greenMap = neighborhoodMap;
        }
        else
        {
            // Скрываем группу элементов под названием "В теплице":
            ui->groupBoxGreen->setVisible(false);
        }
    }

    // Если группа элементов под названием "В теплице" видна:
    if (ui->groupBoxGreen->isVisible())
    {
        // Получаем данные о благоприятном соседстве:
        QStringList greenGoodList = greenMap[ui->groupBoxGreenGood->title()].toStringList();

        // Очищаем таблицу от предыдущих данных:
        ui->listWidgetGreenGood->clear();

        // Добавляем список в таблицу:
        ui->listWidgetGreenGood->addItems(greenGoodList);


        // Получаем данные о неблагоприятном соседстве:
        QStringList greenBadList = greenMap[ui->groupBoxGreenBad->title()].toStringList();

        // Очищаем таблицу от предыдущих данных:
        ui->listWidgetGreenBad->clear();

        // Добавляем список в таблицу:
        ui->listWidgetGreenBad->addItems(greenBadList);
    }


    if (openMap.isEmpty())  // если нет данных о соседстве "В открытом грунте":
    {
        // Скрываем группу элементов под названием "В открытом грунте":
        ui->groupBoxOpen->hide();
    }

    else  // иначе:
    {
        // Показываем группу элементов под названием "В открытом грунте":
        ui->groupBoxOpen->show();

        // Получаем данные о благоприятном соседстве:
        QStringList openGoodList = openMap[ui->groupBoxOpenGood->title()].toStringList();

        // Очищаем таблицу от предыдущих данных:
        ui->listWidgetOpenGood->clear();

        // Добавляем список в таблицу:
        ui->listWidgetOpenGood->addItems(openGoodList);


        // Получаем данные о неблагоприятном соседстве:
        QStringList openBadList = openMap[ui->groupBoxOpenBad->title()].toStringList();

        // Очищаем таблицу от предыдущих данных:
        ui->listWidgetOpenBad->clear();

        // Добавляем список в таблицу:
        ui->listWidgetOpenBad->addItems(openBadList);
    }
}
