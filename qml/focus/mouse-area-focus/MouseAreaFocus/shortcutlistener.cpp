#include <QtGui>
#include "shortcutlistener.h"

ShortcutListener::ShortcutListener(QObject *parent) : QObject(parent)
{

}

void ShortcutListener::listenTo(QObject *object)
{
    if (!object)
        return;

    object->installEventFilter(this);

    qDebug() << QDateTime::currentDateTime().toString(Qt::ISODateWithMs)
        << object << ".installEventFilter(" << this << ")";
}

bool ShortcutListener::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        qDebug() << QDateTime::currentDateTime().toString(Qt::ISODateWithMs)
            << objectName() << ": key" << keyEvent->key() << "pressed on" << object;
//        return true;
    }
    return false;
}
