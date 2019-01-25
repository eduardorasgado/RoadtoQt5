#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "infodialog.h"
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_dialog_clicked();

private:
    InfoDialog *dialog;
    Ui::Widget *ui;
    void initDialogBoxes();
};

#endif // WIDGET_H
