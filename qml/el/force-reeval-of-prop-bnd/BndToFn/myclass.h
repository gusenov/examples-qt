#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool visible WRITE setVisible READ isVisible NOTIFY visibleChanged )

public:
    explicit MyClass(QObject *parent = nullptr);

    // Функции должны начинаться с маленькой буквы.
    // Иначе в QML будет ошибка:
    // Call of functions that start with an uppercase letter should use 'new'. (M306)

    Q_INVOKABLE void setVisible(bool isVisible);
    Q_INVOKABLE bool isVisible() const;

    Q_INVOKABLE bool dummy(bool val) const;

signals:
    void visibleChanged(bool);

public slots:

private:
    bool m_isVisible;
};

#endif // MYCLASS_H
