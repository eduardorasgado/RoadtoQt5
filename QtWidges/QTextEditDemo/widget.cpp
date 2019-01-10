#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), textFont{"Times", 10, QFont::Bold}
{
    initLabels();
    initText();
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

void Widget::initText()
{
    textEdit = new QTextEdit(this);
    textEdit->move(70, 55);
}

QSize Widget::sizeHint() const
{
    return QSize(400, 400);
}
