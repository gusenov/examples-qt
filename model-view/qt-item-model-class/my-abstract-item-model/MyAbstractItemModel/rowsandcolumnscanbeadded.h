#ifndef ROWSANDCOLUMNSCANBEADDED_H
#define ROWSANDCOLUMNSCANBEADDED_H

#include <QAbstractItemModel>

class RowsAndColumnsCanBeAdded : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit RowsAndColumnsCanBeAdded(QObject *parent = nullptr);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

private:
};

#endif // ROWSANDCOLUMNSCANBEADDED_H
