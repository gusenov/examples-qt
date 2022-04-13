#ifndef FETCHDATADYNAMICALLY_H
#define FETCHDATADYNAMICALLY_H

#include <QAbstractTableModel>

class FetchDataDynamically : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FetchDataDynamically(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // FETCHDATADYNAMICALLY_H
