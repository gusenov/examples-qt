#ifndef  TABLEMODEL_H
#define  TABLEMODEL_H

#include <QtWidgets>

// ======================================================================

// Дпя создания табличной модели на базе класса QAbstractTableModel нужно поступить так
// же, как мы поступили в случае класса QAbstractListModel. Дополнительно к этому, в унаследованном
// от QAbstractTableModel классе необходимо реализовать метод columnCount(),
// предоставляющий информацию о количестве столбцов таблицы. И если модель предполагает
// возможность вставки и удаления столбцов, то необходимо еще дополнительно реализовать
// методы insertColumns() и removeColumns().

// Если бы мы хотели построить класс нашей модели на классе QAbstractItemМodel, то его
// реализация выглядела бы аналогично табличной модели QAbstractTableModel. Но дополнительно
// в унаследованном классе потребовалось бы реализовать методы QAbstractItemМodel::index()
// и QAbstractItemМodel::parent(). В этом случае для создания индексов использовался
// бы метод QAbstractItemМodel::createIndex(), поэтому его тоже нужно было бы перегрузить.

class TableModel : public QAbstractTableModel {
private:
    int m_nRows;
    int m_nColumns;
    QHash<QModelIndex, QVariant> m_hash;  // данные мы храним в хэше.

public:

    // -----------------------------------------------------------------
    TableModel (int nRows, int nColumns, QObject* pobj = 0)
        : QAbstractTableModel(pobj)
        , m_nRows(nRows)
        , m_nColumns(nColumns)
    {
        // В конструкторе мы допускаем инициализацию данными.
    }

    // -----------------------------------------------------------------
    QVariant data(const QModelIndex& index, int nRole) const
    {
        if (!index.isValid()) {
            return QVariant();
        }

        // Данные ячеек устанавливаются автоматически и представляют собой
        // строку, составленную из номеров строки и столбца ячейки.
        QString str = QString("%1, %2").arg(index.row() + 1).arg(index.column() + 1);

        return (nRole == Qt::DisplayRole || nRole == Qt::EditRole)
                ? m_hash.value(index, QVariant(str))
                : QVariant();
    }

    // -----------------------------------------------------------------
    bool setData(const QModelIndex& index,
                const QVariant& value,
                int nRole)
    {
        // Данные можно изменять.
        // Для этого мы проверяем роль Qt::EditRole.

        if (index.isValid() && nRole == Qt::EditRole) {
            m_hash[index] = value;
            emit dataChanged(index, index);
            return true;
        }
        return false;
    }

    // -----------------------------------------------------------------
    int rowCount(const QModelIndex&) const {
        return m_nRows;
    }

    // -----------------------------------------------------------------
    int columnCount(const QModelIndex&) const {
        return m_nColumns;
    }

    // -----------------------------------------------------------------
    Qt::ItemFlags flags(const QModelIndex& index) const
    {
        // Данные можно изменять.
        // Для этого в методе flags() возвращаем
        // значение с добавленным флагом Qt::ItemIsEditable.

        Qt::ItemFlags flags = QAbstractTableModel::flags(index);
        return index.isValid() ? (flags | Qt::ItemIsEditable) : flags;
    }
};

#endif // TABLEMODEL_H
