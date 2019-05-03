#ifndef MULTIPLE_H
#define MULTIPLE_H

#include <QWidget>
#include <QStringListModel>
#include "appmodel.h"
#include "devicetypes.h"

namespace Ui {
class Multiple;
}

class Multiple : public QWidget
{
    Q_OBJECT

public:
    explicit Multiple(QWidget *parent = nullptr);
    ~Multiple();

    void config(QStringListModel *model, AppModel *appDataModel, DeviceType deviceType);
    QString getText();
    int getPrice();

    QList<int> getDeviceIndexes();

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_tabCloseRequested(int index);

    void checkCompatibility();

signals:
   void checkCompatibilitySignal();

private:
    Ui::Multiple *ui;

    // Модель данных для выпадающего списка для выбора:
    QStringListModel *model = nullptr;

    AppModel *appDataModel = nullptr;

    DeviceType deviceType;

    void renameTabsByOrder(void);

    void deleteCloseBtn(int idx);
};

#endif // MULTIPLE_H
