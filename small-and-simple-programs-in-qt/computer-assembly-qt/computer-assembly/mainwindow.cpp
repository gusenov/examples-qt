#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QMessageBox>

// Конструктор:
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  // вызов родительского конструктора.
    ui(new Ui::MainWindow)
{
    // Приложение пока ещё не инциализировано:
    isInitialized = false;

    ui->setupUi(this);

    // Установить фиксированный размер окна:
    this->setFixedSize(QSize(width(), height()));

    // Установка иконки для окна программы:
    setWindowIcon(QIcon("://Home-Server-icon.png"));

    // Создание экземпляра окна в котором отображается информация о программе:
    about = new About(this);

    // Делаем окно О программе… модальным:
    about->setWindowFlags(Qt::Dialog);
    about->setWindowModality(Qt::WindowModal);

    // Окно для печати:
    print = new Print(this);

    // Делаем окно для печати модальным:
    print->setWindowFlags(Qt::Dialog);
    print->setWindowModality(Qt::WindowModal);

    // Настройка моделей для выпадающих списков:
    setupModels();

    isInitialized = true;  // приложение инициализировано.

    checkCompatibility();  // проверка совместимости выбранных компонентов.

    connect(ui->widgetSelectVideoCard, SIGNAL(checkCompatibilitySignal()), this, SLOT(checkCompatibility()));
    connect(ui->widgetSelectHDD, SIGNAL(checkCompatibilitySignal()), this, SLOT(checkCompatibility()));
}

// Настройка моделей данных для выпадающих списков:
void MainWindow::setupModels()
{
    // Создаем модель данных приложения:
    appDataModel = new AppModel("://data.csv");


    // Создаем и устанавливаем модели данных для выпадающих списков:

    modelVideoCard = new QStringListModel(appDataModel->getVideoCardStringList());
    ui->widgetSelectVideoCard->config(modelVideoCard, appDataModel, DeviceType::VideoCard);

    modelMotherboard = new QStringListModel(appDataModel->getMotherboardStringList());
    ui->comboBoxMotherboardChoice->setModel(modelMotherboard);

    modelHDD = new QStringListModel(appDataModel->getHddStringList());
    ui->widgetSelectHDD->config(modelHDD, appDataModel, DeviceType::HDD);

    modelCPU = new QStringListModel(appDataModel->getCpuStringList());
    ui->comboBoxCPUChoice->setModel(modelCPU);

    modelPowerSupply = new QStringListModel(appDataModel->getPowerSupplyStringList());
    ui->comboBoxPowerSupplyChoice->setModel(modelPowerSupply);

    modelRAM = new QStringListModel(appDataModel->getRamStringList());
    ui->comboBoxRAMChoice->setModel(modelRAM);
}

// Деструктор:
MainWindow::~MainWindow()
{
    delete ui;

    // Удаление экземпляра окна в котором отображается информация о программе:
    if (about)            delete about;

    // Удаление окна печати:
    if (print)            delete print;

    // Удаление модели данных программы:
    if (appDataModel)     delete appDataModel;

    // Удаление моделей данных выпадающих списков:
    if (modelVideoCard)   delete modelVideoCard;
    if (modelMotherboard) delete modelMotherboard;
    if (modelHDD)         delete modelHDD;
    if (modelCPU)         delete modelCPU;
    if (modelPowerSupply) delete modelPowerSupply;
    if (modelRAM)         delete modelRAM;


    // Удаление временного файла в котором хранится информация о проекте:
    if (filePathProjectInfo != nullptr)
    {
        if (QFile(*filePathProjectInfo).remove())
        {
            qDebug() << "Файл" << *filePathProjectInfo << "удален";
        }
        else
        {
            qDebug() << "Проблемы при удалении файла" << *filePathProjectInfo;
        }
        delete filePathProjectInfo;
    }
}

// Выход из программы:
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();  // выход.
}

// Обработчик события выбора пункта главного меню Справка → О программе Сборка ПК…:
void MainWindow::on_actionAbout_triggered()
{
    about->show();  // показать окно.
}

// Обработчик события смены материнской платы:
void MainWindow::on_comboBoxMotherboardChoice_currentIndexChanged(int index)
{
    // Показать характеристики выбранного компонента:
    ui->plainTextEditMotherboardSpecifications->setPlainText(
        appDataModel->getSpecificationsByIndex(DeviceType::Motherboard, index)
    );

    // Пересчитать цену в завимисости от количества:
    ui->labelMotherboardPriceValue->setText(
        QString::number(appDataModel->getPriceByIndex(DeviceType::Motherboard, index)) + " ₽"
    );

    // Проверить совместимость:
    checkCompatibility();
}

// Обработчик события смены процессора:
void MainWindow::on_comboBoxCPUChoice_currentIndexChanged(int index)
{
    // Показать характеристики выбранного компонента:
    ui->plainTextEditCPUSpecifications->setPlainText(
        appDataModel->getSpecificationsByIndex(DeviceType::CPU, index)
    );

    // Пересчитать цену в завимисости от количества:
    priceCPU = appDataModel->getPriceByIndex(DeviceType::CPU, index);
    ui->labelCPUPriceValue->setText(
        QString::number(priceCPU) + " ₽"
    );

    // Проверить совместимость:
    checkCompatibility();
}

