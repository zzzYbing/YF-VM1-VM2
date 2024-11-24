#include "mainwindow.h"


#include <QAxWidget>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    DisposeResource();
}
