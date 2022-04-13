#include <QtWidgets>
#include <QObject>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QWidget wgt;

    // Создаем модель QStringListModel,
    // которую инициализируем строковыми значениями.
    QStringListModel model;
    model.setStringList(QStringList() << "Xandria"
                                      << "Epica"
                                      << "Therion"
                                      << "Evanescence"
                                      << "Nightwish");

    // Класс QSortFilterProxyModel является обобщенной реализацией промежуточной модели,
    // позволяющей выполнять сортировку и отбор.
    QSortFilterProxyModel proxyModel;

    proxyModel.setSourceModel(&model);  // связывается с оригинальной моделью.

    // Для задания критериев отбора может быть
    // использован слот QSortFilterProxyModel::setFilterRegExp(), в который передается объект
    // регулярного выражения класса QRegExp.

    proxyModel.setFilterWildcard("E*");  // в слоте setFilterWildcard () устанавливается маска "Е*".

    // Можно было бы поступить и так: создать виджет текстового поля, с помощью которого
    // пользователь сам бы устанавливал критерий для выборки. В этом случае сигнал
    // textChanged() нужно было бы соединить со слотом setFilterWildcard() модели
    // SortFilterProxyModel, что позволило бы при изменении критерия отбора, находящегося
    // в текстовом поле, сразу же его применить.


    // Создав два представления QListView, в одном из них мы устанавливаем оригинальную модель,
    // а в другом - промежуточную:

    QListView* pListView1 = new QListView;
    pListView1->setModel(&model);

    QListView* pListView2 = new QListView;
    pListView2->setModel(&proxyModel);


    // При добавлении/удалении строк в SourceModel,
    // proxy model автоматически подхватит изменения.

    auto btnRm = new QPushButton;
    btnRm->setText(QObject::tr("Remove row"));

    QObject::connect(btnRm, QOverload<>::of(&QPushButton::released), [&model] () {
        model.removeRow(0);
    });

    auto btnAdd = new QPushButton;
    btnAdd->setText(QObject::tr("Add row"));

    QObject::connect(btnAdd, QOverload<>::of(&QPushButton::released), [&model] () {
        model.insertRow(0);
        model.setData(model.index(0), "Eminem", Qt::ItemDataRole::DisplayRole);
    });


    // Layout setup
    auto pvbxLayout = new QVBoxLayout;
    QHBoxLayout* phbxLayout = new QHBoxLayout;

    pvbxLayout->addWidget(pListView1);
    pvbxLayout->addWidget(btnAdd);
    pvbxLayout->addWidget(btnRm);

    // В левой части окна программы представление
    // отображает оригинальную модель, а в правой - промежуточную.

    phbxLayout->addLayout(pvbxLayout);
    phbxLayout->addWidget(pListView2);

    wgt.setLayout(phbxLayout);

    wgt.show();

    return app.exec();
}