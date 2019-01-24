#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setLabelData();
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
         setLabelData(position, os);
     }
     if(response == QDialog::Rejected)
     {
         qDebug() << "Dialog rejected";
         // no data
         auto nodata = "<No Data Assigned>";
         setLabelData(nodata, nodata);
     }
}

void Widget::setLabelData(QString pos, QString os)
{
    ui->label_position->setText(pos);
    ui->label_os->setText(os);
}

