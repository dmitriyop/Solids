#include <QApplication>

#include "mainwindow.h"
#include "solids.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Solids sls;
    sls.showMainWIndow();

    return a.exec();
}
