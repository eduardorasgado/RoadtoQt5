#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // avoiding override warning
    qputenv("QT_STYLE_OVERRIDE", "");
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
