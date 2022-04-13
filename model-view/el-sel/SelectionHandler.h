//
// Created by Abbas Gussenov on 2020-02-11.
//

#ifndef SelectionHandler_h
#define SelectionHandler_h

#include <QObject>
#include <QItemSelection>
#include <QDebug>

class SelectionHandler : public QObject {
    Q_OBJECT
public:
    explicit SelectionHandler(QObject *parent = nullptr): QObject(parent) {
    }

    ~SelectionHandler() override = default;

public slots:
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
        qDebug() << "QItemSelectionModel::selectionChanged { selected = " << selected << "; deselected = " << deselected << " }";
    }

    void onCurrentRowChanged(const QModelIndex &current, const QModelIndex &previous) {
        qDebug() << "QItemSelectionModel::currentRowChanged { current = " << current << "; previous = " << previous << " }";
    }
};

#endif /* SelectionHandler_h */
