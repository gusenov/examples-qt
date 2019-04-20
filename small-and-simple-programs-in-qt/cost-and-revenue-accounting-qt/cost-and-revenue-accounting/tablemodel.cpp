#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include "tablemodel.h"

// Конструктор:
TableModel::TableModel(QObject *parent, QString tableTitle)
    : QAbstractTableModel(parent)  // вызов конструктора базового класса:
{
    // Установка заголовка таблицы:
    this->tableTitle = tableTitle;

    // Выбор месяца по умолчанию:
    selectedMonth = "Январь";
}

// Установка данных из словаря типа QMap<QString, QList<Base>>:
void TableModel::setItemList(QMap<QString, QList<Base>> itemList)
{
    this->itemList = itemList;
}

// Количество строк:
int TableModel::rowCount(const QModelIndex &parent) const
{
    // Неиспользуемые параметры:
    Q_UNUSED(parent);

    return itemList[selectedMonth].count() + 3;
}

// Количество столбцов в таблице:
int TableModel::columnCount(const QModelIndex &parent) const
{
    // Неиспользуемые параметры:
    Q_UNUSED(parent);

    return 2;
}

// Данные:
QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int rowIndex = index.row();  // индекс строки.
    int colIndex = index.column();  // индекс столбца.

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (rowIndex) {
        case TABLE_TITLE_ROW_INDEX:
            switch (colIndex) {
            // Отображаем заголовок таблицы:
            case TABLE_TITLE_COL_INDEX: return QVariant(tableTitle);
            }
            break;
        case CURRENCY_ROW_INDEX:
            switch (colIndex) {

            // Отображаем выбранный месяц:
            case MONTH_COL_INDEX: return QVariant(selectedMonth);

            // Отображаем валюту:
            case CURRENCY_COL_INDEX: return QVariant("руб");

            }
            break;
        default:
            if (rowIndex == rowCount() - 1)
            {
                switch (colIndex) {
                case TOTAL_COL_INDEX: return QVariant("Итого");

                // Отображаем итоговую сумму:
                case TOTAL_VALUE_COL_INDEX:
                    double totalValue = getTotalForMonth(selectedMonth);
                    return QVariant(totalValue);

                }
            }

            // Отображение значений по статьям расхода или дохода:
            else if (rowIndex > MONTH_ROW_INDEX && rowIndex < rowCount() - 1)
            {
                QList<Base> list = itemList[selectedMonth];
                Base item = list.at(rowIndex - 2);

                switch (colIndex) {
                case 0: return QVariant(item.getItemName());  // статья.
                case 1: return QVariant(item.getAmount());  // сумма.
                default:
                    break;
                }
            }
        }

    }

    else if (role == Qt::TextAlignmentRole)
    {
        switch (rowIndex) {
        // Выравнивание заголовка таблицы:
        case TABLE_TITLE_ROW_INDEX:
            return Qt::AlignCenter;
        default:
            // Выравнивание итоговой строки:
            if (rowIndex == rowCount() - 1 && colIndex == TOTAL_COL_INDEX)
            {
                return Qt::AlignLeft;
            }

            // Выравнивание численных значений:
            else if (rowIndex > MONTH_ROW_INDEX && colIndex == 1)
            {
                return Qt::AlignLeft;
            }

            // Выравнивание в остальных случаях:
            else return Qt::AlignCenter;
        }
    }

    return QVariant();
}

// Элементы можно менять:
bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int rowIndex = index.row();  // индекс строки.
    int colIndex = index.column();  // индекс столбца.

    switch (rowIndex) {
    case MONTH_ROW_INDEX:
        switch (colIndex) {

        // Сохранение выбранного месяца:
        case MONTH_COL_INDEX:
            // qDebug() << "Месяц =" << value.toString();
            selectedMonth = value.toString();
            break;
        }
        break;

    default:

        // Установка значений по статьям расхода или дохода:
        if (rowIndex > MONTH_ROW_INDEX && rowIndex < rowCount() - 1 && colIndex == 1)
        {
            QList<Base>& list = itemList[selectedMonth];
            // & обозначает, что мы получаем ссылку на список.
            // Без & мы получим копию списка.

            int i = rowIndex - 2;
            Base newItem = list.at(i);
            newItem.setAmount(value.toDouble());
            list.removeAt(i);
            list.insert(i, newItem);
        }

    }

    return false;
}

// Флаги:
Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    int rowIndex = index.row();  // индекс строки.
    int colIndex = index.column();  // индекс столбца.

    switch (rowIndex) {
    case MONTH_ROW_INDEX:
        switch (colIndex) {
        case MONTH_COL_INDEX: return Qt::ItemIsEnabled | Qt::ItemIsEditable;
        }
        break;
    default:
        if (rowIndex > MONTH_ROW_INDEX && rowIndex != rowCount() - 1 && colIndex == 1)
            return Qt::ItemIsEnabled | Qt::ItemIsEditable;
    }

    return QAbstractItemModel::flags(index);
}

// Метод для подсчёта итога за месяц:
double TableModel::getTotalForMonth(QString monthName) const
{
    double result = 0;

    QList<Base> list = itemList[monthName];
    // & обозначает, что мы получаем ссылку на список.
    // Без & мы получим копию списка.

    // Проходим по всем пунктам:
    for (QList<Base>::iterator it = list.begin(); it != list.end(); ++it)
    {
        result += (*it).getAmount();  // и считаем сумму.
    }

    return result;

}

// Получение данных в виде экземпляра класса QJsonObject:
QJsonObject TableModel::getDataAsJsonObject()
{
    QJsonObject json;

    QMapIterator<QString, QList<Base>> i(itemList);
    while (i.hasNext()) {
        i.next();

        QJsonArray arr;

        QListIterator<Base> j(i.value());
        while (j.hasNext()) {
            const Base& item = j.next();

            QJsonObject itemJson;
            itemJson.insert("название", item.getItemName());
            itemJson.insert("сумма", item.getAmount());

            arr.push_back(itemJson);
        }

        json.insert(i.key(), arr);
    }

    return json;
}

// Установка данных из экземпляра класса QJsonObject:
void TableModel::setDataFromJsonObject(QJsonObject jsonObj)
{
    beginResetModel();

    itemList.clear();

    foreach(const QString& key, jsonObj.keys()) {
        QList<Base> list;

        QJsonArray jsonArray = jsonObj.value(key).toArray();

        foreach (const QJsonValue & value, jsonArray) {
            QJsonObject obj = value.toObject();

            Base b(obj["название"].toString(), obj["сумма"].toDouble());
            list.append(b);
        }

        itemList.insert(key, list);
    }

    endResetModel();
}
