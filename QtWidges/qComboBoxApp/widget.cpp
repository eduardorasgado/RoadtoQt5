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
    // adding fixed items to combo box
    ui->comboBox->addItem("Linux");
    ui->comboBox->addItem("Windows");
    ui->comboBox->addItem("Mac OS");
    ui->comboBox->addItem("Free BSD");
    ui->comboBox->addItem("Solaris");
    ui->comboBox->addItem("Add your own...");

    maxIndex = ui->comboBox->count();
}

void Widget::on_pushButton_capture_val_clicked()
{
    // in fixed selections
    auto comboContent = ui->comboBox->currentText();
    if(comboContent == "Add your own..."){
        // reject if customizable is not set
        QMessageBox::critical(this, "Not an Option", "Please, write your OS"
                                    " then press ENTER to save and select it.",
                              QMessageBox::Ok);
    }
    else {
        qDebug() << "The current selected is: "
                 << comboContent << ", index is: "
                 << QString::number(ui->comboBox->currentIndex());

        QMessageBox::information(this, "Your OS", "You selected: "+comboContent,
                                 QMessageBox::Ok);
    }

}

void Widget::on_pushButton_set_val_clicked()
{
    // set item programatically
    ui->comboBox->setCurrentIndex(0);
}

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //qDebug() << "Actual combo box text is: " << arg1;
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    // if it is not the user customizable then not editable
    ui->comboBox->setEditable(false);
    //qDebug() << "Actual combobox index is: " << index;
    //qDebug() << "Max is: " << maxIndex;

    // in case of users own selection
    if(index == maxIndex-1){
        // in case index is the last element->make editable

        // make the combo box able to be edited
        ui->comboBox->setEditable(true);
    }
}

void Widget::on_pushButton_get_val_clicked()
{
    qDebug() << "The combo box currently has: " <<
                QString::number(ui->comboBox->count()) << " items. They are: ";
    for(int i = 0;i < ui->comboBox->count(); ++i)
    {
        qDebug() << QString::number(i) << ": " << ui->comboBox->itemText(i);
    }
}
