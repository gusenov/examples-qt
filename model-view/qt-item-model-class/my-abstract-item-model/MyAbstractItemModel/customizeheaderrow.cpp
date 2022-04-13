#include "customizeheaderrow.h"

CustomizeHeaderRow::CustomizeHeaderRow(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant CustomizeHeaderRow::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex CustomizeHeaderRow::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex CustomizeHeaderRow::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int CustomizeHeaderRow::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int CustomizeHeaderRow::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant CustomizeHeaderRow::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
