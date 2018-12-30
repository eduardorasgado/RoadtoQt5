#include "widget.h"
// include restinio from conan
// restinio is a web services and real time library for C++
#include "restinio/all.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_STYLE_OVERRIDE", "");
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
