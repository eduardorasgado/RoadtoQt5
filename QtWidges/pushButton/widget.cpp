#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), buttonFont{"Times", 20, QFont::Bold}
{
    this->setWindowTitle("Push Button App");

    initGeneralButtons();
    // connecting signals and slots
    signalSlotsConnections();
}

Widget::~Widget()
{
    delete button;
}

void Widget::initGeneralButtons()
{
    button = new QPushButton("Press here", this);
    button->setMinimumSize(200,100);
    button->move(0, 50);
    button->setFont(buttonFont);

    button2 = new QPushButton("Press me", this);
    button2->setMinimumSize(200,100);
    button2->move(300, 50);
    button2->setFont(buttonFont);
}

void Widget::signalSlotsConnections()
{
    // button signal
    connect(button, &QPushButton::clicked, [=](){
       qDebug() << "button was clicked";
    });

    // button 2 signals
    connect(button2, &QPushButton::pressed,[=](){
        qDebug() << "Button [2] was pressed";
    });

    connect(button2, &QPushButton::released, [=](){
        qDebug() << "Button [2] was released";
    });
}

QSize Widget::sizeHint() const
{
    // defining the gadget window size
    return QSize(500, 200);
}
