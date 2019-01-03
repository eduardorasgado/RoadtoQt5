#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), labelFont{"Times", 16, QFont::Thin}
{
    //adding form
    createForm();
    //signals and slots
    connectingSignalsAndSlots();
}

Widget::~Widget()
{
    delete firstNameLabel;
    delete lastNameLabel;
    delete cityLabel;
    delete firstNameLineEdit;
    delete lastNameLineEdit;
    delete cityLineEdit;
    delete submitBtn;

}

QSize Widget::sizeHint() const
{
    return QSize(400, 200);
}

void Widget::createForm()
{
    createLabels();
    createLineEdits();
    submitButton();
}

void Widget::createLabels()
{
    // First name
    firstNameLabel = new QLabel("First name:", this);
    firstNameLabel->setMinimumSize(70, 50);
    firstNameLabel->setFont(labelFont);
    firstNameLabel->move(10,10);

    //last name
    lastNameLabel = new QLabel("Last name:", this);
    lastNameLabel->setMinimumSize(70, 50);
    lastNameLabel->setFont(labelFont);
    lastNameLabel->move(10,40);

    cityLabel = new QLabel("City:", this);
    cityLabel->setMinimumSize(70, 50);
    cityLabel->setFont(labelFont);
    cityLabel->move(10, 70);
}

void Widget::createLineEdits()
{
    // adding an input for label
    firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200, 20); //box size
    firstNameLineEdit->move(110, 22);
    firstNameLineEdit->setPlaceholderText("Eduardo");

    //lastName
    lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200, 20);
    lastNameLineEdit->move(110, 54);
    lastNameLineEdit->setPlaceholderText("Rasgado Ruiz");

    // city line edit
    cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200, 20);
    cityLineEdit->move(110, 86);
    cityLineEdit->setPlaceholderText("Oaxaca, MX");
}

void Widget::submitButton()
{
    submitBtn = new QPushButton("Save", this);
    submitBtn->setFont(labelFont);
    submitBtn->move(150, 118);
}

void Widget::connectingSignalsAndSlots()
{
    getForm();
    // all line signals
    for(auto signal : {firstNameLineEdit, lastNameLineEdit, cityLineEdit})
    {
        lineSignal(signal);
    }
}

void Widget::getForm()
{
    // connecting button and capturing form data
    connect(submitBtn, &QPushButton::clicked,[=](){
        // messages
        //QString validation_msgs[3];
        std::vector<QString> validation_msgs;

        auto firstname = firstNameLineEdit->text();
        auto lastName = lastNameLineEdit->text();
        auto city = cityLineEdit->text();

        validatingFormData(firstname, lastName, city, validation_msgs);

        // in case all data is well set
        if( validation_msgs.size() == 0)
        {
            qDebug() << "firstname: " << firstname << "| lastname: " << lastName << " | city: " << city;
            QMessageBox::information(this, "Welcome", "Your data is saved.",
                                     QMessageBox::Ok);

            // TODO: cleaning the inputs
        }
        else {
            // in case something is empty, show msg
            for(auto &msg : validation_msgs)
            {
                qDebug() << "NOT SET: " << msg;
                QMessageBox::critical(this, "Not Set", "Please fill the "+msg+" data input",
                                      QMessageBox::Ok);
            }
        }
    });
}

void Widget::validatingFormData(QString& firstname, QString& lastName,
                        QString& city, std::vector<QString> &validation_msgs)
{
    // validator
    auto validateString = [](auto data)->bool{
        if(data.isEmpty()) { return false; }
        return true;
    };

    // validating first name
    auto v_firstname = validateString(firstname);
    if(!v_firstname)
    { validation_msgs.push_back("FirstName"); }

    // validating lastName
    auto v_lastname = validateString(lastName);
    if(!v_lastname) { validation_msgs.push_back("LastName"); }

    // validating city
    auto v_city = validateString(city);
    if(!v_city) { validation_msgs.push_back("City"); }
}

void Widget::lineSignal(QLineEdit *signal)
{
    // Resnpond to signals from QQLineEdit
    // cursorPositionChanged
    connect(signal, &QLineEdit::cursorPositionChanged, [=](){
        qDebug() << "The current cursor position is: " << signal->cursorPosition();
    });

    // editingFinished: emmited when user clicks enter or when line edit looses focus
    connect(signal, &QLineEdit::editingFinished, [=](){
        qDebug() << signal->text() << " in line.";
    });

    // when enter is pressed in an input
    connect(signal, &QLineEdit::returnPressed, [=](){
        qDebug() << "[Return Pressed].";
    });

    // when change between inputs
    connect(signal, &QLineEdit::selectionChanged,[=](){
        qDebug() << "[[Selection changed]]";
    });

    connect(signal, &QLineEdit::textChanged, [=](){
        qDebug() << "Text actually is: " << signal->text();
        // taking actual text and replace space to -
        signal->setText(signal->text().replace(" ", "-"));
    });
    /* others:
     *
     * textEdited
    */
}
