#include "integer64.h"

Integer64::Integer64(QObject *parent) : QObject(parent)
{

}

Integer64::Integer64(qint64 value, QObject *parent)
{
    m_value = value;
}

Integer64::Integer64(Integer64 const &other)
    : Integer64(other.m_value, other.parent())
{

}

Integer64& Integer64::operator=(Integer64 const &other)
{
    if (this != &other)
        m_value = other.m_value;
    return *this;
}

QString Integer64::value() const
{
    return QString::number(m_value);
}

void Integer64::setValue(QString value)
{
    m_value = value.toLongLong();  //  If you want a qint64 you should call QString::toLongLong().
}

void Integer64::add(Integer64 *other)
{

}

void Integer64::subtract(Integer64 *other)
{

}

void Integer64::multiply(Integer64 *other)
{

}

void Integer64::divide(Integer64 *other)
{

}
