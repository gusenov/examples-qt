#ifndef ROWSANDCOLUMNSCANBEADDED_H
#define ROWSANDCOLUMNSCANBEADDED_H

#include <QAbstractTableModel>

class RowsAndColumnsCanBeAdded : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit RowsAndColumnsCanBeAdded(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

private:
};

#endif // ROWSANDCOLUMNSCANBEADDED_H
