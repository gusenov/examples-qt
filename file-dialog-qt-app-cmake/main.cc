#include <QtGui>
#include <QApplication>
#include "MyProgram.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    MyProgram prog;
    prog.show();

    return app.exec();
}
