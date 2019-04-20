#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QHBoxLayout>
#include <QLabel>
#include "filelist.h"

// Пространство имён Ui:
namespace Ui {
// Предварительное объявление класса MainWindow:
class MainWindow;
}

// Класс главного окна приложения:
class MainWindow : public QMainWindow  // унаследован от QMainWindow.
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

    // Открытие папки:
    void on_actionOpenFolder_triggered();

    // Показать предыдущее изображение:
    void on_actionBack_triggered();

    // Показать следующее изображение:
    void on_actionNext_triggered();

// Приватные члены класса:
private:

    // Указатель на форму:
    Ui::MainWindow *ui;
    // Через этот указатель можно получить доступ к виджетам расположенным на форме.

    // Путь к папке:
    QString dir;

    // Список изображений из папки:
    QStringList imgLst;

    // Индекс текущего изображения:
    int curImgIdx;

    // Кнопки на панели инструментов:
    QToolButton *toolButtonOpenFolder;  // открыть папку.
    QToolButton *toolButtonBack;  // назад.
    QToolButton *toolButtonNext;  // вперёд.
    QToolButton *toolButtonExit;  // выход.

    // Виджет для отображения изображения:
    QLabel *imageLabel;

    // Статусная строка:
    QHBoxLayout *statusBarLayout;
    QWidget *statusBarContainer;

    // Текстовая метка в статусной строке:
    QLabel *statusBarLabel;

    // Показать изображение с индексом imgIdx:
    void showImgByIdx(int imgIdx);

    // Выкл./вкл. кнопку НАЗАД:
    void setBackEnabled(bool isEnabled);

    // Выкл./вкл. кнопку ВПЕРЁД:
    void setNextEnabled(bool isEnabled);

    // Выкл./вкл. кнопку НАЗАД, если нужно:
    void enableOrDisableBackIfNeed();

    // Выкл./вкл. кнопку ВПЕРЁД, если нужно:
    void enableOrDisableNextIfNeed();
};

#endif // MAINWINDOW_H
