#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_STYLE_OVERRIDE", "");

    //main Application wrapper
    QApplication a(argc, argv);
    Widget w;
    w.show();

    // it starts an event loop
    return a.exec();
}
