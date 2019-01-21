#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initGroupBoxes();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_button_tab1_select_clicked()
{
    qDebug() << "Select";
    if(p_languages_group->checkedButton()){
        // if radio button is checked
        qDebug() << "Programming language is: "
                 << p_languages_group->checkedButton()->text();
    }
}

void Widget::initGroupBoxes()
{
    p_languages_group = new QButtonGroup(this);
    p_languages_group->addButton(ui->radioButton_cpp);
    p_languages_group->addButton(ui->radioButton_java);
    p_languages_group->addButton(ui->radioButton_python);
    p_languages_group->addButton(ui->radioButton_labview);
}
