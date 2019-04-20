#include "formresult.h"
#include "ui_formresult.h"

// Конструктор:
FormResult::FormResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormResult)
{
    ui->setupUi(this);

    // Установить фиксированный размер окна:
    this->setFixedSize(QSize(width(), height()));

    // Установка иконки окну:
    setWindowIcon(QIcon(":/MyImgRes/people-icon-256.png"));
}

// Деструктор:
FormResult::~FormResult()
{
    delete ui;
}

// Установка имени народа:
void FormResult::setPeopleName(QString peopleName)
{
    _peopleName = peopleName;
}

// Установка результатов выживания народа
// (true - народ выжил, false - погиб):
void FormResult::setSurvived(bool isSurvived)
{
    _isSurvived = isSurvived;
}

// Обработчик события нажатия на кнопку "Закрыть":
void FormResult::on_pushButtonClose_clicked()
{
    hide();
}

// Переопределение метода showEvent для того чтобы
// обработать событие, когда форма показывается пользователю:
void FormResult::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);

    // Установка текста результата:
    ui->labelResult->setText(QString("Народ %1 %2").arg(_peopleName, _isSurvived ? "выжил :)" : "умер :("));

    // Установка цвета:
    ui->labelResult->setStyleSheet(_isSurvived ? "QLabel { color: green; }" : "QLabel { color: red; }");
}
