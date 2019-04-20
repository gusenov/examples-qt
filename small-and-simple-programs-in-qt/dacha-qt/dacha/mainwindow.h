#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "dachadata.h"

// Пространство имён Ui:
namespace Ui {
// Предварительное объявление класса MainWindow:
class MainWindow;
}

// Класс представляющий собой главное окно программы:
class MainWindow : public QMainWindow
{

    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члена класса:
public:

    // Явный конструктор:
    explicit MainWindow(QWidget *parent = nullptr);

    // Деструктор:
    ~MainWindow();

    // Переопределение метода showEvent для того чтобы
    // обработать событие, когда форма показывается пользователю:
    void showEvent(QShowEvent *event);

// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Обработчик события выбора пункта главного меню Файл → Выход:
    void on_actionExit_triggered();

    // Обработчик события смены выбора типа растения:
    void on_comboBoxType_currentTextChanged(const QString &arg1);

    // Обработчик события смены растения принадлежащего выбранному типу:
    void on_comboBoxPlant_currentTextChanged(const QString &arg1);

// Приватные члены класса:
private:

    // Указатель на форму:
    Ui::MainWindow *ui;
    // Через этот указатель можно получить доступ к виджетам расположенным на форме.

    // Объект для работы с данными из JSON-файла:
    DachaData *dachaData;

    // Модели данных для выпадающих списков
    // в которых выбираются тип растения и какое-нибудь растение
    // принадлежащее этому типу:
    QStringListModel *modelType = nullptr;
    QStringListModel *modelPlant = nullptr;

    // Переменная-флаг служащая для разовой инициализации приложения:
    bool isInitialized;

};

#endif // MAINWINDOW_H
