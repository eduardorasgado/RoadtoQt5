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
    delete dialog;
    delete ui;
}

void Widget::on_pushButton_provideinfo_clicked()
{
     dialog = new InfoDialog(this);
     // show a dialog as a modal dialog
     dialog->exec();
}
