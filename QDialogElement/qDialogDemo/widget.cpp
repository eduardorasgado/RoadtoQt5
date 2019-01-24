#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setLabelData();

    // to avoid creating a lot of dialogs in the heap
    initDialogs();
}

Widget::~Widget()
{
    delete dialog;
    delete dialog_non_modal;
    delete ui;
}

void Widget::on_pushButton_provideinfo_clicked()
{
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

void Widget::on_pushButton_provide_nonmodal_clicked()
{
    // to show a dialog non modal
    dialog_non_modal->show();
    dialog_non_modal->raise();
    // to give it focus
    dialog_non_modal->activateWindow();
}

void Widget::initDialogs()
{
    // creating the dialogs
    // modal
    dialog = new InfoDialog(this);
    // non modal: works with signals
    dialog_non_modal = new InfoDialog(this);

    // signals and slots approach
    connect(dialog_non_modal, &InfoDialog::accepted, [=](){
        //
        qDebug() << "[Dialog non modal was accepted]";
        auto position = dialog_non_modal->getPosition();
        auto os = dialog_non_modal->getFavorite_os();

        this->setLabelData(position, os);
    });
    connect(dialog_non_modal, &InfoDialog::rejected, [=](){
        //
        qDebug() << "[Dialog non modal was rejected]";
    });
}

void Widget::setLabelData(QString pos, QString os)
{
    ui->label_position->setText(pos);
    ui->label_os->setText(os);
}


