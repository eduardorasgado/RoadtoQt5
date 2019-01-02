#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    QFont labelFont;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;

    QSize sizeHint() const;
    void createForm();
    void createLabels();
    void createLineEdits();
};

#endif // WIDGET_H
