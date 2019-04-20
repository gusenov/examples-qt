#ifndef FORMABOUT_H
#define FORMABOUT_H

#include <QWidget>

// Пространство имён Ui:
namespace Ui {

// Предварительное объявление класса FormAbout:
class FormAbout;

}

// Класс FormAbout представляет собой окно "О программе Выживаемость народа":
class FormAbout : public QWidget  // унаследован от Qt-класса QWidget.
{
    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:

    // Явный конструктор:
    explicit FormAbout(QWidget *parent = nullptr);

    // Деструктор:
    ~FormAbout();


// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Обработчик события нажатия на кнопку "Закрыть":
    void on_pushButtonClose_clicked();

// Приватные члены класса:
private:

    // Указатель на форму:
    Ui::FormAbout *ui;
    // Через этот указатель можно получить доступ к виджетам расположенным на форме.
};

#endif // FORMABOUT_H
