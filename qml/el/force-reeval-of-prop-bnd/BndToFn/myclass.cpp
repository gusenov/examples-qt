#include "myclass.h"
#include <QDebug>

MyClass::MyClass(QObject *parent) : QObject(parent), m_isVisible(false)
{

}

void MyClass::setVisible(bool isVisible)
{
    m_isVisible = isVisible;
    emit visibleChanged(m_isVisible);
    // qDebug() << "m_isVisible =" << m_isVisible;
}

bool MyClass::isVisible() const
{
    return m_isVisible;
}

bool MyClass::dummy(bool val) const
{
    return val;
}
