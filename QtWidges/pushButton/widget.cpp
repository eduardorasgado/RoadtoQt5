#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), buttonFont{"Times", 20, QFont::Bold}
{
    this->setWindowTitle("Push Button App");

    button = new QPushButton("Press here", this);
    button->setMinimumSize(200,100);
    button->setFont(buttonFont);
    // connecting signals and slots
    signalSlotsConnections();
}

Widget::~Widget()
{
    delete button;
}

void Widget::signalSlotsConnections()
{
    // button signal
    connect(button, &QPushButton::clicked, [=](){
       qDebug() << "button was pressed";
    });
}
