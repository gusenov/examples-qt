#include <QDebug>
#include <QBitmap>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "txtfileinfo.h"

// Конструктор:
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  // вызов конструктора родительского класса.
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Установить фиксированный размер окна:
    this->setFixedSize(QSize(width(), height()));

    setWindowIcon(QIcon(":/images/png/Image-Comics-v2-icon.png"));

    // Создание кнопки на панели инструметов для открытия папки:
    toolButtonOpenFolder = new QToolButton();
    toolButtonOpenFolder->setIcon(QIcon(":/icons/Double-J-Design-Ravenna-3d-Folder-Open.ico"));
    ui->mainToolBar->addWidget(toolButtonOpenFolder);
    connect(toolButtonOpenFolder, SIGNAL(clicked()), this, SLOT(on_actionOpenFolder_triggered()));

    ui->mainToolBar->addSeparator();

    // Создание кнопки на панели инструметов для показа предыдущего изображения:
    toolButtonBack = new QToolButton();
    toolButtonBack->setEnabled(false);
    ui->actionBack->setEnabled(false);
    toolButtonBack->setIcon(QIcon(":/icons/Gakuseisean-Ivista-2-Alarm-Arrow-Left.ico"));
    ui->mainToolBar->addWidget(toolButtonBack);
    connect(toolButtonBack, SIGNAL(clicked()), this, SLOT(on_actionBack_triggered()));

    // Создание кнопки на панели инструметов для показа следующего изображения:
    toolButtonNext = new QToolButton();
    toolButtonNext->setEnabled(false);
    ui->actionNext->setEnabled(false);
    toolButtonNext->setIcon(QIcon(":/icons/Gakuseisean-Ivista-2-Alarm-Arrow-Right.ico"));
    ui->mainToolBar->addWidget(toolButtonNext);
    connect(toolButtonNext, SIGNAL(clicked()), this, SLOT(on_actionNext_triggered()));

    ui->mainToolBar->addSeparator();

    // Создание кнопки на панели инструметов для выхода из программы:
    toolButtonExit = new QToolButton();
    toolButtonExit->setIcon(QIcon(":/icons/Fatcow-Farm-Fresh-Door-open.ico"));
    ui->mainToolBar->addWidget(toolButtonExit);
    connect(toolButtonExit, SIGNAL(clicked()), this, SLOT(on_actionExit_triggered()));

    ui->scrollArea->setWidgetResizable(false);
    ui->scrollArea->setVisible(false);

    // Создание виджета для показа изображения:
    imageLabel = new QLabel();
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    ui->scrollArea->setWidget(imageLabel);

    // Статусная строка:
    this->statusBarContainer = new QWidget();
    this->statusBarLayout = new QHBoxLayout();
    this->statusBarLabel = new QLabel();
    this->statusBarLayout->addWidget(this->statusBarLabel);
    this->statusBarLayout->setContentsMargins(0, 0, 0, 0);
    this->statusBarContainer->setLayout(this->statusBarLayout);
    ui->statusBar->addWidget(this->statusBarContainer);

}

// Деструктор:
MainWindow::~MainWindow()
{
    delete ui;

    // Удаление объектов панели инструментов:
    delete toolButtonOpenFolder;
    delete toolButtonExit;

    // Удаление объектов статусной строки:
    delete this->statusBarLabel;
    delete this->statusBarLayout;
    delete this->statusBarContainer;
}

// Выход из программы:
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

// Открытие папки:
void MainWindow::on_actionOpenFolder_triggered()
{
    dir = QFileDialog::getExistingDirectory(
        this,
        tr("Открытие папки с комиксами"),
        "",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );

    // Показываем в статусной строку путь:
    statusBarLabel->setText(dir);

    FileList fileLst(dir);  // список файлов в заданной папке.
    imgLst = fileLst.getImageList();  // получаем список изображений.

    // Если есть изображения в папке:
    if (imgLst.size() > 0) {
        curImgIdx = 0;
        showImgByIdx(curImgIdx);

        if (imgLst.size() > 1) {
            setNextEnabled(true);  // включить кнопку ВПЕРЁД.
        }

        // Получение и отображение информации о комиксе из текстового файла:
        if (fileLst.hasAnyTxtFiles()) {
            QString infoFilePath = fileLst.getFirstTxtFilePath();
            TxtFileInfo txtInfoFile(infoFilePath);
            ui->labelAuthorValue->setText(txtInfoFile.getAuthor());
            ui->labelNameValue->setText(txtInfoFile.getName());
            ui->labelSeriesValue->setText(txtInfoFile.getSeries());
            ui->labelPublisherValue->setText(txtInfoFile.getPublisher());
        }

    // Иначе:
    } else {
        setNextEnabled(false);  // выключить кнопку ВПЕРЁД.
        ui->scrollArea->setVisible(false);  // скрыть область показа изображения.
    }

    setBackEnabled(false);  // выключить кнопку НАЗАД.
}

// Показать предыдущее изображение:
void MainWindow::on_actionBack_triggered()
{
    if (curImgIdx > 0) {
        --curImgIdx;
        showImgByIdx(curImgIdx);

        enableOrDisableBackIfNeed();
        enableOrDisableNextIfNeed();
    }
}

// Показать следующее изображение:
void MainWindow::on_actionNext_triggered()
{
    if (curImgIdx < imgLst.size()) {
        ++curImgIdx;
        showImgByIdx(curImgIdx);

        enableOrDisableNextIfNeed();
        enableOrDisableBackIfNeed();
    }
}

// Показать изображение с индексом imgIdx:
void MainWindow::showImgByIdx(int imgIdx)
{
    ui->scrollArea->setVisible(true);

    QPixmap pixmap(imgLst.at(imgIdx));

    imageLabel->setPixmap(pixmap);
    imageLabel->adjustSize();

    statusBarLabel->setText(imgLst.at(imgIdx));
}

// Выкл./вкл. кнопку НАЗАД:
void MainWindow::setBackEnabled(bool isEnabled)
{
    toolButtonBack->setEnabled(isEnabled);
    ui->actionBack->setEnabled(isEnabled);
}

// Выкл./вкл. кнопку ВПЕРЁД:
void MainWindow::setNextEnabled(bool isEnabled)
{
    toolButtonNext->setEnabled(isEnabled);
    ui->actionNext->setEnabled(isEnabled);
}

// Выкл./вкл. кнопку НАЗАД, если нужно:
void MainWindow::enableOrDisableBackIfNeed()
{
    toolButtonBack->setEnabled(curImgIdx != 0);
    ui->actionBack->setEnabled(toolButtonBack->isEnabled());
}

// Выкл./вкл. кнопку ВПЕРЁД, если нужно:
void MainWindow::enableOrDisableNextIfNeed()
{
    toolButtonNext->setEnabled(curImgIdx != imgLst.size() - 1);
    ui->actionNext->setEnabled(toolButtonNext->isEnabled());
}
