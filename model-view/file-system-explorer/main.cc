// Обозреватель файловой системы.

#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QFileSystemModel model;

    // В принципе, эту модель можно устанавливать
    // в любом представлении, но для отображения иерархических данных и навигации лучше
    // всего подойдет QTreeView.
    QTreeView pTreeView;
    model.setRootPath(QDir::rootPath());
    pTreeView.setModel(&model);
    // pTreeView.show();

    // Для показа определенного пути можно воспользоваться методом index(). Обычно этот
    // метод ожидает три параметра: столбец, строку и индекс предка, но можно обойтись и без
    // них - достаточно передать в него строку с путем. Таким образом, добавив в нашу программу
    // следующие далее строки, мы увидим в нашем представлении содержимое
    // только текущего каталога:
    QModelIndex index = model.index(QDir::currentPath());
    pTreeView.setRootIndex(index);


    // Воспользовавшись слотом setRootIndex() и еще несколькими слотами и сигналами, можно
    // соединить иерархическое представление с табличным представлением и реализовать программу
    // обозревателя:

    QSplitter spl(Qt::Horizontal);  // виджет разделителя

    QTableView* pTableView = new QTableView;  // табличное представление

    // Оба представления разделяют одну и ту же модель (model).
    pTableView->setModel(&model);

    // Основа реализации нашей программы заключается в сигнально-слотовых соединениях.

    // Первое соединение в табличном представлении осуществляет установку в
    // качестве узлового каталога, выбранного в иерархическом представлении.
    QObject::connect(&pTreeView, SIGNAL(clicked(const QModelIndex&)),
                     pTableView, SLOT(setRootIndex(const QModelIndex&)));

    // Второе соединение нам нужно для того, чтобы при выборе одного из
    // каталогов табличного представления выполнялось выделение этого каталога
    // в иерархическом представлении.
    QObject::connect(pTableView, SIGNAL(activated(const QModelIndex&)),
                     &pTreeView, SLOT(setCurrentIndex(const QModelIndex&)));

    // Последнее соединение служит для показа содержимого
    // каталога при работе в табличном представлении.
    // Таким образом, двойной щелчок мыши или нажатие на клавишу <Enter> на
    // каталоге вышлет из табличного представления сигнал activated(), который
    // будет отловлен самим табличным представлением, и слот setRootIndex()
    // установит этот каталог в качестве базового.
    QObject::connect(pTableView, SIGNAL(activated(const QModelIndex&)),
                     pTableView, SLOT(setRootIndex(const QModelIndex&)));

    spl.addWidget(&pTreeView);
    spl.addWidget(pTableView);
    spl.show();

    return app.exec();
}
