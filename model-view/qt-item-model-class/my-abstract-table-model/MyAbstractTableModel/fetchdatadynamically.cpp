#include "fetchdatadynamically.h"

FetchDataDynamically::FetchDataDynamically(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int FetchDataDynamically::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int FetchDataDynamically::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant FetchDataDynamically::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
