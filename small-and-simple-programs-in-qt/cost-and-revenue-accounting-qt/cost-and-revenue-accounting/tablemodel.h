#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QMap>

#include "base.h"
#include "indexes.h"

// Модель данных для таблицы:
class TableModel : public QAbstractTableModel  // унаследовано от QAbstractTableModel.
{
    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:

    // Конструктор:
    explicit TableModel(QObject *parent = nullptr, QString tableTitle = "");


    // Получение данных в виде экземпляра класса QJsonObject:
    QJsonObject getDataAsJsonObject();

    // Установка данных из экземпляра класса QJsonObject:
    void setDataFromJsonObject(QJsonObject jsonObj);

    // Установка данных из словаря типа QMap<QString, QList<Base>>:
    void setItemList(QMap<QString, QList<Base>> itemList);


    // Переопределение методов табличной модели данных:

    // Количество строк:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    // Количество столбцов:
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // Данные:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Элементы можно менять:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    // Флаги:
    Qt::ItemFlags flags(const QModelIndex& index) const override;


// Приватные члены класса:
private:

    // Заголовок таблицы:
    QString tableTitle;

    // Выбранный месяц:
    QString selectedMonth;

    // Данные:
    QMap<QString, QList<Base>> itemList;

    // Метод для подсчёта итога за месяц:
    double getTotalForMonth(QString monthName) const;

};

#endif // TABLEMODEL_H
