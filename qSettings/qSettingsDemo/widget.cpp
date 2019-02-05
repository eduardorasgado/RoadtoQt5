#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initButtonList();
    setDefaultColors();
}

Widget::~Widget()
{
    delete buttonList;
    delete ui;
}

void Widget::on_pushButton1_clicked()
{
    auto position = 0;
    getNewColor(position);
}

void Widget::on_pushButton2_clicked()
{
    auto position = 1;
    getNewColor(position);
}

void Widget::on_pushButton3_clicked()
{
    auto position = 2;
    getNewColor(position);
}

void Widget::on_pushButton4_clicked()
{
    auto position = 3;
    getNewColor(position);
}

void Widget::on_pushButton5_clicked()
{
    auto position = 4;
    getNewColor(position);
}

void Widget::on_pushButton6_clicked()
{
    auto position = 5;
    getNewColor(position);
}

void Widget::on_pushButton7_clicked()
{
    auto position = 6;
    getNewColor(position);
}

void Widget::on_pushButton8_clicked()
{
    auto position = 7;
    getNewColor(position);
}

void Widget::on_pushButton9_clicked()
{
    auto position = 8;
    getNewColor(position);
}

void Widget::on_pushButton_saveColors_clicked()
{
    // call persistence logic for all buttons
    for(auto &b : {1,2,3,4,5,6,7,8,9}){
        auto buttonName = QString("pushButton%1").arg(b);

        if(b == 1){
            saveColor(buttonName, colorList[b-1]);
        }
        //qDebug() << buttonName;
    }
}

void Widget::on_pushButton_loadColors_clicked()
{
    // load colors
}

void Widget::setDefaultColors()
{
    for(auto i : {1,2,3,4,5,6,7,8,9}){
        // fill list with buttons number of elements and black color
        // as value
        colorList.push_back(Qt::black);
    }

    for(auto &c : colorList){
        qDebug() << c;
    }

}

void Widget::initButtonList()
{
    // allocating all buttons in a dynamic list
    // to enhace button handling
    buttonList = new QList<QWidget*>();

    buttonList->push_back(ui->pushButton1);
    buttonList->push_back(ui->pushButton2);
    buttonList->push_back(ui->pushButton3);
    buttonList->push_back(ui->pushButton4);
    buttonList->push_back(ui->pushButton5);
    buttonList->push_back(ui->pushButton6);
    buttonList->push_back(ui->pushButton7);
    buttonList->push_back(ui->pushButton8);
    buttonList->push_back(ui->pushButton9);
}

void Widget::getNewColor(int &position)
{
    // getting new color
    QColor color = QColorDialog::getColor(colorList[position],
            this, "Choose Background Color");
    if(color.isValid()){
        // assigning new color to list
        colorList[position] = color;

        // show color to button
        // deffining a stylesheet property
        QString css = QString("background-color: %1")
                // .name return name in RGB format
                .arg(color.name());

        buttonList->at(position)->setStyleSheet(css);
    }
}

void Widget::saveColor(QString key, QColor color)
{
    // grabbing g, r, b
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    // data persistence
    // company name, application name
    QSettings color_settings(companyName, applicationName);

    color_settings.beginGroup(buttonGroupName);
    // doing all the persistence thing
    color_settings.setValue(key + "r", red); // name("button1r"), color
    color_settings.setValue(key + "g", green);
    color_settings.setValue(key + "b", blue);

    color_settings.endGroup();
}

QColor Widget::loadColor(QString)
{

}
