#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    void on_pushButton_capture_val_clicked();

    void on_pushButton_set_val_clicked();

private:
    Ui::Widget *ui;
    void initComboBox();
};

#endif // WIDGET_H
