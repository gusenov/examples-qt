#ifndef TABFORM_H
#define TABFORM_H

#include <QWidget>
#include <QStringListModel>
#include "appmodel.h"

namespace Ui {
class TabForm;
}

class TabForm : public QWidget
{
    Q_OBJECT

public:
    explicit TabForm(QWidget *parent = nullptr);
    ~TabForm();

    void config(QStringListModel *model, AppModel *appDataModel, DeviceType deviceType);

    QString getText();
    int getPrice();

    int getDeviceIndex();

private slots:
    void on_comboBoxChoice_currentIndexChanged(int index);

    void on_spinBoxQuantityValue_valueChanged(int arg1);

signals:
   void checkCompatibilitySignal();

private:
    Ui::TabForm *ui;

    // Модель данных для выпадающего списка для выбора:
    QStringListModel *model = nullptr;

    AppModel *appDataModel = nullptr;

    DeviceType deviceType;

    int price = 0;  // цена.

};

#endif // TABFORM_H
