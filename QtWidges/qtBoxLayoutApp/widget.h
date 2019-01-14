#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>

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
    QHBoxLayout *h2_layout;
    QVBoxLayout *v2_layout;

    void initH2BoxLayout();
    void initV2BoxLayout();
};

#endif // WIDGET_H
