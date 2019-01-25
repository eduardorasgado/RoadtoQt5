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

QString InfoDialog::getDial_content() const
{
    return dial_content;
}

void InfoDialog::DialogbuttonBoxHandler(QDialogButtonBox::StandardButton &b)
{
    //
    if(b == QDialogButtonBox::Save){
        auto content = ui->textEdit->toPlainText(); // get content
        if(content == ""){
            QMessageBox::information(this, "Save your information",
                                     "Box is empty, write something",
                                     QMessageBox::Ok);
        } else{
            // if box is not empty
            dial_content = content;
            accept();
        }
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
