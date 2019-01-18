#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include <memory>
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

private:
    Ui::Widget *ui;
    QButtonGroup *b_group;
    QButtonGroup *b_drink_group;
    std::vector<QCheckBox*> *btns;
    void initBox();
    void initButtons();
    void initSignals();
};

#endif // WIDGET_H
