#include "print.h"
#include "ui_print.h"
#include <QPainter>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>

// Конструктор:
Print::Print(QWidget *parent) :
    QWidget(parent),  // вызов родительского конструктора.
    ui(new Ui::Print)
{
    ui->setupUi(this);
}

// Деструктор:
Print::~Print()
{
    delete ui;
}

// Установить результирующий текст:
void Print::setResultText(QString& resultText)
{
    int w = ui->labelResult->width();  // ширина холста.
    int h = ui->labelResult->height();  // высота хоста.
    QSize sz(w, h);  // размеры холста.

    QPixmap pix(sz);  // холст.
    pix.fill(Qt::white);  // заливаем холст белым цветом.

    QPainter painter(&pix);

    // Рисуем текст:
    painter.drawText(10, 10, w, h, Qt::AlignLeft | Qt::AlignTop, resultText);

    ui->labelResult->setPixmap(pix);
}

// Обработчик нажатия на кнопку Закрыть:
void Print::on_pushButtonClose_clicked()
{
    hide();  // скрыть окно.
}

// Обработчик нажатия на кнопку Печать:
void Print::on_pushButtonPrint_clicked()
{
    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Печать документа");

    if (dialog->exec() != QDialog::Accepted)
        return;

    QPainter painter;
    painter.begin(&printer);

    // Печать холста:
    painter.drawPixmap(0, 0, *(ui->labelResult->pixmap()));

    painter.end();
}
