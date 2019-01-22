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
        // closing app with a delay
        // status bar comes with window
        auto time = 3000;
        statusBar()->showMessage("App will close in "
                                 + QString::number(time/1000)
                                 +" secs.");
        QTimer::singleShot(time, this, SLOT(quitApp()));
    }
}

void MainWindow::on_actionCopy_triggered()
{
    // select text then copy
    //qDebug() << "Copy action triggered";
    auto text = ui->textEdit->toPlainText();
    auto words = text.split(" ");

    ui->textEdit->selectAll();
    ui->textEdit->copy();

    // show a message for 2 secs
    statusBar()->showMessage("Text copied. ("
                             + QString::number(words.count())
                             +") word(s) were copied", 2000);
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

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionAbout_triggered()
{
    // show a about message
    QMessageBox::about(this, "EasyPad 1.0 2019", "This is a notepad like app"
                             ", to learn how to create menus and window "
                             "customization");
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::quitApp()
{
    QApplication::quit();
}