// Обработчик события смены блока питания:
void MainWindow::on_comboBoxPowerSupplyChoice_currentIndexChanged(int index)
{
    // Показать характеристики выбранного компонента:
    ui->plainTextEditPowerSupplySpecifications->setPlainText(
        appDataModel->getSpecificationsByIndex(DeviceType::PowerSupply, index)
    );

    // Пересчитать цену в завимисости от количества:
    pricePowerSupply = appDataModel->getPriceByIndex(DeviceType::PowerSupply, index);
    ui->labelPowerSupplyPriceValue->setText(
        QString::number(pricePowerSupply) + " ₽"
    );

    // Проверить совместимость:
    checkCompatibility();
}

// Обработчик события смены оперативной памяти:
void MainWindow::on_comboBoxRAMChoice_currentIndexChanged(int index)
{
    // Показать характеристики выбранного компонента:
    ui->plainTextEditRAMSpecifications->setPlainText(
        appDataModel->getSpecificationsByIndex(DeviceType::RAM, index)
    );

    // Пересчитать цену в завимисости от количества:
    priceRAM = ui->spinBoxRAMQuantityValue->value();
    on_spinBoxRAMQuantityValue_valueChanged(priceRAM);

    // Проверить совместимость:
    checkCompatibility();
}

// Обработчик события смены количества оперативной памяти:
void MainWindow::on_spinBoxRAMQuantityValue_valueChanged(int arg1)
{
    int currentRAMIndex = ui->comboBoxRAMChoice->currentIndex();
    if (currentRAMIndex == -1)
        return;

    // Пересчитать цену в завимисости от количества:
    priceRAM = appDataModel->getPriceByIndex(DeviceType::RAM, currentRAMIndex) * arg1;
    ui->labelRAMPriceValue->setText(
        QString::number(priceRAM) + " ₽"
    );
}


// Метод для получения итоговой цены:
int MainWindow::getTotalPrice()
{
    return priceVideoCard
         + priceMotherboard
         + ui->widgetSelectHDD->getPrice()
         + priceCPU
         + pricePowerSupply
         + priceRAM;
}

// Обработчик нажатия на кнопку
// "Собрать готовое решение персонального компьютера и вывести цену":
void MainWindow::on_pushButtonBuild_clicked()
{
    // Форматируем текст по шаблону:

    QString result = QString("%1"
                             "%2 = %3\n%4\n\n"
                             "%5"
                             "%6 = %7\n%8\n\n"
                             "%9 = %10\n%11\n\n"
                             "%12 x%13 = %14\n%15\n\n\n"
                             "ИТОГО: %16 ₽").arg(
        ui->widgetSelectVideoCard->getText(),

        ui->comboBoxMotherboardChoice->currentText(),
        ui->labelMotherboardPriceValue->text(),
        ui->plainTextEditMotherboardSpecifications->toPlainText(),

        ui->widgetSelectHDD->getText()
    ).arg(
        ui->comboBoxCPUChoice->currentText(),

        ui->labelCPUPriceValue->text(),
        ui->plainTextEditCPUSpecifications->toPlainText()
    ).arg(
        ui->comboBoxPowerSupplyChoice->currentText(),
        ui->labelPowerSupplyPriceValue->text(),
        ui->plainTextEditPowerSupplySpecifications->toPlainText(),

        ui->comboBoxRAMChoice->currentText(),
        QString::number(ui->spinBoxRAMQuantityValue->value()),
        ui->labelRAMPriceValue->text(),
        ui->plainTextEditRAMSpecifications->toPlainText(),

        QString::number(getTotalPrice())
    );

    print->setResultText(result);
    print->show();
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

// Обработчик события выбора пункта главного меню Справка → Информация о проекте:
void MainWindow::on_actionInfo_triggered()
{
    openFileFromRes(":/info.html", filePathProjectInfo);
}

// Метод для проверки совместимости выбранных устройств:
void MainWindow::checkCompatibility()
{
    if (!isInitialized)
        return;

    // Получаем текстовую информацию о результатах совместимости:
    QString compatibilityInfo = appDataModel->getCompatibilityInfo(
        ui->widgetSelectVideoCard->getDeviceIndexes(),
        ui->comboBoxMotherboardChoice->currentIndex(),
        ui->widgetSelectHDD->getDeviceIndexes(),
        ui->comboBoxCPUChoice->currentIndex(),
        ui->comboBoxPowerSupplyChoice->currentIndex(),
        ui->comboBoxRAMChoice->currentIndex()
    );

    // Отображаем текстовую информацию о результатах совместимости:
    ui->plainTextEditCompatibilityInfo->setPlainText(compatibilityInfo);

    // Палитра цветов:
    QPalette p = ui->plainTextEditCompatibilityInfo->palette();

    // Если есть какая-то несовместимость:
    if (compatibilityInfo.contains("не совместим")) {
        p.setColor(QPalette::Base, Qt::white);  // делаем текст красным.
        p.setColor(QPalette::Text, Qt::red);

        ui->pushButtonBuild->setEnabled(false);  // выключить кнопку сборки.

    // Иначе:
    } else {
        p.setColor(QPalette::Base, Qt::white);
        p.setColor(QPalette::Text, Qt::black);

        ui->pushButtonBuild->setEnabled(true);  // включить кнопку сборки.
    }

    ui->plainTextEditCompatibilityInfo->setPalette(p);
}
