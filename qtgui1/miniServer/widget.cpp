#include "widget.h"
#include "ui_widget.h"
// include restinio from conan
// restinio is a web services and real time library for C++
#include "restinio/all.hpp"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget), port{8080}, address{"localhost"}
{
    ui->setupUi(this);
    message = "[QT AND RESTINIO SERVER IS ON]";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startServerButton_clicked()
{
    // button is deactivate
    ui->startServerButton->setDisabled(true);

    // message server is started
    QMessageBox::information(this, "Server is on",
                             "Your server is at localhost:8080.",
                             QMessageBox::Ok);
    // calling the server initializer
    startServer();
}

void Widget::startServer()
{
    // start restinio server
    std::string msg = message;
    // server will start
    try {
        restinio::run(restinio::on_this_thread()
                      .port(port)
                      .address(address)
                      .request_handler([msg](auto req){
            return req->create_response()
                    // server will serve a simple custom string
                    .set_body(msg)
                    .done();
        }));
        //HOW TO CLOSE THE SERVER ???
    } catch (std::exception& e) {
        QMessageBox::information(this, "Server is off",
                                 "Closed unespectely.",
                                 QMessageBox::Ok);

    }
}
