#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), labelFont{"Times", 16, QFont::Thin}
{
    //adding form
    createForm();
}

Widget::~Widget()
{
    delete firstNameLabel;
    delete firstNameLineEdit;

}

QSize Widget::sizeHint() const
{
    return QSize(400, 400);
}

void Widget::createForm()
{
    createLabels();
    createLineEdits();
}

void Widget::createLabels()
{
    // First name
    firstNameLabel = new QLabel("First name:", this);
    firstNameLabel->setMinimumSize(70, 50);
    firstNameLabel->setFont(labelFont);
    firstNameLabel->move(10,10);

    //last name
    lastNameLabel = new QLabel("Last name:", this);
    lastNameLabel->setMinimumSize(70, 50);
    lastNameLabel->setFont(labelFont);
    lastNameLabel->move(10,40);
}

void Widget::createLineEdits()
{
    // adding an input for label
    firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200, 20); //box size
    firstNameLineEdit->move(110, 22);

    //lastName
    lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200, 20);
    lastNameLineEdit->move(110, 54);
}

