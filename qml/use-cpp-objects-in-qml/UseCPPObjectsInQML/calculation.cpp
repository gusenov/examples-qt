#include "calculation.h"

Calculation::Calculation(QObject *parent) : QObject(parent)
{

}

// метод factorial() производит рекурсивное вычисление факториала;
qulonglong Calculation::factorial(const qulonglong& n)
{
    return n ? (n * factorial (n - 1)) : 1;
}

// метод inputValue() - это реализация чтения свойства input, он возвращает его значение;
qulonglong Calculation::inputValue() const
{
    return m_nInput;
}

// метод resultValue() - это реализация чтения свойства result, он возвращает его значение;
qulonglong Calculation::resultValue() const
{
    return m_nResult;
}

// метод setinputValue () - это реализация записи свойства input.
void Calculation::setInputValue(const qulonglong& n)
{
    m_nInput = n;

    // После присвоения нового значения вызовом
    // метода factorial() осуществляется повторное
    // вычисление нового значения факториала.
    m_nResult = factorial(m_nInput);

    // В результате изменяются два значения, и в конце выводится уведомление об изменении
    // двух свойств высылкой сигналов: inputValueChanged() и resultValueChanged().

    emit inputValueChanged(m_nInput);
    emit resultValueChanged(m_nResult);
}
