#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // This solves the warning:
    // QApplication: invalid style override passed, ignoring it.
    qputenv("QT_STYLE_OVERRIDE","");

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
