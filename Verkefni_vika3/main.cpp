#include "mainwindow.h"
#include <QApplication>
#include <datalayer.h>

int main(int argc, char *argv[])
{
    Datalayer data;
    data.connectDB();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
