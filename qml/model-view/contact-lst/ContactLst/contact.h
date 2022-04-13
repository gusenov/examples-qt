#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact(QString _name, QString _phone, uint _age);

    void setName (QString _name);
    QString getName() const;

    void setPhone (QString _phone);
    QString getPhone() const;

    void setAge (uint _age);
    uint getAge() const;

private:
    QString name_;
    QString phone_;
    uint age_;
};

#endif // CONTACT_H
