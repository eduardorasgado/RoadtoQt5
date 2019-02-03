#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // to be able to fill background label
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_textcolor_clicked()
{
    // we select a default color for choosenCOlor dialog
    QPalette palette = ui->label->palette();
    // sustracting the actual label color from palette
    QColor color = palette.color(QPalette::WindowText);

    // dialog takes label color by default
    QColor choosenColor = QColorDialog::getColor(color,
                                                 this,
                                                 "Choose text color");
    // in case color is in range of colors
    if(choosenColor.isValid()){
        // now we can change the label palette color by calling the
        // palette already created and just adding the new color
        // this helps us to avoid making another copy of label palette
        // again
        palette.setColor(QPalette::WindowText, choosenColor);
        // setting the new properties to label
        ui->label->setPalette(palette);
        qDebug() << "User choose a valid color";
    } else {
        qDebug() << "User choose a INVALID color";
    }
}

void Widget::on_pushButton_background_color_clicked()
{
    //
}

void Widget::on_pushButton_font_clicked()
{
    //
}
