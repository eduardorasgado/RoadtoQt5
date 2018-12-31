#include "rockwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_STYLE_OVERRIDE", "");

    //main Application wrapper
    QApplication a(argc, argv);
    RockWidget wt;
    wt.show();

    // it starts an event loop
    return a.exec();
}
