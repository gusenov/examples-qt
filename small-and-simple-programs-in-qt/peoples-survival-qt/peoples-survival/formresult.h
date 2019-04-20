#ifndef FORMRESULT_H
#define FORMRESULT_H

#include <QWidget>

// Пространство имён Ui:
namespace Ui {

// Предварительное объявление класса FormResult:
class FormResult;

}

// Класс FormResult предназначен для отображения результатов программы:
class FormResult : public QWidget  // унаследован от Qt-класса QWidget.
{
    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:

    // Явный конструктор:
    explicit FormResult(QWidget *parent = nullptr);

    // Деструктор:
    ~FormResult();

    // Переопределение метода showEvent для того чтобы
    // обработать событие, когда форма показывается пользователю:
    virtual void showEvent(QShowEvent *);

    // Установка имени народа:
    void setPeopleName(QString peopleName);

    // Установка результатов выживания народа
    // (true - народ выжил, false - погиб):
    void setSurvived(bool isSurvived);

// Приватные слоты
// (слот - это функция, вызываемая в ответ на определенный сигнал):
private slots:

    // Обработчик события нажатия на кнопку "Закрыть":
    void on_pushButtonClose_clicked();

// Приватные члены класса:
private:

    // Указатель на форму:
    Ui::FormResult *ui;
    // Через этот указатель можно получить доступ к виджетам расположенным на форме.

    // Наименование народа:
    QString _peopleName;

    // Результат выживания народа:
    bool _isSurvived = false;
};

#endif // FORMRESULT_H
