#include "contact.h"

Contact::Contact(QString name, QString phone, uint age)
{
    name_ = name;
    phone_ = phone;
    age_ = age;
}

void Contact::setName (QString name)
{
    name_ = name;
}

void Contact::setPhone (QString phone)
{
    phone_ = phone;
}

void Contact::setAge(uint age)
{
    age_ = age;
}

QString Contact::getName() const
{
    return name_;
}

QString Contact::getPhone() const
{
    return phone_;
}

uint Contact::getAge() const
{
    return age_;
}
