#include "formabout.h"
#include "ui_formabout.h"

// Конструктор:
FormAbout::FormAbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAbout)
{
    ui->setupUi(this);

    // Установить фиксированный размер окна:
    this->setFixedSize(QSize(width(), height()));

    // Установка иконки окну:
    setWindowIcon(QIcon(":/MyImgRes/people-icon-256.png"));
}

// Деструктор:
FormAbout::~FormAbout()
{
    delete ui;
}

// Обработчик события нажатия на кнопку "Закрыть":
void FormAbout::on_pushButtonClose_clicked()
{
    hide();  // скрыть окно.
}
