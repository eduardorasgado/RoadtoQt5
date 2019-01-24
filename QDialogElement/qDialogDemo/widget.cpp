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
    delete dialog;
    delete ui;
}

void Widget::on_pushButton_provideinfo_clicked()
{
     dialog = new InfoDialog(this);
     // show a dialog as a modal dialog
     auto response = dialog->exec();
     if(response == QDialog::Accepted)
     {
         //
         QString position = dialog->getPosition();
         QString os = dialog->getFavorite_os();
         qDebug() << "Dialog accepted, position is: "
                  << position
                  << " | os is: "
                  << os;
     }
     if(response == QDialog::Rejected)
     {
         qDebug() << "Dialog rejected";
     }
}
