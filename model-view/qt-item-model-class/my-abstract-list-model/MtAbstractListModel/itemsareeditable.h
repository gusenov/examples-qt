#ifndef ITEMSAREEDITABLE_H
#define ITEMSAREEDITABLE_H

#include <QAbstractListModel>

class ItemsAreEditable : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ItemsAreEditable(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
};

#endif // ITEMSAREEDITABLE_H
