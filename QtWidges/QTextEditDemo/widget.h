#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QFont textFont;
    QLabel *mLabel;
    QTextEdit *textEdit;

    void initLabels();
    void initText();
    QSize sizeHint() const;
};

#endif // WIDGET_H
