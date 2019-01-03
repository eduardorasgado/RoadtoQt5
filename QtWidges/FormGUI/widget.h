#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <vector>
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QFont labelFont;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *cityLabel;
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *cityLineEdit;
    QPushButton *submitBtn;

    QSize sizeHint() const;
    void createForm();
    void createLabels();
    void createLineEdits();
    void submitButton();
    void connectingSignalsAndSlots();
    void getForm();
    void validatingFormData(QString& firstname, QString& lastName,
                            QString& city, std::vector<QString> &validation_msgs);
    void lineSignal(QLineEdit *signal);
};

#endif // WIDGET_H
