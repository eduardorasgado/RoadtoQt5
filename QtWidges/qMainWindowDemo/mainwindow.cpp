#include "mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // title
    this->setWindowTitle("My Application");

    // calling initializer methods
    addCentralWidget();
    addMenubar();
    initStatusBar();
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
    auto button = new QPushButton("Click me", this);
    setCentralWidget(button);
}

void MainWindow::addMenubar()
{
    // Add menus
    menuBar()->addMenu("File");
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

