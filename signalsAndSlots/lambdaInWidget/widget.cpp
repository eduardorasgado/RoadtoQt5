#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // title to window
    this->setWindowTitle("Signals and Slots");

    //CONNECTING SLOTS WITH SIGNALS

    // Using String notation
    connect(ui->connectButton, SIGNAL(clicked()),
            this, SLOT(changeText()));

    // Using  Functor notation: Regular slots
    connect(ui->connectButton2, &QPushButton::clicked,
            this, &Widget::changeTextb2);

    // Using Functor notation: Lambdas
    connect(ui->connectButton3, &QPushButton::clicked,
            [=](){
        // this is the lambda that  captures everything in
        // capture list, by value
        // Be sure function does not get too long
        qDebug() << "User clicked on button 3";
        ui->label_3->setText("Lambda Functor");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    // on click event
    qDebug() << "User clicked on button";
    ui->label->setText("String notation");
}

void Widget::changeTextb2()
{
    //
    qDebug() << "User clicked on button 2";
    ui->label_2->setText("Regular Functor");
}

void Widget::changeTextb3()
{
    // this slot is not used by the lambda notation
    qDebug() << "User clicked on button 3";
    ui->label_3->setText("You mad.");
}
