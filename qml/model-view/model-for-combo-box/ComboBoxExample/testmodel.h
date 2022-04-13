#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QAbstractListModel>

class TestModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum TestRoles {
        kLst = Qt::UserRole + 1
    };

    explicit TestModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
};

#endif // TESTMODEL_H
