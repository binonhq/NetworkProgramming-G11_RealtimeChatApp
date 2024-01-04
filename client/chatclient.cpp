#include "chatclient.h"
#include "ui_chatclient.h"


ChatClient::ChatClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatClient)
{
    ui->setupUi(this);
    ui->label_username->setText(this->current);
    ui->label_type->hide();
    ui->pushButton_sendMsg->setDisabled(true);
}

ChatClient::~ChatClient()
{
    delete ui;
}

void ChatClient::set_current(QString username) {
    this->current = username;
    ui->label_username->setText(this->current);
}

void ChatClient::get_all_users(QString userList){
    QStringList users = userList.split('|');
    QStringList allUserList;
    for (const QString& userData : users) {
        QStringList data = userData.split('`');
        allUserList.append(data[0]);
    }

    allUserList.removeOne(current);
    this->allUsers = allUserList;

    QWidget *containerWidget = new QWidget;
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    for (const QString& userData : users) {
        UserFrame *userFrame = new UserFrame(this);
        connect(userFrame, SIGNAL(userClicked(QString,QString)), this, SLOT(set_receiver(QString,QString)));
        connect(userFrame, SIGNAL(requestAddFriend(QString,QString)), this, SLOT(send_request_add_friend(QString,QString)));

        QStringList data = userData.split('`');
        if (data[0] == current) {
            continue;
        }

        userFrame->setUsername(data[0]);
        userFrame->setFriendButton(data[1]);
        userFrame->hideStatus();
        containerLayout->addWidget(userFrame);
    }

    QLabel *spacerLabel = new QLabel;
    containerLayout->addWidget(spacerLabel);
    containerWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->scrollArea_allUsers->setWidget(containerWidget);
}

void ChatClient::get_active_users(QString data){
    QStringList actives = data.split(',');
    actives.removeOne(this->current);
    this->activeUsers = actives;

    QWidget *containerWidget = new QWidget;
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    for (const QString& username : this->activeUsers) {
        UserFrame *userFrame = new UserFrame(this);
        connect(userFrame, SIGNAL(userClicked(QString,QString)), this, SLOT(set_receiver(QString,QString)));
        userFrame->hideAddFriendButton();
        userFrame->setUsername(username);
        containerLayout->addWidget(userFrame);
    }

    QLabel *spacerLabel = new QLabel;
    containerLayout->addWidget(spacerLabel);
    containerWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->scrollArea_activeList->setWidget(containerWidget);
}

void ChatClient::set_receiver(const QString &clickedName, QString type) {
    this->receiver = clickedName;
    this->type = type;

    ui->pushButton_sendMsg->setDisabled(false);
    ui->listWidget_inbox->clear();
    ui->label_type->setText(this->type.toUpper());
    ui->label_type->show();
    ui->label_nameChat->setText(this->receiver);

    if (type == "private") {
        emit getPrivateHistory();
    } else if (type == "group") {
        emit getGroupHistory();
    }

}

void ChatClient::get_messages(QString from, QString messages) {
    if(from != this->receiver) {
       QString notification = "You have a new message from " + from;
       ui->listWidget_notifications->insertItem(0,notification);
       return;
    }

    ui->listWidget_inbox->clear();
    ui->listWidget_inbox->addItems(messages.split('|'));
}

void ChatClient::on_pushButton_sendMsg_clicked()
{
    if(receiver == nullptr) {
        QMessageBox::warning(this, "Send fail","Please choose an user or group to send messages");
        return;
    }

    QString message = ui->lineEdit_input->text();

    if(message == "") {
        QMessageBox::warning(this, "Send fail","Please input a messages!");
        return;
    }

    if (this->type == "private") {
       emit sendPrivateMessage(message);
    } else if (this->type == "group") {
       emit sendGroupMessage(message);
    }

    ui->lineEdit_input->clear();
}

void ChatClient::send_request_add_friend(const QString &username, QString type){
    emit requestAddFriend(username, type);
}

void ChatClient::on_pushButton_createGroup_clicked()
{
    CreateGroupDialog *dialog = new CreateGroupDialog;
    connect(dialog, SIGNAL(createGroup(QString,QStringList)), this, SLOT(request_create_group(QString,QStringList)));
    
    dialog->set_user_list(this->allUsers);
    dialog->show();
}

void ChatClient::request_create_group(QString nameGroup ,QStringList members) {
    members.append(current);
    emit requestCreateGroup(nameGroup, members);
}

void ChatClient::get_my_groups(QString groups){
    if (groups == "") {
        return;
    }

    QStringList myGroups = groups.split('|');
    QWidget *containerWidget = new QWidget;
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    for (const QString& group : myGroups) {
        GroupChatFrame *groupChatFrame = new GroupChatFrame(this);
        connect(groupChatFrame, SIGNAL(userClicked(QString,QString)), this, SLOT(set_receiver(QString,QString)));
        connect(groupChatFrame, SIGNAL(manageGroup(QString)), this, SLOT(request_manage_group(QString)));
        groupChatFrame->setGroupName(group);
        containerLayout->addWidget(groupChatFrame);
    }

    QLabel *spacerLabel = new QLabel;
    containerLayout->addWidget(spacerLabel);
    containerWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->scrollArea_groups->setWidget(containerWidget);
}

void ChatClient::request_manage_group(const QString &groupName){
    emit requestManageGroup(groupName);
};

void ChatClient::open_manage_group(QString groupName, QStringList members){
    CreateGroupDialog *dialog = new CreateGroupDialog;
    connect(dialog, SIGNAL(leaveGroup(QString)), this, SLOT(request_leave_group(QString)));
    connect(dialog, SIGNAL(updateGroup(QString,QStringList)), this, SLOT(request_update_group(QString,QStringList)));
    
    dialog->set_user_list(this->allUsers);
    dialog->on_manage_group(groupName, members);
    dialog->show();
}

void ChatClient::request_leave_group(const QString &groupName){
    emit requestLeaveGroup(groupName);
};

void ChatClient::request_update_group(const QString &groupName, QStringList members){
    members.append(current);
    emit requestUpdateGroup(groupName, members);
};

void ChatClient::on_pushButton_logout_clicked()
{
    this->close();
    ui->label_nameChat->setText("Chat room");
    ui->listWidget_inbox->clear();
    ui->listWidget_notifications->clear();

    emit logOut(this->current);
    
    QMessageBox::information(this, "Log out","Log out successful!");
}
