#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // no initial content
    ui->label_container->setText("");
    initDialogBoxes();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_dialog_clicked()
{
    // can be executed as a modal, but handled using
    // signnals and slots
    dialog->exec();
}

void Widget::initDialogBoxes()
{
    dialog = new InfoDialog(this);

    // connecting dialog signals
    connect(dialog, &InfoDialog::accepted,[=](){
        qDebug() << "Dialog Accepted";
    });

    connect(dialog, &InfoDialog::rejected, [=](){
        qDebug() << "Dialog Rejected";
    });
}
