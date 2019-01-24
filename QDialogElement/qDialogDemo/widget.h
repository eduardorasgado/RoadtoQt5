#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "infodialog.h" // we should include the dialog manually
#include <QDebug>

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
    void on_pushButton_provideinfo_clicked();

    void on_pushButton_provide_nonmodal_clicked();

private:
    Ui::Widget *ui;
    InfoDialog *dialog;
    InfoDialog *dialog_non_modal;
    void initDialogs();
    void setLabelData(QString pos="", QString os="");
};

#endif // WIDGET_H
