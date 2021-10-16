#include "otherclass.h"

OtherClass::OtherClass(QObject *parent) : QObject(parent)
{

}

OtherClass::OtherClass(OtherClass const& anOther)
    : OtherClass(anOther.parent())
{

}

OtherClass& OtherClass::operator=(OtherClass const& anOther)
{
    if (this != &anOther)
    {
        setParent(anOther.parent());
    }
    return *this;
}
