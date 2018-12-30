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
    void on_startServerButton_clicked();

private:
    Ui::Widget *ui;
    u_int16_t port;
    std::string address;
    std::string message;

    void startServer();
};

#endif // WIDGET_H
