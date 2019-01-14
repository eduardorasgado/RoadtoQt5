#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->imageLabel->setText("");
    // Add an image to the minion label
    initImageResources();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initImageResources()
{

    int new_width = static_cast<int>(minionPixmap.width() / 2);
    int new_height = static_cast<int>(minionPixmap.height() / 2);

    // redefine the minion image size
    minionPixmap = minionPixmap.scaled(new_width, new_height);

    ui->imageLabel->move(0, 70);
    ui->imageLabel->setPixmap(minionPixmap);
    // redifine the label size
    ui->imageLabel->setMinimumSize(minionPixmap.size());
}
