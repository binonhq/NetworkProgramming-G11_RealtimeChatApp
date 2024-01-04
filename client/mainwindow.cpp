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
    connect(&chatClient, SIGNAL(logOut(QString)), this, SLOT(log_out(QString)));

    connect(&registerDialog, SIGNAL(registerReq(QString,QString)), this, SLOT(register_request(QString,QString)));
    connect(&client, SIGNAL(registerSuccess()), &registerDialog, SLOT(register_success()));
    connect(&client, SIGNAL(registerFailure()), &registerDialog, SLOT(register_failure()));
    connect(&registerDialog, SIGNAL(logIn()), this, SLOT(show_main()));

    connect(&client, SIGNAL(getActiveUsers(QString)), &chatClient, SLOT(get_active_users(QString)));
    connect(&chatClient, SIGNAL(requestGetAllUsers()), this, SLOT(get_all_users()));
    connect(&client, SIGNAL(getAllUsersResponse(QString)), &chatClient, SLOT(get_all_users(QString)));

    connect(&client, SIGNAL(getMessages(QString,QString)), &chatClient, SLOT(get_messages(QString,QString)));    
    connect(&chatClient, SIGNAL(getPrivateHistory()), this, SLOT(get_private_history()));
    connect(&chatClient, SIGNAL(sendPrivateMessage(QString)), this, SLOT(send_private_chat(QString)));
    
    connect(&chatClient, SIGNAL(requestCreateGroup(QString,QStringList)), this, SLOT(create_group(QString,QStringList)));
    connect(&client, SIGNAL(getMyGroups(QString)), &chatClient, SLOT(get_my_groups(QString)));
    connect(&chatClient, SIGNAL(sendGroupMessage(QString)), this, SLOT(send_group_chat(QString)));
    connect(&chatClient, SIGNAL(getGroupHistory()), this, SLOT(get_group_history()));
    connect(&chatClient, SIGNAL(requestManageGroup(QString)), this, SLOT(request_manage_group(QString)));
    connect(&client, SIGNAL(manageGroup(QString,QStringList)), &chatClient, SLOT(open_manage_group(QString,QStringList)));
    connect(&chatClient, SIGNAL(requestLeaveGroup(QString)), this, SLOT(request_leave_group(QString)));
    connect(&chatClient, SIGNAL(requestUpdateGroup(QString,QStringList)), this, SLOT(request_update_group(QString,QStringList)));

    connect(&chatClient, SIGNAL(requestAddFriend(QString,QString)), this, SLOT(request_add_friend(QString,QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_main(){
    this->show();
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
    hide();
    chatClient.set_current(username);
    chatClient.show();
}

void MainWindow::login_failure(){
    QMessageBox::information(this, "Login failure", "Log in failure! Check your username and password!");
}

void MainWindow::register_request(QString username, QString password){
    client.SendRequest("SIGNUP", username, password);
}

void MainWindow::get_all_users() {
    client.SendRequest("GET_ALL_USERS", "", "");
}

void MainWindow::get_private_history() {
    client.SendRequest("GET_PRIVATE_CHAT", chatClient.current, chatClient.receiver);
}

void MainWindow::send_private_chat(QString message){
    client.SendRequest("PRIVATE", chatClient.receiver, message);
}

void MainWindow::create_group(QString nameGroup, QStringList members){
    client.SendRequest("CREATE_GROUP", nameGroup, members.join('|'));
}

void MainWindow::send_group_chat(QString message){
    client.SendRequest("GROUP", chatClient.receiver, message);
}

void MainWindow::get_group_history() {
    client.SendRequest("GET_GROUP_CHAT", chatClient.receiver, "");
}

void MainWindow::request_manage_group(const QString groupName) {
    client.SendRequest("MANAGE_GROUP", groupName, "");
}

void MainWindow::request_leave_group(const QString groupName) {
    client.SendRequest("LEAVE_GROUP", chatClient.current, groupName);
}

void MainWindow::request_update_group(const QString groupName, QStringList members) {
    client.SendRequest("UPDATE_GROUP", groupName, members.join('|'));
}

void MainWindow::request_add_friend(const QString username, QString type) {
    client.SendRequest("ADD_FRIEND", chatClient.current + '|' + username, type);
}

void MainWindow::log_out(QString username){
    client.SendRequest("LOGOUT", username, "");
    this->show();
}