#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QDebug>
#include <QDialogButtonBox>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::InfoDialog *ui;
    void DialogbuttonBoxHandler(QDialogButtonBox::StandardButton&);
};

#endif // INFODIALOG_H
