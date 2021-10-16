#ifndef OTHERCLASS_H
#define OTHERCLASS_H

#include <QObject>

class OtherClass : public QObject
{
    Q_OBJECT
public:
    explicit OtherClass(QObject *parent = nullptr);
    OtherClass(OtherClass const& anOther);
    OtherClass& operator=(OtherClass const& anOther);

signals:

};

#endif // OTHERCLASS_H
