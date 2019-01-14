#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initH2BoxLayout();
    initV2BoxLayout();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initH2BoxLayout()
{
    // we can do the same for QVBoxLayout

    // make easy to handle buttons in layout
    h2_layout = new QHBoxLayout();

    std::vector<QWidget*> btns = std::vector<QWidget*>
                            {ui->cutButton, ui->copyButton,
                            ui->pasteButton, ui->writeButton, ui->loadButton};

    // adding the buttons to the layout
    for(auto& b : btns)
    {
        h2_layout->addWidget(b);
    }

    setLayout(h2_layout);

}

void Widget::initV2BoxLayout()
{
    //
}
