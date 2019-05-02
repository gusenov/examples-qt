#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "about.h"
#include "appmodel.h"
#include "print.h"

// Пространство имён Ui:
namespace Ui {
// Предварительное объявление класса MainWindow:
class MainWindow;
}

// Класс представляющий собой главное окно программы:
class MainWindow : public QMainWindow  // унаследован от Qt-класса QMainWindow.
{

    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:

    // Явный конструктор:
    explicit MainWindow(QWidget *parent = nullptr);

    // Деструктор:
    ~MainWindow();

// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Обработчик события выбора пункта главного меню Файл → Выход:
    void on_actionExit_triggered();

    // Обработчик события выбора пункта главного меню Справка → О программе Сборка ПК…:
    void on_actionAbout_triggered();


    // Обработчик события смены видеокарты:
    void on_comboBoxVideoCardChoice_currentIndexChanged(int index);

    // Обработчик события смены материнской платы:
    void on_comboBoxMotherboardChoice_currentIndexChanged(int index);

    // Обработчик события смены жесткого диска:
    void on_comboBoxHDDChoice_currentIndexChanged(int index);
    void on_comboBoxHDDChoice_2_currentIndexChanged(int index);

    // Обработчик события смены процессора:
    void on_comboBoxCPUChoice_currentIndexChanged(int index);

    // Обработчик события смены блока питания:
    void on_comboBoxPowerSupplyChoice_currentIndexChanged(int index);

    // Обработчик события смены оперативной памяти:
    void on_comboBoxRAMChoice_currentIndexChanged(int index);


    // Обработчик события смены количества видеокарт:
    void on_spinBoxVideoCardQuantityValue_valueChanged(int arg1);

    // Обработчик события смены количества жестких дисков:
    void on_spinBoxHDDQuantityValue_valueChanged(int arg1);
    void on_spinBoxHDDQuantityValue_2_valueChanged(int arg1);

    // Обработчик события смены количества оперативной памяти:
    void on_spinBoxRAMQuantityValue_valueChanged(int arg1);


    // Обработчик нажатия на кнопку
    // "Собрать готовое решение персонального компьютера и вывести цену":
    void on_pushButtonBuild_clicked();

    // Обработчик события выбора пункта главного меню Справка → Информация о проекте:
    void on_actionInfo_triggered();

// Приватные члены класса:

private:

    // Настройка моделей данных для выпадающих списков:
    void setupModels();

    // Метод для получения итоговой цены:
    int getTotalPrice();

    // Метод для проверки совместимости выбранных устройств:
    void checkCompatibility();


    // Указатель на форму:
    Ui::MainWindow *ui;
    // Через этот указатель можно получить доступ к виджетам расположенным на форме.


    // Окно о "О программе Сборка ПК":
    About *about = nullptr;

    // Окно печати:
    Print *print = nullptr;


    // Модель данных программы:
    AppModel *appDataModel = nullptr;


    // Модель данных для выпадающего списка для выбора видеокарты:
    QStringListModel *modelVideoCard = nullptr;

    // Модель данных для выпадающего списка для выбора материнской платы:
    QStringListModel *modelMotherboard = nullptr;

    // Модель данных для выпадающего списка для выбора жесткого диска:
    QStringListModel *modelHDD = nullptr;

    // Модель данных для выпадающего списка для выбора процессора:
    QStringListModel *modelCPU = nullptr;

    // Модель данных для выпадающего списка для выбора блока питания:
    QStringListModel *modelPowerSupply = nullptr;

    // Модель данных для выпадающего списка для выбора модуля оперативной памяти:
    QStringListModel *modelRAM = nullptr;


    int priceVideoCard = 0;  // цена по видеокартам.
    int priceMotherboard = 0;  // цена материнской платы.
    int priceHDD = 0, priceHDD2 = 0;  // цена по жестким дискам.
    int priceCPU = 0;  // цена процессора.
    int pricePowerSupply = 0;  // цена блока питания.
    int priceRAM = 0;  // цена по оперативной памяти.


    // Путь к файлу справки с информацией о проекте:
    QString* filePathProjectInfo = new QString();

    // Метод для открытия файла из ресурсов приложения:
    void openFileFromRes(QString filePathInRes, QString* output_path);


    // Переменная-флаг служащая для разовой инициализации приложения:
    bool isInitialized;

};

#endif // MAINWINDOW_H
