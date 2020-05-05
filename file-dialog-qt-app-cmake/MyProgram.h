#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QLabel>

#define kPixCnt 2

class MyProgram : public QWidget {
Q_OBJECT
private:
    QLabel *lblPix[kPixCnt];
    QPushButton *btnSelectDir;
    QPushButton *btnSavePixmap;
    QPushButton *btnOpenPixmap;
    QPushButton *btnOpenPixmaps;

public:
    MyProgram(QWidget* pwgt = nullptr): QWidget(pwgt)
    {
        auto v = new QVBoxLayout;

        for (int i = 0; i < kPixCnt; ++i) {
            lblPix[i] = new QLabel;
            v->addWidget(lblPix[i]);
        }

        btnSelectDir = new QPushButton;
        btnSelectDir->setText("Open Folder");
        v->addWidget(btnSelectDir);
        connect(btnSelectDir, SIGNAL(clicked()), SLOT(slotBtnSelectDirClicked()));

        btnOpenPixmap = new QPushButton;
        btnOpenPixmap->setText("Open Pixmap");
        v->addWidget(btnOpenPixmap);
        connect(btnOpenPixmap, SIGNAL(clicked()), SLOT(slotBtnOpenPixmapClicked()));

        btnOpenPixmaps = new QPushButton;
        btnOpenPixmaps->setText("Open Pixmaps");
        v->addWidget(btnOpenPixmaps);
        connect(btnOpenPixmaps, SIGNAL(clicked()), SLOT(slotBtnOpenPixmapsClicked()));

        btnSavePixmap = new QPushButton;
        btnSavePixmap->setText("Save Pixmap");
        v->addWidget(btnSavePixmap);
        connect(btnSavePixmap, SIGNAL(clicked()), SLOT(slotBtnSavePixmapClicked()));

        setLayout(v);
    }

    ~MyProgram() override = default;

public slots:
    void slotBtnSelectDirClicked() {
        // getExistingDirectory() - создает окно выбора каталога.
        // Возвращает значение типа
        // QString, содержащее имя и путь выбранного каталога.
        QString str = QFileDialog::getExistingDirectory(
            nullptr,  // указатель на объект-предок
            "Directory Dialog",  // текст заголовка окна
            ""  // строка, представляющая собой рабочий каталог
        );
    }

    void slotBtnOpenPixmapClicked() {
        // getOpenFileName() - создает диалоговое окно выбора одного файла. Этот метод возвращает
        // значение типа QString, содержащее имя и путь выбранного файла.

        // Вызов метода getOpenFileName() запустит диалоговое окно открытия файла:
        QString str = QFileDialog::getOpenFileName(
            nullptr,  // указатель на объект-предок
            "Open Dialog",  // текст заголовка окна
            "",  // строка, представляющая собой рабочий каталог
            "*.png *.jpg *.bmp"  // фильтр (или маска), задающая расширение файлов.
        );

        lblPix[0]->setPixmap(QPixmap(str));
    }

    void slotBtnOpenPixmapsClicked() {
        // getOpenFileNames() - создает диалоговое окно выбора нескольких файлов. Возвращает
        // список строк типа QStringList, содержащих пути и имена файлов.
    }

    void slotBtnSavePixmapClicked() {
        // Создаем объект растрового изображения размером 320х200 пикселов:
        QPixmap pix(320, 200);

        // Создаем объект строкового типа - в эту строку будет
        // помещен выбранный пользователем при помощи диалогового окна формат:
        QString strFilter;

        // Предположим, что мы хотим записать в файл какое-нибудь растровое изображение.
        // Как можно использовать статический метод getSaveFileName(),
        // предназначенный для диалогового окна записи файла:
        QString str = QFileDialog::getSaveFileName(
            nullptr,  // нулевой указатель на объект предка
            tr("Save Pixmap"),  // надпись самого окна
            "Pixmap",  // имя для файла
            "*.png ;; *.jpg ;; *.bmp",  // строка с тремя графическими форматами, разделенными между собой двумя символами точки с запятой: ;; - чтобы каждый из них был представлен отдельным элементом
            &strFilter  // место, куда будет помещен выбранный пользователем формат
        );

        // getSaveFileName() - создает диалоговое окно сохранения файла. Возвращает имя и
        // путь файла в строковой переменной типа QString.

        // После закрытия диалогового окна мы
        // проверяем строку str на содержимое, и если оно есть, то далее при помощи метода
        // QString::contains() мы проверяем строку strFilter на содержание одного из обозначений
        // графического формата:
        if ( !str.isEmpty()) {
            if (strFilter.contains("jpg")) {
                // Растровое изображение записывается вызовом метода QPixmap::save():
                pix.save(str, "JPG");
            } else if ( strFilter.contains ("bmp") ) {
                pix. save ( str, "ВМР" ) ;
            } else {  // Если совпадений для JPG или ВМР не найдено, то растровое изображение будет записано в формате PNG.
                pix.save (str, "PNG");
            }
        }
    }
};