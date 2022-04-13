#include "testmodel.h"

TestModel::TestModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int TestModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return 2;
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == TestRoles::kLst)
    {
        QVariantList list;
        list.append("string1");
        list.append("string2");
        return list;
    }

    return QVariant();
}

QHash<int, QByteArray> TestModel::roleNames() const
{
    static QHash<int, QByteArray> roles {
        { TestRoles::kLst, "lst" }
    };
    return roles;
}
