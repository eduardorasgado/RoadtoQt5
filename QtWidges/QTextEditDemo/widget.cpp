#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), textFont{"Times", 10, QFont::Bold}
{
    initLabels();
    initButtons();
    initText();

    // signals and slots
    initSignalsAndSlots();
}

Widget::~Widget()
{

}

void Widget::initLabels()
{
    mLabel = new QLabel("Edit your thing here: ", this);
    mLabel->setFont(textFont);
    mLabel->move(100, 25);
}

void Widget::initButtons()
{
    // copy
    buttons.push_back(new QPushButton("Copy", this));
    buttons.at(0)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons.at(0)->move(10, 260);

    // cut
    buttons.push_back(new QPushButton("Cut", this));
    buttons.at(1)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons.at(1)->move(110, 260);

    // paste
    buttons.push_back(new QPushButton("Paste", this));
    buttons.at(2)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons.at(2)->move(210, 260);

    // undo
    buttons.push_back(new QPushButton("Undo", this));
    buttons.at(3)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons.at(3)->move(10, 300);

    // redo
    buttons.push_back(new QPushButton("Redo", this));
    buttons.at(4)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons.at(4)->move(110, 300);
}

void Widget::initText()
{
    textEdit = new QTextEdit(this);
    textEdit->move(10, 55);
}

void Widget::initSignalsAndSlots()
{
    // text changed
    connect(textEdit, &QTextEdit::textChanged, [=](){
        qDebug("Text Changed");
    });

    // copy button
    connect(buttons.at(0), &QPushButton::clicked, [=](){
        textEdit->selectAll();
        textEdit->copy();
    });

    // cut button
    connect(buttons.at(1), &QPushButton::clicked, [=](){
        textEdit->cut();
    });

    // past button
    connect(buttons.at(2), &QPushButton::clicked, [=](){
        textEdit->paste();
    });

    // undo button
    connect(buttons.at(3), &QPushButton::clicked, [=](){
        textEdit->undo();
    });
    // redo button
    connect(buttons.at(4), &QPushButton::clicked, [=](){
        textEdit->redo();
    });
}

QSize Widget::sizeHint() const
{
    return QSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}
