#include "formabout.h"
#include "ui_formabout.h"

// Конструктор:
FormAbout::FormAbout(QWidget *parent) :
    QWidget(parent),  // вызов конструктора базового класса.
    ui(new Ui::FormAbout)
{
    ui->setupUi(this);
}

// Деструктор:
FormAbout::~FormAbout()
{
    delete ui;
}

// Закрыть:
void FormAbout::on_pushButtonClose_clicked()
{
    hide();  // скрыть форму.
}
