#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    // to have a better way to handle the radio buttons
    os_group = new QButtonGroup(this);
    os_group->addButton(ui->radioButton_windows);
    os_group->addButton(ui->radioButton_linux);
    os_group->addButton(ui->radioButton_mac);
}

InfoDialog::~InfoDialog()
{
    delete os_group;
    delete ui;
}

void InfoDialog::on_pushButton_ok_clicked()
{
    // capturing the information
    QString userPosition = ui->lineEdit_position->text();
    if(!userPosition.isEmpty())
    {
        position= userPosition;

        if(os_group->checkedButton())
        {
            favorite_os = os_group->checkedButton()->text();
        }
        qDebug() << "info is: " << position << " | " << favorite_os;
    }

    // when clicking ok quit the dialog
    accept();
}

void InfoDialog::on_pushButton_cancel_clicked()
{
    // the dialog has been rejected
    reject();
}
