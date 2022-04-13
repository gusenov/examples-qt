#ifndef PHONEMODEL_H
#define PHONEMODEL_H

#include <QAbstractListModel>
#include "contact.h"

class PhoneModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum contactRoles {  // множество возможных значений поля
        NameRole = Qt::DisplayRole,  // заголовок для элемента модели ( для нас это имя контакта)
        PhoneRole = Qt::UserRole + 1,  // номер телефона
        AgeRole = Qt::UserRole + 2  // возраст
    };

    explicit PhoneModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    Q_INVOKABLE bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    QHash<int, QByteArray> roleNames() const override;

public slots:
    void addContact(Contact ct);  // добавить контакт в модель

private:
    QList<Contact> contacts_;  // список контактов
    QHash<int, QByteArray> roles_;  // роли
};

#endif // PHONEMODEL_H
