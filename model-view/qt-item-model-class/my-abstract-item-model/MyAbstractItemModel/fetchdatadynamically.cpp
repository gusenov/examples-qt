#include "fetchdatadynamically.h"

FetchDataDynamically::FetchDataDynamically(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex FetchDataDynamically::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex FetchDataDynamically::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int FetchDataDynamically::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int FetchDataDynamically::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

bool FetchDataDynamically::hasChildren(const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

bool FetchDataDynamically::canFetchMore(const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return false;
}

void FetchDataDynamically::fetchMore(const QModelIndex &parent)
{
    // FIXME: Implement me!
}

QVariant FetchDataDynamically::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
