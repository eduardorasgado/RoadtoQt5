#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_STYLE_OVERRIDE", "");
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Text Editor App");
    w.show();

    return a.exec();
}
