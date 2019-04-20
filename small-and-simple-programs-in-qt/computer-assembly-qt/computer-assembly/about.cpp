#include "about.h"
#include "ui_about.h"

// Конструктор:
About::About(QWidget *parent) :
    QWidget(parent),  // вызов родительского конструктора.
    ui(new Ui::About)
{
    ui->setupUi(this);

    // Установить фиксированный размер окна:
    this->setFixedSize(QSize(width(), height()));

}

// Деструктор:
About::~About()
{
    delete ui;
}

// Обработчик события нажатия на кнопку "Закрыть":
void About::on_closePushButton_clicked()
{
    hide();  // скрыть окно.
}
