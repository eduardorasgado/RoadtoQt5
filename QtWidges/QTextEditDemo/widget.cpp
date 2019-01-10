#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), textFont{"Times", 10, QFont::Bold}
{
    initLabels();
}

Widget::~Widget()
{

}

void Widget::initLabels()
{
    mLabel = new QLabel("This is my text", this);
    mLabel->setFont(textFont);
    mLabel->move(100, 25);
}
