#include "myclass.h"
#include <QDebug>

MyClass::MyClass(QObject *parent) : QObject(parent)
    , m_a(100)
{

}

qulonglong MyClass::aValue() const
{
    return m_a;
}

void MyClass::setAValue(qulonglong const a)
{
    m_a = a;
    emit aValueChanged(m_a);
}

OtherClass MyClass::oValue() const
{
    return m_o;
}

void MyClass::setOValue(OtherClass const& o)
{
    m_o = o;
    emit oValueChanged(m_o);
}

Integer64 MyClass::iValue() const
{
    return m_i;
}

void MyClass::setIValue(Integer64 i)
{
    m_i = i;
    emit iValueChanged(m_i);
}

QString MyClass::sValue() const
{
    return m_s;
}

void MyClass::setSValue(QString const& s)
{
    qDebug() << "MyClass::setSValue(" << s << ")";

    m_s = s;
    emit sValueChanged(m_s);
}
