#include "rowsandcolumnscanbeadded.h"

RowsAndColumnsCanBeAdded::RowsAndColumnsCanBeAdded(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex RowsAndColumnsCanBeAdded::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex RowsAndColumnsCanBeAdded::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int RowsAndColumnsCanBeAdded::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int RowsAndColumnsCanBeAdded::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant RowsAndColumnsCanBeAdded::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

bool RowsAndColumnsCanBeAdded::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool RowsAndColumnsCanBeAdded::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
}
