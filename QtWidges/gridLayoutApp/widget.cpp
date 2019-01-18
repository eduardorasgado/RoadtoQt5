#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    layout = new QGridLayout(this);

    // first row
    // widget, position(row, column)
    layout->addWidget(ui->button1, 0, 0);
    layout->addWidget(ui->button2, 0, 1);
    // Expanding the button 2 rows and 1 column
    layout->addWidget(ui->button3, 0, 2, 2, 1);

    // Second row
    layout->addWidget(ui->button4, 1, 0);
    layout->addWidget(ui->button5, 1, 1);
    //layout->addWidget(ui->button6, 1, 2);

    // thirth layout
    layout->addWidget(ui->button7, 2, 0, 1, 2);
    //layout->addWidget(ui->button8, 2, 1);
    layout->addWidget(ui->button9, 2, 2);

}

Widget::~Widget()
{
    delete ui;
}
