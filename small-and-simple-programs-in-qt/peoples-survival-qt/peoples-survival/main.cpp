#include "mainwindow.h"
#include <QApplication>

// Точка входа в программу:
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создание главного окна приложения:
    MainWindow w;

    // Отображение главного окна:
    w.show();

    return a.exec();
}
