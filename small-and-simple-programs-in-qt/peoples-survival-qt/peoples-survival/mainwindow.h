#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QFile>

#include "formresult.h"
#include "formabout.h"

#include "vegetation.h"

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
    explicit MainWindow(QWidget* parent = nullptr);

    // Деструктор:
    ~MainWindow();

// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Обработчик события нажатия на кнопку "Рассчитать…"
    void on_pushButtonCalculate_clicked();

    // Обработчик события смены условий местности:
    void on_comboBoxTerrainConditions_currentIndexChanged(int index);

    // Обработчик события выбора пункта главного меню Файл → Выход:
    void on_actionExit_triggered();

    // Обработчик события выбора пункта главного меню Справка → Описание уровней:
    void on_actionLevelsDescription_triggered();

    // Обработчик события изменения количества людей:
    void on_spinBoxNumberOfPeople_valueChanged(int arg1);

    // Обработчик события выбора пункта главного меню Справка → О программе Выживаемость народа…:
    void on_actionAbout_triggered();

    // Обработчик события изменения названия народа:
    void on_lineEditPeople_textChanged(const QString &arg1);

// Приватные члены класса:
private:

    // Указатель на форму:
    Ui::MainWindow* ui;
    // Через этот указатель можно получить доступ к виджетам расположенным на форме.

    // Окно с результатами:
    FormResult* formResult;

    // Окно "О программе Выживаемость народа":
    FormAbout* formAbout;

    // Модель данных для выпадающего списка с уровнями развития:
    QStringListModel* levelModel = nullptr;

    // Модель данных для выпадающего списка с температурами:
    QStringListModel* temperatureModel = nullptr;

    // Модель данных для выпадающего списка с условиями местности:
    QStringListModel* groundModel = nullptr;

    // Модель данных для выпадающего списка с растительностью:
    QStringListModel* vegetationModel = nullptr;

    // Массив из трех видов растительности:
    VegetationType vegetationItemsValue[3];

    // Двумерных массив температур
    // (6 строк, в каждой мин. и мак. температура):
    float temperatureItemsValues[6][2];

    // Путь к файлу справки с описанием уровней развития:
    QString* filePathLevelsDescription = new QString();

    // Метод для открытия файла из ресурсов приложения:
    void openFileFromRes(QString filePathInRes, QString* output_path);
};

#endif // MAINWINDOW_H
