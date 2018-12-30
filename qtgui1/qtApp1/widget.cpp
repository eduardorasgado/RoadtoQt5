#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

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

void Widget::on_pushButton_clicked()
{
    //qDebug() << "You clicked the button";
    QMessageBox::information(this, "Attention",
                             "You clicked in the botton.",
                             QMessageBox::Ok);
}
