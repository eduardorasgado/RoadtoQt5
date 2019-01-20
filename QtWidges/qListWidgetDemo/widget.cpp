#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initUI();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_button_add_assignment_clicked()
{
    //

}

void Widget::initUI()
{
    // hide buttons if no elements in list
    if(ui->list_assignments->count() == 0)
    {
        ui->button_delete_assignment->setVisible(false);
        ui->button_selected_assignment->setVisible(false);
    }
}
