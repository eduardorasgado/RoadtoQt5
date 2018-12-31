#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // set the title to the program
    this->setWindowTitle("Signals and Slots demo App");

    // Connecting signals and slots

    // String notation
    // the signal is when the value change
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            // the object we want to affect, and how we affects
            ui->progressBar, SLOT(setValue(int)));

    // Functor notation: Regular slots
    // who we will interact with, the location of that object's method
    connect(ui->horizontalSlider_2, &QSlider::valueChanged,
            // who is affected with first action
            // the object which owns the action,  the action we are affecting the last
            ui->progressBar_2, &QProgressBar::setValue);

    // Lambda Functor notation
    // in the lamda we pass =, ui is pass inside the function scope, auto range is
    // the params is taking from horizontal slider
    connect(ui->horizontalSlider_3, &QSlider::valueChanged, [=](auto range){
        ui->progressBar_3->setValue(range);
        // if we do not want to add auto rangem we can just left param values void and
        // just write
        //ui->progressBar_3->setValue(ui->horizontalSlider_3->value());
    });
}

Widget::~Widget()
{
    delete ui;
}
