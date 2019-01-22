#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    // slot connected from ui designer bye right click
    // the quit action in actions list
    auto confirm = QMessageBox::question(this, "Clossing app",
                                         "You are about to close your work, "
                                         "are you sure?",
                                         QMessageBox::Ok | QMessageBox::No);
    if(confirm == QMessageBox::Ok){
        QApplication::quit();
    }
}

void MainWindow::on_actionCopy_triggered()
{
    // select text then copy
    qDebug() << "Copy action triggered";
    ui->textEdit->selectAll();
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->selectAll();
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}