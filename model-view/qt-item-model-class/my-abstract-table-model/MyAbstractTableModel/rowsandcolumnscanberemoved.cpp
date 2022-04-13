#include "rowsandcolumnscanberemoved.h"

RowsAndColumnsCanBeRemoved::RowsAndColumnsCanBeRemoved(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex RowsAndColumnsCanBeRemoved::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex RowsAndColumnsCanBeRemoved::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int RowsAndColumnsCanBeRemoved::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int RowsAndColumnsCanBeRemoved::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant RowsAndColumnsCanBeRemoved::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

bool RowsAndColumnsCanBeRemoved::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}

bool RowsAndColumnsCanBeRemoved::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
}
