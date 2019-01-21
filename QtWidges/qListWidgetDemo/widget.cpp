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
        showButtons(false);
        // hide form
        ui->box_asg_form->setVisible(false);
        // set place holders to inputs
        ui->edit_title->setPlaceholderText("Math Homework");
        ui->edit_description->setPlaceholderText("Is all about addition stuff...");
    }
}

void Widget::closeCreationForm()
{
    ui->box_asg_form->setVisible(false);
    ui->edit_title->clear();
    ui->edit_description->clear();
}

void Widget::showButtons(bool state)
{
    ui->button_delete_assignment->setVisible(state);
    ui->button_selected_assignment->setVisible(state);
}

void Widget::on_button_form_cancel_clicked()
{
    // in case cancel the clean inputs and hide form
    closeCreationForm();
}

void Widget::on_button_save_form_clicked()
{
    auto confirm = QMessageBox::information(this, "Save Assignment",
                                            "Are you sure?",
                                            QMessageBox::Ok | QMessageBox::No);
    if(confirm == QMessageBox::Ok){
        // then save item and hide and clean form
        // if inputs are not empty
        if((ui->edit_title->text() != "") &&
                (ui->edit_description->text() != ""))
        {
            // save the assignment
            auto assignment = ui->edit_title->text() + " : " + ui->edit_description->text();
            ui->list_assignments->addItem(assignment);
            // clear the form
            closeCreationForm();
            if(ui->list_assignments->count() != 0){
                // show the buttons
                showButtons(true);
            }
        } else {
            QMessageBox::information(this, "No data",
                                     "Please complete the form to save your assignment",
                                     QMessageBox::Ok);
        }

    }

}
