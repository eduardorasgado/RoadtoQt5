#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initUI();
    // multiselection in list using ctrl + click
    ui->list_assignments
            ->setSelectionMode(QAbstractItemView::ExtendedSelection);
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
    }

    if(ui->list_done->count() == 0){
        //hidde button
        ui->button_clean_done->setVisible(false);
    }

    // hide form
    ui->box_asg_form->setVisible(false);
    // set place holders to inputs
    ui->edit_title->setPlaceholderText("Math Homework");
    ui->edit_description->setPlaceholderText("Is all about addition stuff...");
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
    ui->button_finish_assignment ->setVisible(state);
}

QString Widget::createMessage(QList<QListWidgetItem *> selectedItems)
{
    // message when items will be deleted
    QString message = "Are you sure to delete this assignment?";
    if(selectedItems.count() >1) {
        message = " Are you sure to delete this group of "+
                QString::number(selectedItems.count())
                +" assigments?";
    }
    return message;
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
                (ui->edit_description->toPlainText() != ""))
        {
            // save the assignment
            auto assignment = ui->edit_title->text() + " : "
                    + ui->edit_description->toPlainText();
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

void Widget::on_button_delete_assignment_clicked()
{
    // delete item
    auto selectedItems = ui->list_assignments->selectedItems();
    auto message = createMessage(selectedItems);
    auto confirm = QMessageBox::question(this, "Delete an assignment",
                                             message,
                                             QMessageBox::Ok | QMessageBox::No);
    if(confirm == QMessageBox::Ok){
        if(ui->list_assignments->selectedItems().count() == 1)
        {
            qDebug() << "one  item";
            // if it is just one element, we will remove it
            ui->list_assignments->takeItem(ui->list_assignments->currentRow());
        } else {
            // in case it is a list of items selected
            // getting list of selected items
            for(auto& e : ui->list_assignments->selectedItems())
            {
                // if it is one and directly we show use
                // removing the element
                auto actualRow = ui->list_assignments->row(e);
                // removing the row
                ui->list_assignments->takeItem(actualRow);
            }
        }
    }
    // verifying list not empty after deleting element.
    // if it is, then hide buttons
    if(ui->list_assignments->count() == 0) { showButtons(false); }

}
