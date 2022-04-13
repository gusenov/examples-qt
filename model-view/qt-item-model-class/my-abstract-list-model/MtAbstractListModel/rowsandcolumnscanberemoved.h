#ifndef ROWSANDCOLUMNSCANBEREMOVED_H
#define ROWSANDCOLUMNSCANBEREMOVED_H

#include <QAbstractListModel>

class RowsAndColumnsCanBeRemoved : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit RowsAndColumnsCanBeRemoved(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
};

#endif // ROWSANDCOLUMNSCANBEREMOVED_H
