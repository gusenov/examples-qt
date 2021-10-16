#ifndef SHORTCUTLISTENER_H
#define SHORTCUTLISTENER_H

#include <QObject>

class ShortcutListener : public QObject
{
    Q_OBJECT
public:
    explicit ShortcutListener(QObject *parent = nullptr);

    Q_INVOKABLE void listenTo(QObject *object);
    bool eventFilter(QObject *object, QEvent *event) override;

signals:

};

#endif // SHORTCUTLISTENER_H
