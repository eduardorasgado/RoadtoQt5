#include "rockwidget.h"
#include <QLabel>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
  // tocreate we extended from qwdget and add qObject too
{
    // constructor
    //setWindowTitle("Rock App");

    auto label =new QLabel("This is my label", this);
}
