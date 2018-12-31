#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    // initializing ui object
    // connecting the form ui to our widget
    // to be able to have access user interactive components
    ui->setupUi(this);
    // set label to void
    ui->label->setText("");

    // slots and signals
    connect(ui->startButton, &QPushButton::clicked,
            [=](){
        // we do not need to access to ui to do some actions on ui
        this->showMessage();
    });

}

Widget::~Widget()
{
    //class destructor
    delete ui;
}

void Widget::showMessage()
{
    qDebug() << "Clicked with lambda";
    ui->label->setText("You clicked me bro!");
}
