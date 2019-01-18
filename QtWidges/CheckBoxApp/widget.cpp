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
    delete rb_pets_group;
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
        bool passed = false;
        for(auto& btn : *btns)
        {
            if( b_group->checkedButton() == btn){
                //auto option
                QMessageBox::information(this, "Your option", "Your option was: "
                                         + btn->text(),
                                     QMessageBox::Ok);
                passed = true;
            }
        }
        if(!passed)
        {
            QMessageBox::information(this, "Your OS", "Please select something",
                                     QMessageBox::Ok);
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
        if(drinks.isEmpty()){
            QMessageBox::information(this, "Your drink(s)", "Please select something",
                                     QMessageBox::Ok);
        }
        else{
            // in case a comma is at the end: ", ", delete it
            //qDebug() << drinks.at(drinks.size()-1);
            drinks = drinks.remove(drinks.size()-1, 1);
            drinks = drinks.remove(drinks.size()-1, 1);

            QMessageBox::information(this, "Your drink(s)", "Your option was: "
                                     + drinks,
                                     QMessageBox::Ok);
        }
    });

    // radion button group signals
    connect(ui->save_pet_btn, &QPushButton::clicked, [=](){
        if(rb_pets_group->checkedButton())
        {
            auto btn_name = rb_pets_group->checkedButton()->text();
            QMessageBox::information(this, "Your fav pet", "Your favorite pet is: a "
                                     +btn_name,
                                     QMessageBox::Ok);
        }
        else{
            QMessageBox::information(this, "Your fav pet", "Please select something",
                                     QMessageBox::Ok);
        }
    });
}

void Widget::checkingSlot(QString box, bool &checked) const
{
    if(checked) { qDebug() << box+" Checkbox is checked"; }
    else { qDebug() << box+" Checkbox is not checked"; }
}


/* created in qt designer by right click in checkbox and click on
 * go to slot
*/
void Widget::on_checkBox_windows_toggled(bool checked)
{
    // whenever  the check box is selected or undo selected
    checkingSlot("Windows", checked);
}

void Widget::on_checkBox_beer_toggled(bool checked)
{
    checkingSlot("Beer", checked);
}

void Widget::on_radioButton_dog_toggled(bool checked)
{
    checkingSlot("Dog radio button", checked);
}


void Widget::on_SaveAll_btn_clicked()
{
    // to store all the data from user
    std::vector<std::string> data;

    // os check box
    auto os_btn = b_group->checkedButton();

    // drinks check box
    auto drinks_buttons = b_drink_group->buttons();

    // pets radio button
    auto pet_btn = rb_pets_group->checkedButton();

    // handling errors
    if(!os_btn || !pet_btn)
    {
        QMessageBox::critical(this, "Ops", "Please fill the options we give you",
                                 QMessageBox::Ok);
    }
    else {
        // getting strings
        // conveting from QString to std::string
        std::string utf8_os = os_btn->text().toUtf8().constData();

        std::string utf8_drinks;
        // in case no button was checked
        bool not_checked = true;
        for(auto& b : drinks_buttons)
        {
            if(b->isChecked()){
                utf8_drinks += b->text().toUtf8().constData();
                utf8_drinks += " ";
                not_checked = false;
            }
        }
        if(not_checked){
            QMessageBox::critical(this, "Ops", "Please fill the we options give you",
                                     QMessageBox::Ok);
        } else {
            std::string utf8_pet = pet_btn->text().toUtf8().constData();

            // storing the requested data
            data.push_back(utf8_os);
            data.push_back(utf8_drinks);
            data.push_back(utf8_pet);

            // showing data in debugger
            qDebug() << "DATA TO STORE: ";
            for(auto& e : data)
            {
                qDebug() << QString::fromUtf8(e.c_str()) << " | ";
            }
        }
    }
}
