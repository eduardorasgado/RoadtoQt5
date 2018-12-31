#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void changeText();
    void changeTextb2();
    void changeTextb3();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H