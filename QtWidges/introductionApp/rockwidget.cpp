#include "rockwidget.h"
#include <QLabel>
#include <QFont>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
  // tocreate we extended from qwdget and add qObject too
{
    // constructor
    //setWindowTitle("Rock App");

    // adding a label with new
    auto label =new QLabel("This is my label", this);
    auto label2 = new QLabel(this);
    label2->setText("Is is a colored label");

    // add a styled widget and move it around
    QFont labelFont("Times", 14, QFont::Bold);

    QPalette labelPallete1;
    labelPallete1.setColor(QPalette::Window, Qt::yellow);
    labelPallete1.setColor(QPalette::WindowText, Qt::blue);

    // fonts
    label->setFont(labelFont);
    label2->setFont(labelFont);

    // set palettes
    label->setPalette(labelPallete1);
    label->setAutoFillBackground(true);

    // label position
    label2->move(0, 100);

}

QSize RockWidget::sizeHint() const
{
    // this method is called by the system
    return QSize(500, 500);
}
