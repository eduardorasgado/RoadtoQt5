#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_STYLE_OVERRIDE", "");
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Todoers: Developer right hand");
    w.show();

    return a.exec();
}
