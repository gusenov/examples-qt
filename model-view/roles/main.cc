#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QStringList lst;
    lst << "Linux" << "Windows" << "macOS" << "Android";

    QStandardItemModel model(lst.size(), 1);
    for (int i = 0; i < model.rowCount(); ++i) {
        QModelIndex index = model.index(i, 0);
        QString str = lst.at(i);

        // Для отображения текста мы создаем список строк с использованием роли
        // Qt::DisplayRole:
        model.setData(index, str, Qt::DisplayRole);

        // Для отображения всплывающей подсказки применяем роль
        // Qt::tооlTipRole:
        model.setData(index, "ToolTip for" + str, Qt::ToolTipRole);

        // С ролью декорации Qt::DecorationRole добавляется растровое изображение,
        // на которое мы ссылаемся посредством конкатенации строки с ".png".
        model.setData(index, QIcon(str + ".png"), Qt::DecorationRole);

        // В результате получается элемент с текстом, растровым изображением
        // и всплывающей подсказкой.
    }

    QListView listView;
    listView.setViewMode(QListView::IconMode);
    listView.setModel(&model);
    listView.show();

    return app.exec();
}