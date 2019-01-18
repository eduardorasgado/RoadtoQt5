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
    delete b_drink_group;
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

    // create drink ckech btn group
    b_drink_group = new QButtonGroup(this);
    b_drink_group->addButton(ui->checkBox_beer);
    b_drink_group->addButton(ui->checkBox_juice);
    b_drink_group->addButton(ui->checkBox_coffee);

    b_drink_group->setExclusive(false);

    // creating the radion button group
    rb_pets_group = new QButtonGroup(this);
    rb_pets_group->addButton(ui->radioButton_dog);
    rb_pets_group->addButton(ui->radioButton_cat);
    rb_pets_group->addButton(ui->radioButton_hamster);
}

void Widget::initButtons()
{
    //
}

void Widget::initSignals()
{

    // saving OS data
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

    // saving Drink data
    connect(ui->save_dring_btn, &QPushButton::clicked, [=](){
        auto box_selected = b_drink_group->buttons();
        QString drinks;
        for(auto& b : box_selected)
        {
            if(b->isChecked()){
                drinks += b->text()+ ", ";
            }
        }
        // in case a comma is at the end: ", ", delete it
        //qDebug() << drinks.at(drinks.size()-1);
        drinks = drinks.remove(drinks.size()-1, 1);
        drinks = drinks.remove(drinks.size()-1, 1);

        QMessageBox::information(this, "Your drink(s)", "Your option was: "
                                 + drinks,
                                 QMessageBox::Ok);

    });

    // radion button group signals
    connect(ui->save_pet_btn, &QPushButton::clicked, [=](){
        auto btn_name = rb_pets_group->checkedButton()->text();
        QMessageBox::information(this, "Your fav pet", "Your favorite pet is: a "
                                 +btn_name,
                                 QMessageBox::Ok);
    });
}
