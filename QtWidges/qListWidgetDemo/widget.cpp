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
    // if add button then show a form
    ui->box_asg_form->setVisible(true);
}

void Widget::initUI()
{
    //no elements in list
    if(ui->list_assignments->count() == 0)
    {
        // hide buttons
        ui->button_delete_assignment->setVisible(false);
        ui->button_selected_assignment->setVisible(false);
        // hide form
        ui->box_asg_form->setVisible(false);
    }
}
