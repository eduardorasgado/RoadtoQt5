#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // initializing buttons in check box 1
    btns = new std::vector<QCheckBox*>();

    btns->push_back(ui->checkBox_windows);
    btns->push_back(ui->checkBox_linux);
    btns->push_back(ui->checkBox_mac);

    initBox();
    initButtons();
    initSignals();

}

Widget::~Widget()
{
    delete ui;
    delete b_group;
    delete btns;
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

    connect(ui->save_data_btn, &QPushButton::clicked ,[=](){
        //auto box_name = b_group->checkedButton()->text();
        for(auto& btn : *btns)
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
