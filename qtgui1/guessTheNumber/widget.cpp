#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
#include <cstdlib> // to generate random numbers
#include <time.h> // to seed a generator

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget), lowerNum{1}, higherNum{10}
{
    ui->setupUi(this);
    // this is the constructor and initialize the widget class
    // so when app starts, numbers will be generated

    // It is the seeder
    srand(time(NULL));

    // generate the random number (1 - 10)
    secretNumber = rand() % 10 +1;
    // debuggin in qt console
    qDebug() << "Secret number is: " << QString::number(secretNumber);

    // show nothing in message label
    setMessage(" ");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    // assigning the spinbox number selected when button is clicked, to
    // guessNumber
    guessNumber = ui->spinBox->value();
    // debugging the output
    qDebug() << "Guess number is: " << QString::number(guessNumber);
    if(guessNumber != secretNumber)
    {
        if(secretNumber > guessNumber){
            ui->messageLabel->setText("Number is greater than that.");
        }
        else if(secretNumber < guessNumber)
        {
            ui->messageLabel->setText("Number is lower than that.");
        }
    }
    else
    {
        // Congrats message
        QMessageBox::information(this, "All right!", "You did it well",
                                 QMessageBox::Ok);
        setMessage("Click Start Over to play again :)");
    }
}

void Widget::on_startOverButton_clicked()
{
    //
}

void Widget::setMessage(QString message)
{
    ui->messageLabel->setText(message);
}
