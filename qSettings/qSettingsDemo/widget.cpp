#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton1_clicked()
{

}

void Widget::on_pushButton2_clicked()
{

}

void Widget::on_pushButton3_clicked()
{

}

void Widget::on_pushButton4_clicked()
{

}

void Widget::on_pushButton5_clicked()
{

}

void Widget::on_pushButton6_clicked()
{

}

void Widget::on_pushButton7_clicked()
{

}

void Widget::on_pushButton8_clicked()
{

}

void Widget::on_pushButton9_clicked()
{

}

void Widget::on_pushButton_saveColors_clicked()
{

}

void Widget::on_pushButton_loadColors_clicked()
{

}
