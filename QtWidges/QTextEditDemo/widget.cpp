#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), textFont{"Times", 10, QFont::Bold}
{
    buttons = std::make_shared<std::vector<QPushButton*>>();
    initLabels();
    initButtons();
    initText();

    // signals and slots
    initSignalsAndSlots();

    // avoiding to change the window size
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
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
    buttons->push_back(new QPushButton("Copy", this));
    buttons->at(0)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(0)->move(10, 260);

    // cut
    buttons->push_back(new QPushButton("Cut", this));
    buttons->at(1)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(1)->move(110, 260);

    // paste
    buttons->push_back(new QPushButton("Paste", this));
    buttons->at(2)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(2)->move(210, 260);

    // undo
    buttons->push_back(new QPushButton("Undo", this));
    buttons->at(3)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(3)->move(10, 300);

    // redo
    buttons->push_back(new QPushButton("Redo", this));
    buttons->at(4)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(4)->move(110, 300);

    // Html
    buttons->push_back(new QPushButton("Html", this));
    buttons->at(5)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(5)->move(210, 300);

    // Plain text
    buttons->push_back(new QPushButton("Plain Text", this));
    buttons->at(6)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(6)->move(10, 340);

    // Grab text
    buttons->push_back(new QPushButton("Grab Text", this));
    buttons->at(7)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(7)->move(110, 340);

    // Grab HTML
    buttons->push_back(new QPushButton("Grab HTML", this));
    buttons->at(8)->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    buttons->at(8)->move(210, 340);

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
    connect(buttons->at(0), &QPushButton::clicked, [=](){
        textEdit->selectAll();
        textEdit->copy();
    });

    // cut button
    connect(buttons->at(1), &QPushButton::clicked, [=](){
        textEdit->cut();
    });

    // past button
    connect(buttons->at(2), &QPushButton::clicked, [=](){
        textEdit->paste();
    });

    // undo button
    connect(buttons->at(3), &QPushButton::clicked, [=](){
        textEdit->undo();
    });
    // redo button
    connect(buttons->at(4), &QPushButton::clicked, [=](){
        textEdit->redo();
    });

    // html button
    connect(buttons->at(5), &QPushButton::clicked, [=](){
        textEdit->setHtml("<h1>Your Data:</h1><p>This is my name: <strong>Eduardo</strong></p>");
    });

    // plain text button
    connect(buttons->at(6), &QPushButton::clicked, [=](){
        textEdit->setPlainText("This is some plain text to set");
    });

    // grab plain text button
    connect(buttons->at(7), &QPushButton::clicked, [=](){
        qDebug() << "The plain text inside the text editor box is: "
               << textEdit->toPlainText();
    });

    // grab html button
    connect(buttons->at(8), &QPushButton::clicked, [=](){
        qDebug() << "The html inside the text edito is: "
                 << textEdit->toHtml();
    });
}

QSize Widget::sizeHint() const
{
    return QSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}
