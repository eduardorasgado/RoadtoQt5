#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    bool ok;
    // getting data from user using a dialog
    auto data = QInputDialog::getDouble(this,
                                        // title
                                        tr("Set some data"),
                                        // input label
                                        tr("Max Speed"),
                                        // default data, min, max
                                        37.56,
                                        -10000,
                                        11000,
                                        // decimal precision
                                        2,
                                        &ok);
    if(ok){
        qDebug() << "Max Speed: " << QString::number(data);
    }
}

void Widget::on_pushButton_2_clicked()
{
    // item selector input
    QStringList items_to_append;
    items_to_append.append("Blue Left corner");
    items_to_append.append("Blue Center");
    items_to_append.append("Blue Righ Corner");
    items_to_append.append("Red Left corner");
    items_to_append.append("Red Center");
    items_to_append.append("Red Righ Corner");

    bool ok;
    QString item = QInputDialog::getItem(this,
                                         tr("Select one robot position"),
                                         tr("Match Position"),
                                         items_to_append,
                                         0, false, &ok);
    if(ok && !item.isEmpty()){
        qDebug() << "ACTUAL POSITION IS: " << item.toUtf8();
    }
}
