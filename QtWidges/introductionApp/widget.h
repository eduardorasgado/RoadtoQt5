#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

// QWidget has all the qt window features
// we need to develop cross platform
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void showMessage();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
