#ifndef CPPCONNECT_H
#define CPPCONNECT_H

#include <QObject>
#include <QtCore>

class CppConnection : public QObject
{
    Q_OBJECT
public:
    explicit CppConnection(QObject *parent = nullptr);

signals:

public slots:
    void slotQuit() {
        qApp->quit();
    }

    void slotInfo(const QString& str) {
        qDebug() << str;
    }
};

#endif // CPPCONNECT_H
