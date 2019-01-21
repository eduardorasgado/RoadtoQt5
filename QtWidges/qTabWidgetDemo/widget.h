#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QButtonGroup>

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
    void on_button_tab1_select_clicked();

private:
    Ui::Widget *ui;
    QButtonGroup *p_languages_group;

    void initGroupBoxes();
};

#endif // WIDGET_H
