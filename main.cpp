#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwidget w;
    w.resize(1024,768);
    w.show();
    return a.exec();
}
