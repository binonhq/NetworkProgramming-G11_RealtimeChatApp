#include "userframe.h"
#include "ui_userframe.h"

UserFrame::UserFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ActiveUserFrame)
{
    ui->setupUi(this);
    ui->pushButton_rejectAddFriend->hide();
}

UserFrame::~UserFrame()
{
    delete ui;
}

void UserFrame::setUsername(QString username) {
    ui->pushButton_chat->setText(username);
}

void UserFrame::setFriendButton(QString status) {
    if (status == '1') {
        ui->pushButton_addFriend->setText("Accept");
        ui->pushButton_addFriend->setStyleSheet("background-color: rgb(255, 163, 104); color: #ffffff");
        ui->pushButton_rejectAddFriend->show();
    }

    if (status == '2') {
        ui->pushButton_addFriend->setText("Requested");
        ui->pushButton_addFriend->setStyleSheet("background-color: rgb(192, 192, 192);");
        ui->pushButton_addFriend->setDisabled(true);
        ui->pushButton_rejectAddFriend->setText("Unrequest");
        ui->pushButton_rejectAddFriend->show();
    }

    if (status == '3') {
        ui->pushButton_addFriend->setText("Friend");
        ui->pushButton_addFriend->setStyleSheet("background-color: #ffffff;");
        ui->pushButton_addFriend->setDisabled(true);
        ui->pushButton_rejectAddFriend->setText("Unfriend");
        ui->pushButton_rejectAddFriend->show();
    }
}

void UserFrame::hideStatus() {
    ui->label_active->hide();
}

void UserFrame::hideAddFriendButton() {
    ui->pushButton_addFriend->hide();
}


void UserFrame::on_pushButton_chat_clicked()
{
    emit userClicked(ui->pushButton_chat->text(), "private");
}


void UserFrame::on_pushButton_addFriend_clicked()
{
    if (ui->pushButton_addFriend->text() == "Add friend") {
        emit requestAddFriend(ui->pushButton_chat->text(), "add");
    }

    if (ui->pushButton_addFriend->text() == "Accept") {
        emit requestAddFriend(ui->pushButton_chat->text(), "accept");
    }
}


void UserFrame::on_pushButton_rejectAddFriend_clicked()
{
    if (ui->pushButton_rejectAddFriend->text() == "Reject") {
       emit requestAddFriend(ui->pushButton_chat->text(), "reject");
    }

    if (ui->pushButton_rejectAddFriend->text() == "Unfriend") {
       emit requestAddFriend(ui->pushButton_chat->text(), "unfriend");
    }

    if (ui->pushButton_rejectAddFriend->text() == "Unrequest") {
       emit requestAddFriend(ui->pushButton_chat->text(), "unrequest");
    }
}

