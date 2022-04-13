#pragma once

#include <QAbstractListModel>

// Для создания своей собственной модели нужно унаследовать
// либо класс QAbstractItemМodel, либо один из унаследованных от него классов. Обычно это
// могут быть QAbstractListModel или QAbstractTableModel. Первый класс представляет собой
// одномерный список, второй - двумерную таблицу.

// Наследовать классы QAbstractItemМodel, QAbstractListModel и QAbstractTableModel нужно
// обязательно, так как они содержат чисто виртуальные методы, и произвести от них объект
// напрямую не получится. Есть два класса, которые не содержат чисто виртуальных методов,
// - это QStandardItemМodel и QStringListModel - от них можно производить объекты,
// не наследуя их

// Класс модели для списка целых чисел:
class IntListModel : public QAbstractListModel {
Q_OBJECT
private:
    QList<int> m_list;

public:
    IntListModel(const QList<int>& list,
                 QObject* pobj = 0);


    // Для реализации модели на базе
    // класса QAbstractListModel необходимо реализовать методы rowCount() и data():

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    // Будет сообщать о количестве строк модели.

    QVariant data(const QModelIndex& index,
                 int nRole) const;
    // Отвечает за доставку
    // данных, которые он возвращает в объектах класса QVariant.


    // Модель допускает изменение данных, и именно поэтому мы обязаны переопределить
    // методы flags() и setData():

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool setData(const QModelIndex& index,
                 const QVariant& value,
                 int nRole);


    // Модель будет допускать операции вставки и удаления строк:

    bool insertRows (int nRow,
                     int nCount,
                     const QModelIndex& parent = QModelIndex());

    bool removeRows(int nRow,
                    int nCount,
                    const QModelIndex& parent = QModelIndex());


    QVariant headerData(int nSection,
                        Qt::Orientation orientation,
                        int nRole = Qt::DisplayRole) const;
    // Нужно для того, чтобы модель
    // работала с заголовками QTableView и QTreeView,
    // хотя такое требование и не является обязательным.

};