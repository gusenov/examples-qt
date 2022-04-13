#include "phonemodel.h"

PhoneModel::PhoneModel(QObject *parent)
    : QAbstractListModel(parent)
{
    roles_[NameRole] = "name";
    roles_[PhoneRole] = "phone";
    roles_[AgeRole] = "age";
}




// Fetch data dynamically

int PhoneModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // Implementation:
    return contacts_.size();
}

QVariant PhoneModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // Implementation:
    if (index.row() < 0 || index.row() > contacts_.count())
        return QVariant();
    const Contact & ct = contacts_[index.row()];
    if (role == NameRole)
        return ct.getName();
    else if (role == PhoneRole)
        return ct.getPhone();
    else if (role == AgeRole)
        return ct.getAge();

    return QVariant();
}




// Customize header row

QVariant PhoneModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}




// Items are editable

bool PhoneModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

bool PhoneModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags PhoneModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}




// Rows and columns can be added

bool PhoneModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(
        parent,
        row,             // first index of the new item (row)
        row + count - 1  // and the last "new" index of the items being inserted (row + count - 1).
    );
    // FIXME: Implement me!
    endInsertRows();
}




// Rows and columns can be removed

bool PhoneModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}




QHash<int, QByteArray> PhoneModel::roleNames() const
{
    return roles_;
}




void PhoneModel::addContact(Contact ct)
{
    contacts_ << ct;
}
