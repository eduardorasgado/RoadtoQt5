#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initComboBox();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initComboBox()
{
    ui->comboBox->addItem("Linux");
    ui->comboBox->addItem("Windows");
    ui->comboBox->addItem("Mac OS");
    ui->comboBox->addItem("Free BSD");
    ui->comboBox->addItem("Solaris");
}

void Widget::on_pushButton_capture_val_clicked()
{
    auto comboContent = ui->comboBox->currentText();
    qDebug() << "The current selectedd is: "
             << comboContent << ", index is: "
             << QString::number(ui->comboBox->currentIndex());

    QMessageBox::information(this, "Your OS", "You selected: "+comboContent,
                             QMessageBox::Ok);

}

void Widget::on_pushButton_set_val_clicked()
{
    // set item programatically
    ui->comboBox->setCurrentIndex(0);
}
