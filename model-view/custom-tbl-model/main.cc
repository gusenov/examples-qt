#include <QtWidgets>
#include "TableModel.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Создаем
    // нашу модель размером 200 на 200:
    TableModel model(200, 200);

    QTableView tableView;

    // Устанавливаем ее в табличное представление:
    tableView.setModel(&model);

    tableView.show();

    return app.exec();
}