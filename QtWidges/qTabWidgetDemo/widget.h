#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QPushButton>
#include <QList>

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
    QWidget *widget_tab4;
    QVBoxLayout *layout_tab4;
    QButtonGroup *p_languages_group;
    QList<QWidget*> *new_widgets; // to store custom widgets
    QList<QVBoxLayout*> *new_layouts; // for custom widgets

    void initGroupBoxes();
    void initTabInCode();
};

#endif // WIDGET_H
