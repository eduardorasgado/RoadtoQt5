#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>

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
    void on_button_add_assignment_clicked();

    void on_button_form_cancel_clicked();

    void on_button_save_form_clicked();

    void on_button_delete_assignment_clicked();

private:
    Ui::Widget *ui;
    void initUI();

    void closeCreationForm();
    void showButtons(bool);
    QString createMessage(QList<QListWidgetItem*>);
};

#endif // WIDGET_H
