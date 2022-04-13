Благодаря индексу (QModelIndex) модель может ссылаться на нужные данные и, тем самым,
передать эти данные представлению. Дпя того чтобы данные были правильно показаны на
экране, представление обращается посредством объекта индекса (QModelIndex) к так называемым
ролям.

Каждый элемент в модели может содержать различные данные, которые привязаны к разным
значениям ролей. Данные заданной роли можно получить с помощью метода
QAЬstractItemМodel::data(), передав в него индекс и значение нужной роли, - например,
DisplayRole. Если для заданной роли не будет найдено соответствующего значения, то
метод data 1) возвратит объект класса QVariant, не содержащий никаких данных.

Элементы, помимо текста, могут иметь и растровое изображение, а также и дополнительный
текст. Нам нужно каким-либо образом обращаться к этим данным. Разумеется, когда
мы рисуем элементы, то используем делегат и можем не пользоваться дополнительной
информацией, которая заложена в элементе посредством ролей.

Существующие представления и делегаты понимают много ролей.
Вот наиболее часто используемые из них:

- DisplayRole - текст для показа:
- DecorationRole - растровое изображение;
- FontRole - шрифт для текста;
- ToolTipRole - текст для подсказки (ToolТip);
- WhatThisRole - текст для подсказки «Что это?»;
- TextColorRole - цвет текста;
- BackgroundColorRole - цвет фона элемента.

Можно задать и свои собственные роли для своих классов, например, так:

```cpp
class GeoModel : public QAbstractListModel (
Q_OBJECT
public:
    enum GeoRoles
    {
        DistanceRole = Qt::UserRole + 1,
        LatitudeRole,
        LongitudeRole
    };
...
};
```