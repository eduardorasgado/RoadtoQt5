#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mainMenu = new QMenuBar(this);
    initMenuActions();
    initMenu();
    initH2BoxLayout();
    initV2BoxLayout();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initMenu()
{
    mainMenu->setMinimumWidth(this->geometry().width());
    auto fileMenu = mainMenu->addMenu("File");
    fileMenu->addAction(quitAction);
    auto editMenu = mainMenu->addMenu("Edit");
    auto helpMenu = mainMenu->addMenu("Help");
}

void Widget::initMenuActions()
{
    // For file menu
    // quit action
    quitAction = new QAction("Quit");

    // connecting signals to actions
    connect(quitAction, &QAction::triggered,[=](){
        // quit the widget
        auto selection = QMessageBox::information(this, "Are you serious?", "Your are "
                                                                            "near to close this app",
                                                  QMessageBox::Ok, QMessageBox::No);
        if(selection == QMessageBox::Ok)
        {
            QApplication::quit();
        }
    });

}

void Widget::initH2BoxLayout()
{
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
    v2_layout = new QVBoxLayout();

    auto v2_btns = std::vector<QWidget*>{ui->pushButton, ui->pushButton_2,
                                        ui->pushButton_3, ui->pushButton_4,
                                        ui->pushButton_5};

    for(auto& b : v2_btns)
    {
        v2_layout->addWidget(b);
    }
    //setLayout(v2_layout);
}
