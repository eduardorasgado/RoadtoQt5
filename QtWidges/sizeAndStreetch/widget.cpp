#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Fill this one");
    ui->groupBox_2->setTitle("Download zone");
    ui->groupBox_3->setTitle("Your data");
    ui->groupBox_4->setTitle("Social");
    ui->groupBox_5->setTitle("Gender");
    ui->groupBox_6->setTitle("Calendar");
    ui->groupBox_7->setTitle("Married");

}

Widget::~Widget()
{
    delete ui;
}
