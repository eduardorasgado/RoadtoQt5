#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *button;
    QPushButton *button2;
    QFont buttonFont;

    void initGeneralButtons();
    void signalSlotsConnections();
    QSize sizeHint() const;
};

#endif // WIDGET_H
