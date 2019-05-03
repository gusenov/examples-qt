#include "computercomponent.h"

// Конструктор:
ComputerComponent::ComputerComponent(
        DeviceType type,
        int id,
        QString name,
        int price,
        QString specifications,
        QList<int> compatibility
):
    type(type),
    id(id),
    name(name),
    price(price),
    specifications(specifications),
    compatibility(compatibility)
{

}

// Получить тип компонента:
DeviceType ComputerComponent::getType() const
{
    return type;
}

// Получить идентификатор:
int ComputerComponent::getId() const
{
    return id;
}

// Получить наименование:
QString ComputerComponent::getName() const
{
    return name;
}

// Получить цену:
int ComputerComponent::getPrice() const
{
    return price;
}

// Получить характеристики:
QString ComputerComponent::getSpecifications() const
{
    return specifications;
}

// Получить идентификаторы совместимых компонентов:
QList<int> ComputerComponent::getCompatibility()
{
    return compatibility;
}

// Проверить совместима ли деталь с другой деталью:
int ComputerComponent::isCompatible(const ComputerComponent& component) const
{
    if (compatibility.contains(component.id))
        return 1;  // совместима.
    else if (compatibility.contains(-component.id))
        return -1;  // не совместима.
    else {
        return 0;  // нет информации.
    }
}
