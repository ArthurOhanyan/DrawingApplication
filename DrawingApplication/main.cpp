#include "mainwindow.h"
#include <QApplication>
#include <draw.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.show();
    QWidget* wi = nullptr;
    Draw obj(wi);
    obj.show();

    return a.exec();
}
