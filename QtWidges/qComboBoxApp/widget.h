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

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_get_val_clicked();

private:
    Ui::Widget *ui;
    int maxIndex;
    void initComboBox();
};

#endif // WIDGET_H
