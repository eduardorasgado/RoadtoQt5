#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

// added using go to slot in ui
void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton =
            ui->buttonBox->standardButton(button);

    for(auto& b : { QDialogButtonBox::Save,
                    QDialogButtonBox::Cancel,
                    QDialogButtonBox::Reset,
                    QDialogButtonBox::Help})
    if(stdButton == b)
    {

        qDebug() << b << " button clicked";
    }

    // handling what button user clicked
    DialogbuttonBoxHandler(stdButton);
}

void InfoDialog::DialogbuttonBoxHandler(QDialogButtonBox::StandardButton &b)
{
    //
    if(b == QDialogButtonBox::Save){
        accept();
    }
    else if(b == QDialogButtonBox::Cancel){
        reject();
    }
    else if(b == QDialogButtonBox::Reset){
        qDebug() << "reset button";
    }
    else if(b == QDialogButtonBox::Help){
        qDebug() << "Help button";
    }
}
