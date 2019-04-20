#ifndef FORMABOUT_H
#define FORMABOUT_H

#include <QWidget>

// Пространство имен Ui:
namespace Ui {
// Предварительное объявление класса FormAbout:
class FormAbout;
}

// Класс FormAbout нужен для окна
class FormAbout : public QWidget
{
    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:

    // Конструктор:
    explicit FormAbout(QWidget *parent = nullptr);

    // Деструктор:
    ~FormAbout();

// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Обработчик нажатия на кнопку закрыть:
    void on_pushButtonClose_clicked();

// Приватные члены класса:
private:

    Ui::FormAbout *ui;
};

#endif // FORMABOUT_H
