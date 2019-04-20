#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QHBoxLayout>
#include <QLabel>
#include "tablemodel.h"
#include "comboboxitemdelegate.h"
#include "formabout.h"

// Пространство имен Ui:
namespace Ui {

// Предварительное объявление класса MainWindow в пространстве имён Ui:
class MainWindow;

}

// Класс главного окна:
class MainWindow : public QMainWindow  // унаследован от класса QMainWindow.
{
    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:
    // Конструктор:
    explicit MainWindow(QWidget *parent = nullptr);

    // Деструктор:
    ~MainWindow();

// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Выход:
    void on_actionExit_triggered();

    // Открытие файла:
    void on_actionOpen_triggered();

    // Сохранение файла:
    void on_actionSave_triggered();

// Приватные члены класса:
    void on_actionAbout_triggered();

private:

    Ui::MainWindow *ui;


    FormAbout *formAbout;


    // Модель данных для таблицы расходов:
    TableModel *tableModelCosts;

    // Выпадающий список для выбора названия месяца для таблицы расходов:
    ComboBoxItemDelegate *cbidCosts;


    // Модель данных для таблицы доходов:
    TableModel *tableModelIncome;

    // Выпадающий список для выбора названия месяца для таблицы доходов:
    ComboBoxItemDelegate *cbidIncome;


    // Имя файла:
    QString fileName;


    // Статусная строка:
    QHBoxLayout *statusBarLayout;
    QWidget *statusBarContainer;

    // Текстовая метка в статусной строке:
    QLabel *statusBarLabel;


    // Метод для настройки таблиц:
    void setupTable(
        QTableView *tableView,  // виджет таблицы.
        TableModel **tableModel,  // модель данных таблицы.
        QString tableTitle,  // заголовок таблицы.
        ComboBoxItemDelegate **cbid,  // объект для выбора месяца.
        QMap<QString, QList<Base>> itemList  // данные для модели данных таблицы.
    );
};

#endif // MAINWINDOW_H
