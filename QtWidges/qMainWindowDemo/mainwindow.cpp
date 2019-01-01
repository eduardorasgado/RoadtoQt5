#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction> // quit action
#include <QApplication> // contents all interaction witl app

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // title
    this->setWindowTitle("My Application");

    // --calling initializer methods--
    addCentralWidget();
    // declaring actions with qaction
    initActions();
    addMenubar();
    initStatusBar();
    initSignalsAndSlots();

}

MainWindow::~MainWindow()
{
    // deleting all the pointers
    delete button1;
    delete quitAction;
    delete msgAction;
    delete msg2Action;
}

QSize MainWindow::sizeHint() const
{
    // size of the window, this method is called automatically
    return QSize(500, 200);
}

void MainWindow::addCentralWidget()
{
    // Adding a central widget
    button1 = new QPushButton("Click me", this);
    setCentralWidget(button1);

    // Defining the custom mesage box
    message.setMinimumSize(100, 400);
    message.setWindowTitle("Attention");
    message.setText("You have clicked the push button and this occurs.");
    message.setInformativeText("Did you know?");
    message.setIcon(QMessageBox::Critical);
    //  | is a sepparator, we not use commas here
    message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    // if you click in close then default choice is cancel
    message.setDefaultButton(QMessageBox::Cancel);

    // question message box
    questionmsg.setMinimumSize(100, 400);
    questionmsg.setWindowTitle("Https is optional");
    questionmsg.setText("You can active the https protocol.");
    questionmsg.setInformativeText("If you have a ssl certificated locally"
                                   "installed you can use it for your server. Do you want"
                                   "to take it?");
    questionmsg.setIcon(QMessageBox::Question);
    questionmsg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    questionmsg.setDefaultButton(QMessageBox::Cancel);

}

void MainWindow::addMenubar()
{
    // Add menus
    auto filemenu = menuBar()->addMenu("File");
    filemenu->addAction(quitAction);
    filemenu->addAction(msgAction);

    auto editmenu = menuBar()->addMenu("Edit");
    editmenu->addAction(msg2Action);

    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");
}

void MainWindow::initStatusBar()
{
    // Add status bar message
    // the message is shown for 3 seconds
    statusBar()->showMessage("Welcome to  the app", 3000);
}

void MainWindow::initActions()
{
    // this method calls all the actions before app is already for user
    initFileMenuActions();
}

void MainWindow::initFileMenuActions()
{
    // FOR FILE MENU
    // Quit action
    quitAction = new QAction("Quit");

    // connecting the action with slot and signal
    connect(quitAction, &QAction::triggered,[=](){
        // close the app
        QApplication::quit();
    });

    msgAction = new QAction("Show a message");

    connect(msgAction, &QAction::triggered, [=](){
        // in case user click on show a message option in menu
        auto userChoise = QMessageBox::critical(this, "Title",
                                        "Something went wrong",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        if(userChoise == QMessageBox::Ok)
        {
            qDebug() << "User choise is OK(2)";
        }
        else if(userChoise == QMessageBox::Cancel)
        {
            qDebug() << "User just CANCEL it(2)";
        }
    });

    msg2Action = new QAction("Show information msg");
    // connect the action label in edit menu option to a
    // action in window
    connect(msg2Action, &QAction::triggered,[=](){
        this->largeScaleAction();
    });
}

void MainWindow::clickButton()
{
    // this is called because signal connection
    qDebug() << "Button is pressed";

    // Message box executed
    auto userElection = message.exec();

    // capturing user choise
    if(userElection == QMessageBox::Ok)
    {
        qDebug() << "User option was OK";
    }
    else if (userElection == QMessageBox::Cancel)
    {
        qDebug() << "User option was CANCEL";
    }
    else {
        qDebug() << "User Option was NOTHING";
    }
 }

// events
void MainWindow::initSignalsAndSlots()
{
    //initializing click event
    connect(button1, &QPushButton::clicked,[=](){
        this->clickButton();
    });
}

void MainWindow::largeScaleAction()
{
    // information message
    qDebug() << "A process is started";
    int ret = QMessageBox::information(this, "The server is on",
                                       "Look at your browser at localhost:8080. Do you,"
                                       "Want to keep the server on?",
                                       QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QMessageBox::Ok)
    {
        qDebug() << "Button OK was pressed in INFORMATION";
        // question message
        auto uc = questionmsg.exec();
        if(uc == QMessageBox::Ok) {
            qDebug() << "[QUESTION ANSWER: OK]";
            // warning message box
            QMessageBox::warning(this, "Ops!",
                                 "You do not have such certificates in your machine",
                                 QMessageBox::Ok);
        }
    }
}
