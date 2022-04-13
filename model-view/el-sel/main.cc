// Программа выполняет разделение выделения элементов между тремя
// представлениями. Выделение элемента в одном из представлений приведет к
// выделению этого же элемента и в остальных представлениях.

#include <QtWidgets>
#include "SelectionHandler.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QWidget wgt;

    // Создаем модель списка строк (объект model), которую инициализируем
    // тремя элементами. Каждый элемент является строкой:
    QStringListModel model;
    model.setStringList(QStringList() << "Первая строка"
                                      << "Вторая строка"
                                      << "Третья строка");

    // Создаем три разных представления (указатели pTreeView, pListView и
    // pTableView) и устанавливаем в них нашу модель, вызывая метод setModel():

    auto* pTreeView = new QTreeView;
    pTreeView->setModel(&model);

    auto* pListView = new QListView;
    pListView->setModel(&model);

    auto* pTableView = new QTableView;
    pTableView->setModel(&model);

    // Управление выделением осуществляется при помощи специальной модели, реализованной
    // в классе QItemSelectionModel.

    // Создание модели выделения (объекта класса QItemSelectionModel). При
    // создании этот объект инициализируется оригинальной моделью
    // (объект model):
    QItemSelectionModel selection(&model);

    // Для получения модели выделения элементов,
    // установленной в представлении, нужно вызвать метод QAbstractItemView::selectionМodel(),
    // а установить новую модель можно с помощью метода QAbstractItemView::setSelectionМodel().
    pTreeView->setSelectionModel(&selection);
    pListView->setSelectionModel(&selection);
    pTableView->setSelectionModel(&selection);

    // Индексы текущих выделенных позиций можно получить вызовом метода
    // QItemSelectionModel::selectedIndexes(). А выделять элементы программно
    // можно с помощью метода QItemSelectionModel::select(). При изменениях
    // выделения модель выделений отсылает сигналы currentChanged(),
    // selectionChanged(), currentColumnChanged() и currentRowChanged().

    QObject::connect(&selection,
                     &QItemSelectionModel::currentChanged,
                     [](const QModelIndex &current, const QModelIndex &previous)
    {
        qDebug() << "QItemSelectionModel::currentChanged { current = " << current << "; previous = " << previous << " }";
    });
    // Вызывается сразу при старте приложения.
    // Хотя визуально синее выделение не устанавливается.
    // При клике на 0-й элемент повторно вызван не будет.
    // QItemSelectionModel::currentChanged { current =  QModelIndex(0,0,0x0,QStringListModel(0x7ffee2afba30)) ; previous =  QModelIndex(-1,-1,0x0,QObject(0x0))  }

    SelectionHandler selectionHandler;
    QObject::connect(&selection,
                     SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
                     &selectionHandler,
                     SLOT(onSelectionChanged(const QItemSelection &, const QItemSelection &)));
    // При старте приложения не будет вызван.
    // Но будет вызван при установке выделения (даже на 0-й элемент).
    // QItemSelectionModel::selectionChanged { selected =  (QItemSelectionRange(QModelIndex(0,0,0x0,QStringListModel(0x7ffeeacefa30)),QModelIndex(0,0,0x0,QStringListModel(0x7ffeeacefa30)))) ; deselected =  ()  }

    QObject::connect(&selection,
                     SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
                     &selectionHandler,
                     SLOT(onCurrentRowChanged(const QModelIndex &, const QModelIndex &)));
    // Вызывается сразу при старте приложения.
    // Хотя визуально синее выделение не устанавливается.
    // При клике на 0-й элемент повторно вызван не будет.
    // QItemSelectionModel::currentRowChanged { current =  QModelIndex(0,0,0x0,QStringListModel(0x7ffee0901a30)) ; previous =  QModelIndex(-1,-1,0x0,QObject(0x0))  }

    // Layout setup
    auto* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pTreeView);
    phbxLayout->addWidget(pListView);
    phbxLayout->addWidget(pTableView);
    wgt.setLayout(phbxLayout);

    wgt.show();

    return app.exec();
}