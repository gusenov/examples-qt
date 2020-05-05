#include "MyProgram.h"
#include <QLabel>
#include <QTextEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QVBoxLayout>

MyProgram::MyProgram(QWidget* pwgt/*=0*/)
    : QWidget(pwgt)
    , m_settings("BHV", "MyProgram")
{
    m_plbl = new QLabel;  // виджет надписи
    m_ptxt = new QTextEdit;  // виджет текстового поля

    // Флажок Disable edit (Отключить редактирование)
    // включает/выключает режим редактирования текстового поля:
    m_pchk = new QCheckBox ("Disable edit");  // виджет флажка

    // Виджет выпадающего списка
    // управляет изменением расцветки текстового поля и предоставляет два режима: Classic
    // (Классический), когда текст - черный, а фон - белый, и Borland (стиль расцветки фирмы
    // Borland), когда текст - желтый, а фон - синий.
    m_pcbo = new QComboBox;  // виджет выпадающего списка

    // Методом addItem() в виджет выпадающего списка
    // добавляются опции Classic и Borland, обозначающие текущую расцветку текстового поля:
    m_pcbo->addItem("Classic");
    m_pcbo->addItem("Borland");

    // Сигнал clicked() виджета флажка (указатель m_pchk) соединяется со слотом
    // slotCheckBoxClicked():
    connect(m_pchk, SIGNAL(clicked()), SLOT(slotCheckBoxClicked()));

    // Сигнал activated(int) виджета выпадающего списка со слотом
    // slotComЬoBoxActivated(int):
    connect(m_pcbo, SIGNAL(activated(int)), SLOT(slotComboBoxActivated(int)));

    readSettings();

    // Виджеты размещаются при помощи компоновок (layout setup):

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    pvbxLayout->setContentsMargins(5, 5, 5, 5);
    phbxLayout->setSpacing(15);
    pvbxLayout->setSpacing(15);
    pvbxLayout->addWidget(m_plbl);
    pvbxLayout->addWidget(m_ptxt);
    phbxLayout->addWidget(m_pcbo);
    phbxLayout->addWidget(m_pchk);
    pvbxLayout->addLayout(phbxLayout) ;
    setLayout(pvbxLayout);
}

void MyProgram::readSettings()
{
    // Методом beginGroup() объекту класса QSettings передается префикс ключа:
    m_settings.beginGroup("/Settings");
    // Это делается
    // для того, чтобы не передавать в методы чтения настроек полный ключ.

    // Для получения данных нужно воспользоваться методом value(), который возвращает значения
    // типа QVariant. Благодаря этому класс QSettings предоставляет методы для чтения
    // разных типов - полученные значения типа QVariant необходимо лишь привести к нужному
    // вам типу. Это существенно облегчает задачу. В метод value() можно передавать два параметра:
    // первый параметр - это сам ключ, а второй - значение ключа, которое будет возвращаться
    // том в случае, если ключ не найден.

    QString strText = m_settings.value("/text", "").toString();
    // В том случае, если к.точа с именем /text не существует, метод вернет
    // значение, указанное во втором параметре, то есть пустую строку.

    // Инициализация переменных nWidth и nHeight, предназначенных для хранения
    // размеров окна:

    m_settings.beginGroup("/Geometry");
    int nWidth = m_settings.value("/width", width()).toInt();
    int nHeight = m_settings.value("/height", height()).toInt();
    m_settings.endGroup();

    // Индекс опции виджета выпадающего списка:
    int nComboItem = m_settings.value("/highlight", 0) .toInt();

    // Значения разрешения редактирования:
    bool bEdit = m_settings.value("/edit", false) .toBool();

    // Подсчет количества запусков программы:
    m_nCounter = m_settings.value("/counter", 1).toInt();
    QString str = QString().setNum(m_nCounter++);
    // Надпись информирует о количестве запусков приложения:
    m_plbl->setText("This program has been started " + str +" times");

    m_ptxt->setPlainText(strText);

    resize(nWidth, nHeight);

    m_pchk->setChecked(bEdit);
    slotCheckBoxClicked();

    m_pcbo->setCurrentIndex(nComboItem);
    slotComboBoxActivated(nComboItem ) ;

    m_settings.endGroup();
}


// Деструктор - это самое удобное место, где можно выполнить
// запись настроек приложения, так как он вызывается при уничтожении виджета:
/*virtual*/MyProgram::~MyProgram()
{
    // Для записи настроек используется метод writeSettings():
    writeSettings();
}

// АДЕКВАТНАЯ ЗАМЕНА ДЕСТРУКТОРА
// Вместо деструктора можно воспользоваться методом обработки события closeEvent(),
// который вызывается при закрытии окна виджета.


void MyProgram::writeSettings()
{
    // Чтобы в методы ключ не передавать полностью, можно задать его префикс методом
    // beginGroup():
    m_settings.beginGroup("/Settings") ;

    // Для записи настроек приложения служит метод setValue(). Первым параметром в метод
    // передается ключ, а вторым - значение:
    m_settings.setValue("/counter", m_nCounter);
    m_settings.setValue("/text", m_ptxt->toPlainText()) ;

    // Методы префиксов разрешается вкладывать друг в друга, получая
    // тем самым длинные ключи.
    m_settings.beginGroup("/Geometry");
    m_settings.setValue("/width", width());
    m_settings.setValue("/height", height());
    m_settings.endGroup();

    m_settings.setValue("/highlight", m_pcbo->currentIndex());
    m_settings.setValue("/edit", m_pchk->isChecked());

    // Если такого ключа не существует, то он будет создан.
    // Настройки базируются на использовании класса QVariant, что позволяет
    // записывать значения следующих типов: bool, double, int, QString, QRect, QImage и т. д.

    // После использования ключей, связанных с этим префиксом, необходимо
    // вызвать метод endGroup():
    m_settings.endGroup();
}

void MyProgram::removeSettings()
{
    m_settings.beginGroup("/Settings");

    // Для удаления ключей и их значений нужно передать имя ключа в метод remove() класса
    // QSettings:

    m_settings.remove("/counter");

    m_settings.endGroup();
}

// Метод slotCheckBoxClicked() устанавливает виджет текстового поля в активное или неактивное
// состояние в зависимости от состояния виджета флажка, возвращаемого методом
// isChecked():
void MyProgram::slotCheckBoxClicked()
{
    m_ptxt->setEnabled(!m_pchk->isChecked());
}

// Метод slotComboBoxActivated(), устанавливает цвет фона
// и шрифта виджета текстового поля в зависимости от индекса элемента выпадающего списка n:
void MyProgram::slotComboBoxActivated(int n)
{
    QPalette pal = m_ptxt->palette();

    // Изменение палитры осуществляется только для активного состояния виджета
    // QPalette::Active:
    pal.setColor(QPalette::Active, QPalette::Base, n ? Qt::darkBlue : Qt::white);
    pal.setColor(QPalette::Active, QPalette::Text, n ? Qt::yellow   : Qt::black);
    m_ptxt->setPalette(pal);
}
