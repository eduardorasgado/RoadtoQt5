#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QButtonGroup>
#include <QDebug>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    QString getFavorite_os() const;

    QString getPosition() const;

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::InfoDialog *ui;

    QString position;
    QString favorite_os;
    QButtonGroup *os_group;
};

#endif // INFODIALOG_H
