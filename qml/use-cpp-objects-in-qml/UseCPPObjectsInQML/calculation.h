#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>

// Класс обязательно должен быть унаследован от класса QObject:
class Calculation : public QObject
{
    Q_OBJECT
private:
    // Свойство input - это параметр ввода, поэтому в определении Q_PROPERTY мы разрешаем
    // для него запись (WRITE), чтение (READ) и уведомление о его изменении (NOTIFY).
    Q_PROPERTY(qulonglong input WRITE setInputValue
                                READ inputValue
                                NOTIFY inputValueChanged )

    // Свойство - result - это выходное значение результата,
    // поэтому оно не должно подвергаться изменениям извне,
    // и для этого мы разрешаем только его чтение (READ) и уведомление
    // о его изменении.
    Q_PROPERTY(qulonglong result READ resultValue
                                 NOTIFY resultValueChanged )

    // Определяем два свойства: input и output
    qulonglong m_nInput;
    qulonglong m_nResult;

public:
    explicit Calculation(QObject *parent = nullptr);

    // Определяем в классе метод factorial() - для вычисления значения факториала
    // и декларируем его как Q_INVOКAВLE:
    Q_INVOKABLE qulonglong factorial(const qulonglong& n);

    // Определяем методы: inputValue(), resultValue(), setinputValue() -
    // для чтения и установки значений свойств:
    qulonglong inputValue( ) const;
    void setInputValue(const qulonglong&);
    qulonglong resultValue ( ) const;

signals:

    // Сигналы: inputValueChanged(), resultValueChanged() -
    // для уведомления об изменении значений свойств:
    void inputValueChanged (qulonglong);
    void resultValueChanged(qulonglong);

public slots:
};

#endif // CALCULATION_H
