#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

// Пространство имён Ui:
namespace Ui {
// Предварительное объявление класса About:
class About;
}

// Класс About представляет собой окно "О программе Сборка ПК":
class About : public QWidget  // унаследован от Qt-класса QWidget.
{

    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:

    // Явный конструктор:
    explicit About(QWidget *parent = nullptr);

    // Деструктор:
    ~About();

// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Обработчик события нажатия на кнопку "Закрыть":
    void on_closePushButton_clicked();

// Приватные члены класса:
private:

    // Указатель на форму:
    Ui::About *ui;
    // Через этот указатель можно получить доступ к виджетам расположенным на форме.
};

#endif // ABOUT_H