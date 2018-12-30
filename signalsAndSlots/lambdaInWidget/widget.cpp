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
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    // on click event
    qDebug() << "User clicked on button";
    ui->label->setText("Hello there");
}
