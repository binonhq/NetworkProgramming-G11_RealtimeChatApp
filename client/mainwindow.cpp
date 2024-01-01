#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&client, SIGNAL(loginSuccess(QString)), this, SLOT(login_success(QString)));
    connect(&client, SIGNAL(loginFailure()), this, SLOT(login_failure()));
    connect(&registerDialog, SIGNAL(registerReq(QString,QString)), this, SLOT(register_request(QString,QString)));
    connect(&client, SIGNAL(registerSuccess()), &registerDialog, SLOT(register_success()));
    connect(&client, SIGNAL(registerFailure()), &registerDialog, SLOT(register_failure()));
    connect(&chatClient, SIGNAL(logOut(QString)), this, SLOT(log_out(QString)));
    connect(&registerDialog, SIGNAL(logIn()), this, SLOT(show_main()));
    connect(&client, SIGNAL(getActiveUsers(QString)), &chatClient, SLOT(get_active_users(QString)));
    connect(&chatClient, SIGNAL(sendPrivateMessage(QString)), this, SLOT(send_private_chat(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_register_clicked()
{
    hide();
    registerDialog.show();
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    client.SendRequest("LOGIN", username, password);
}

void MainWindow::login_success(QString username){
    QMessageBox::information(this, "Login success", "Log in successful!");
    hide();
    chatClient.set_username(username);
    chatClient.show();
}

void MainWindow::login_failure(){
    QMessageBox::information(this, "Login failure", "Log in failure! Check your username and password!");
}

void MainWindow::register_request(QString username, QString password){
    client.SendRequest("SIGNUP", username, password);
}

void MainWindow::show_main(){
    this->show();
}

void MainWindow::log_out(QString username){
    client.SendRequest("LOGOUT", username, "");
    this->show();
}

void MainWindow::send_private_chat(QString message){
    client.SendRequest("PRIVATE", chatClient.receiver, message);
}


