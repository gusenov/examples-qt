#ifndef INTEGER64_H
#define INTEGER64_H

#include <QObject>
#include <QString>
#include <QMetaType>

// NOTE: Note that all C++ types registered with the QML type system must be QObject-derived, even if they are non-instantiable.
// https://doc.qt.io/qt-5/qtqml-cppintegration-definetypes.html

class Integer64 : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)

    qint64 m_value;

public:
    explicit Integer64(QObject *parent = nullptr);
    Integer64(qint64 value, QObject *parent);

    Integer64(Integer64 const &other);
    Integer64& operator=(Integer64 const &other);

    QString value() const;
    void setValue(QString value);

    Q_INVOKABLE void add(Integer64 *other);
    Q_INVOKABLE void subtract(Integer64 *other);
    Q_INVOKABLE void multiply(Integer64 *other);
    Q_INVOKABLE void divide(Integer64 *other);

signals:
    void valueChanged(QString);
};

Q_DECLARE_METATYPE(Integer64);

#endif // INTEGER64_H
