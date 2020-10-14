#include <QApplication>
#include "mainmenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainmenu m;
    m.show();

    return a.exec();
}

