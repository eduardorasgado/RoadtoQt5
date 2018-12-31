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
    message.setDefaultButton(QMessageBox::Cancel);

}

void MainWindow::addMenubar()
{
    // Add menus
    auto filemenu = menuBar()->addMenu("File");
    filemenu->addAction(quitAction);

    menuBar()->addMenu("Edit");
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
    // Quit action
    quitAction = new QAction("Quit");

    // connecting the action with slot and signal
    connect(quitAction, &QAction::triggered,[=](){
        // close the app
        QApplication::quit();
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
