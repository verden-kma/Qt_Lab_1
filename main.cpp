#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{// todo: handle deleteinon of prime number
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
