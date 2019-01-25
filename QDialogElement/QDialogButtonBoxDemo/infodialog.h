#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QDebug>
#include <QDialogButtonBox>
#include <QMessageBox>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    QString getDial_content() const;

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    QString dial_content;
    Ui::InfoDialog *ui;
    void DialogbuttonBoxHandler(QDialogButtonBox::StandardButton&);
};

#endif // INFODIALOG_H
