#include "tabform.h"
#include "ui_tabform.h"
#include <QDebug>

TabForm::TabForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabForm)
{
    ui->setupUi(this);
}

TabForm::~TabForm()
{
    delete ui;
}

// Конфигурирование вкладки:
void TabForm::config(QStringListModel *model, AppModel *appDataModel, DeviceType deviceType)
{
    this->deviceType = deviceType;
    this->appDataModel = appDataModel;

    this->model = model;
    ui->comboBoxChoice->setModel(this->model);
}

// Обработчик события смены выбора устройства:
void TabForm::on_comboBoxChoice_currentIndexChanged(int index)
{
    // Показать характеристики выбранного компонента:
    ui->plainTextEditSpecifications->setPlainText(
        appDataModel->getSpecificationsByIndex(this->deviceType, index)
    );

    // Пересчитать цену в завимисости от количества:
    on_spinBoxQuantityValue_valueChanged(ui->spinBoxQuantityValue->value());

    // Проверить совместимость:
    emit checkCompatibilitySignal();
}

// Обработчик события смены количества выбранного устройства:
void TabForm::on_spinBoxQuantityValue_valueChanged(int arg1)
{
    int currentIndex = ui->comboBoxChoice->currentIndex();
    if (currentIndex == -1)
        return;

    // Пересчитать цену в завимисости от количества:
    price = appDataModel->getPriceByIndex(this->deviceType, currentIndex) * arg1;
    ui->labelPriceValue->setText(
        QString::number(price) + " ₽"
    );
}

// Поулучение строки с выбранным устройством для выписки:
QString TabForm::getText()
{
    QString result = QString("%1 x%2 = %3\n%4\n\n").arg(
        ui->comboBoxChoice->currentText(),
        QString::number(ui->spinBoxQuantityValue->value()),
        ui->labelPriceValue->text(),
        ui->plainTextEditSpecifications->toPlainText()
    );
    return result;
}

// Получение цены выбранного устройства:
int TabForm::getPrice()
{
    return price;
}

// Получение индекса выбранного устройства:
int TabForm::getDeviceIndex()
{
    return ui->comboBoxChoice->currentIndex();
}
