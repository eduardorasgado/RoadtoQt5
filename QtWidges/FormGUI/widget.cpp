#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), labelFont{"Times", 16, QFont::Thin}
{
    //adding form
    createForm();
    //signals and slots
    connectingSignalsAndSlots();
}

Widget::~Widget()
{
    delete firstNameLabel;
    delete lastNameLabel;
    delete cityLabel;
    delete firstNameLineEdit;
    delete lastNameLineEdit;
    delete cityLineEdit;
    delete submitBtn;

}

QSize Widget::sizeHint() const
{
    return QSize(400, 200);
}

void Widget::createForm()
{
    createLabels();
    createLineEdits();
    submitButton();
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

    cityLabel = new QLabel("City:", this);
    cityLabel->setMinimumSize(70, 50);
    cityLabel->setFont(labelFont);
    cityLabel->move(10, 70);
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

    // city line edit
    cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200, 20);
    cityLineEdit->move(110, 86);
}

void Widget::submitButton()
{
    submitBtn = new QPushButton("Save", this);
    submitBtn->setFont(labelFont);
    submitBtn->move(150, 118);
}

void Widget::connectingSignalsAndSlots()
{
    // connecting button and capturing form data
    connect(submitBtn, &QPushButton::clicked,[=](){

        auto firstname = firstNameLineEdit->text();
        auto lastName = lastNameLineEdit->text();
        auto city = cityLineEdit->text();

        qDebug() << "firstname: " << firstname << "| lastname: " << lastName << " | city: " << city;
    });
}

