#include "multiple.h"
#include "ui_multiple.h"
#include <QDebug>
#include <QTabBar>
#include <QThread>

Multiple::Multiple(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multiple)
{
    ui->setupUi(this);

    // Панель вкладок:
    ui->tabWidget->setTabText(0, "№ 1");
    deleteCloseBtn(0);

    ui->tabWidget->setTabText(1, "+");
    deleteCloseBtn(1);

}

void Multiple::deleteCloseBtn(int idx)
{
    QTabBar *tabBar = ui->tabWidget->tabBar();
    tabBar->tabButton(idx, QTabBar::RightSide)->deleteLater();
    tabBar->setTabButton(idx, QTabBar::RightSide, nullptr);
}

Multiple::~Multiple()
{
    delete ui;
}

// Конфигурирование вкладки:
void Multiple::config(QStringListModel *model, AppModel *appDataModel, DeviceType deviceType)
{
    this->model = model;
    this->appDataModel = appDataModel;
    this->deviceType = deviceType;

    for (auto i = 0; i < ui->tabWidget->count() - 1; ++i) {
        TabForm *tab = static_cast<TabForm *>(ui->tabWidget->widget(i));
        tab->config(this->model, this->appDataModel, this->deviceType);

        connect(tab, SIGNAL(checkCompatibilitySignal()), this, SLOT(checkCompatibility()));
        connect(tab, SIGNAL(checkCompatibilitySignal()), this, SLOT(checkCompatibility()));
    }
}

// Проверка совместимости:
void Multiple::checkCompatibility()
{
    emit checkCompatibilitySignal();
}

// Получить выписку по выбранным устройствам:
QString Multiple::getText()
{
    QString result = "";
    for (auto i = 0; i < ui->tabWidget->count() - 1; ++i) {
        TabForm *tab = static_cast<TabForm *>(ui->tabWidget->widget(i));
        result += tab->getText();
    }
    return result;
}

// Получить суммарную цену выбранных устройств:
int Multiple::getPrice()
{
    int result = 0;
    for (auto i = 0; i < ui->tabWidget->count() - 1; ++i) {
        TabForm *tab = static_cast<TabForm *>(ui->tabWidget->widget(i));
        result += tab->getPrice();
    }
    return result;
}

// Обработчик события нажатия на вкладку:
void Multiple::on_tabWidget_tabBarClicked(int index)
{
    if (index == ui->tabWidget->count() - 1) {

        TabForm *newTab = new TabForm(ui->tabWidget);
        newTab->config(this->model, this->appDataModel, this->deviceType);
        connect(newTab, SIGNAL(checkCompatibilitySignal()), this, SLOT(checkCompatibility()));
        connect(newTab, SIGNAL(checkCompatibilitySignal()), this, SLOT(checkCompatibility()));
        ui->tabWidget->insertTab(ui->tabWidget->count() - 1, newTab, "");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 2);

        // Проверить совместимость:
        checkCompatibility();

        renameTabsByOrder();
    }
}

// Обработчик смены выбора вкладки:
void Multiple::on_tabWidget_currentChanged(int index)
{
    if (index == ui->tabWidget->count() - 1)
        ui->tabWidget->setCurrentIndex(index - 1 > 0 ? index - 1 : 0);
}

// Переименование всех вкладок по порядку:
void Multiple::renameTabsByOrder(void)
{
    ui->tabWidget->setTabsClosable(false);
    ui->tabWidget->setTabsClosable(true);

    for (auto i = 0; i < ui->tabWidget->count() - 1; ++i) {
        ui->tabWidget->setTabText(i, QString("№ %1").arg(i + 1));

        if (i == 0 && ui->tabWidget->count() <= 2)
            deleteCloseBtn(i);
    }

    deleteCloseBtn(ui->tabWidget->count() - 1);
}

// Обработчик закрытия вкладки:
void Multiple::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
    renameTabsByOrder();

    // Проверить совместимость:
    checkCompatibility();
}

// Получить индексы выбранных устройств:
QList<int> Multiple::getDeviceIndexes()
{
    QList<int> result;
    for (auto i = 0; i < ui->tabWidget->count() - 1; ++i) {
        TabForm *tab = static_cast<TabForm *>(ui->tabWidget->widget(i));
        result.append(tab->getDeviceIndex());
    }
    return result;
}
