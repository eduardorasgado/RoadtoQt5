#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // parent widget, caption, directory, options
    auto directory = QFileDialog::getExistingDirectory(this,
                                                       tr("Open directory"),
                                                       "/home",
                                                       QFileDialog::ShowDirsOnly
                                                       | QFileDialog::DontResolveSymlinks);
    if(directory != ""){
        qDebug() << "DIRECTORY: " << directory;
    }
}

void Widget::on_pushButton_2_clicked()
{
    // get file
    // in this case we can select in base of the list of Image extensions
    auto file = QFileDialog::getOpenFileName(this, tr("Open a file"),
                                             "/home",
                                             tr("Images (*.png *.xpm *.jpg)"));
    if(file != ""){
        qDebug() << "FILE: " << file;
    }
}

void Widget::on_pushButton_3_clicked()
{
    // getting one or more files at the same time
    QStringList files = QFileDialog::getOpenFileNames(
                this, "Select one or more files to open",
                "/home", "Images (*.png *.xml *.jpg)");
    if(files.count() > 0){
        qDebug() << "FILE: " << files;
    }
}
