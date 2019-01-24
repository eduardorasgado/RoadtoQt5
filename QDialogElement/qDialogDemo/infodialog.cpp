#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    // we added both Qt options to avoid the appearing of a
    // interrogant symbol in window, when app is running in windows OS
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::InfoDialog)
{
    qDebug() << "Creating a dialog";
    ui->setupUi(this);
    // to have a better way to handle the radio buttons
    os_group = new QButtonGroup(this);
    os_group->addButton(ui->radioButton_windows);
    os_group->addButton(ui->radioButton_linux);
    os_group->addButton(ui->radioButton_mac);

    this->setWindowTitle("Your data");
}

InfoDialog::~InfoDialog()
{
    qDebug() << "Deleting the dialog";
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
        //qDebug() << "info is: " << position << " | " << favorite_os;
    }

    // to avoid keepin last dialog window info
    clearFields();
    // when clicking ok quit the dialog
    accept();
}

void InfoDialog::on_pushButton_cancel_clicked()
{
    // the dialog has been rejected
    reject();
}

void InfoDialog::clearFields()
{
    qDebug() << "Clearing data fields...";
    ui->lineEdit_position->clear();
    // deactivate exclussiveness for a while
    // and unchecking elements
    QAbstractButton *checked = os_group->checkedButton();
    if(checked)
    {
        os_group->setExclusive(false);
        checked->setChecked(false);
        os_group->setExclusive(true);
    }

}

QString InfoDialog::getPosition() const
{
    return position;
}

QString InfoDialog::getFavorite_os() const
{
    return favorite_os;
}
