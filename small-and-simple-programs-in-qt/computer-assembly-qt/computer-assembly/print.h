#ifndef PRINT_H
#define PRINT_H

#include <QWidget>

// Пространство имён Ui:
namespace Ui {
// Предварительное объявление класса Print:
class Print;
}

// Класс About представляет собой окно для печати результатов:
class Print : public QWidget  // унаследован от Qt-класса QWidget.
{

    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:

    // Явный конструктор:
    explicit Print(QWidget *parent = nullptr);

    // Деструктор:
    ~Print();

    // Установить результирующий текст:
    void setResultText(QString& resultText);

// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Обработчик нажатия на кнопку Закрыть:
    void on_pushButtonClose_clicked();

    // Обработчик нажатия на кнопку Печать:
    void on_pushButtonPrint_clicked();

// Приватные члены класса:
private:

    // Указатель на форму:
    Ui::Print *ui;
    // Через этот указатель можно получить доступ к виджетам расположенным на форме.

    // Результирующий текст:
    QString resultText;

};

#endif // PRINT_H
