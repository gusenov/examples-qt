#include "print.h"
#include "ui_print.h"
#include <QPainter>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QDebug>
#include <QScrollBar>

// Конструктор:
Print::Print(QWidget *parent) :
    QWidget(parent),  // вызов родительского конструктора.
    ui(new Ui::Print)
{
    ui->setupUi(this);

    ui->scrollArea->setWidgetResizable(false);
    ui->scrollArea->setVisible(false);

    // Создание виджета для показа изображения:
    imageLabel = new QLabel();
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    ui->scrollArea->setWidget(imageLabel);

    ui->scrollArea->setStyleSheet("QScrollArea {background-color:white;}");
    ui->scrollArea->horizontalScrollBar()->hide();
}

// Деструктор:
Print::~Print()
{
    delete ui;

    if (imageLabel != nullptr) delete imageLabel;
}

// Установить результирующий текст:
void Print::setResultText(QString& resultText)
{
    ui->scrollArea->setVisible(true);

    int w = ui->scrollArea->width() - ui->scrollArea->verticalScrollBar()->width();  // ширина холста.
    int h = resultText.length() / 2;  // высота хоста.
    QSize sz(w, h);  // размеры холста.

    QPixmap pix(sz);  // холст.
    pix.fill(Qt::white);  // заливаем холст белым цветом.

    QPainter painter(&pix);

    // Рисуем текст:
    painter.drawText(10, 10, w, h, Qt::AlignLeft | Qt::AlignTop, resultText);

    imageLabel->setPixmap(pix);
    imageLabel->adjustSize();
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
    painter.drawPixmap(0, 0, *(imageLabel->pixmap()));

    painter.end();
}
