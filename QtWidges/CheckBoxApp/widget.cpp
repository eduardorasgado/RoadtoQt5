#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initBox();
    initButtons();
    initSignals();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::initBox()
{
    // to create an exclusive check bx option
    b_group = new QButtonGroup(this);
    b_group->addButton(ui->checkBox_windows);
    b_group->addButton(ui->checkBox_linux);
    b_group->addButton(ui->checkBox_mac);

    b_group->setExclusive(true);
}

void Widget::initButtons()
{
    //
}

void Widget::initSignals()
{
    std::vector<QCheckBox*> btns{ui->checkBox_windows, ui->checkBox_linux, ui->checkBox_mac};
    connect(ui->save_data_btn, &QPushButton::clicked ,[=](){
        //auto box_name = b_group->checkedButton()->text();
        for(auto& btn : btns)
        {
            if( b_group->checkedButton() == btn){
                //auto option
                QMessageBox::information(this, "Your option", "Your option was: "
                                         + btn->text(),
                                     QMessageBox::Ok);
            }
        }
    });
}
