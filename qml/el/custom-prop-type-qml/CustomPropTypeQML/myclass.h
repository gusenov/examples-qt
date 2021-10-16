#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QString>
#include "otherclass.h"
#include "integer64.h"

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qulonglong a WRITE setAValue READ aValue NOTIFY aValueChanged)
    Q_PROPERTY(OtherClass o WRITE setOValue READ oValue NOTIFY oValueChanged)
    Q_PROPERTY(Integer64 i WRITE setIValue READ iValue NOTIFY iValueChanged)
    Q_PROPERTY(QString s WRITE setSValue READ sValue NOTIFY sValueChanged)

    qulonglong m_a;
    OtherClass m_o;
    Integer64 m_i;
    QString m_s;

public:
    explicit MyClass(QObject *parent = nullptr);

    qulonglong aValue() const;
    void setAValue(qulonglong const);

    OtherClass oValue() const;
    void setOValue(OtherClass const&);

    Integer64 iValue() const;
    void setIValue(Integer64);

    QString sValue() const;
    void setSValue(QString const&);

signals:
    void aValueChanged(qulonglong);
    void oValueChanged(OtherClass const&);
    void iValueChanged(Integer64 const&);
    void sValueChanged(QString const&);
};

#endif // MYCLASS_H
