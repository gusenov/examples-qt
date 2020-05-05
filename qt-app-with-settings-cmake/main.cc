#include "App.h"
#include "MyProgram.h"

int main(int argc, char **argv) {
    App app ( argc, argv, "MyCompany", "МуАрр") ;

    QSettings* pst = App::theApp()->settings();
    pst->setValue ( "Language", "en");

    MyProgram myProgram;
    myProgram.show();
    return app.exec();
}