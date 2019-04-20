#include "mainwindow.h"
#include <QApplication>

// Точка входа в программу:
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Главное окно приложения:
    MainWindow w;

    // Показать главное окно:
    w.show();

    return a.exec();
}
