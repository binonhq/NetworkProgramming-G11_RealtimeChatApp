#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QDialog>
#include <QMessageBox>
#include <userframe.h>
#include <creategroupdialog.h>
#include <groupchatframe.h>

namespace Ui {
class ChatClient;
}

class ChatClient : public QDialog
{
    Q_OBJECT

public:
    explicit ChatClient(QWidget *parent = nullptr);
    ~ChatClient();
    QString current;
    QString receiver;
    QString type;
    QStringList allUsers;
    QStringList activeUsers;
    void set_current(QString username);

signals:
    void logOut(QString username);
    void requestGetAllUsers();

    //Private-Chat
    void sendPrivateMessage(QString message);
    void getPrivateHistory();
    
    //Group-Chat
    void requestCreateGroup(QString nameGroup ,QStringList members);
    void sendGroupMessage(QString message);
    void getGroupHistory();
    void requestManageGroup(const QString nameGroup);
    void requestUpdateGroup(const QString nameGroup, QStringList members);
    void requestLeaveGroup(const QString nameGroup);

    //Friend
    void requestAddFriend(const QString &username, QString type);

private slots:
    void get_active_users(QString data);
    void get_all_users(QString userList);
    
    void set_receiver(const QString &clickedUsername, QString type);
    void get_messages(QString from, QString messages);
    void on_pushButton_sendMsg_clicked();

    void on_pushButton_createGroup_clicked();
    void request_create_group(QString nameGroup ,QStringList members);
    void get_my_groups(QString groups);
    void request_manage_group(const QString &groupName);
    void open_manage_group(QString groupName, QStringList members);
    void request_leave_group(const QString &groupName);
    void request_update_group(const QString &groupName, QStringList members);
    
    void send_request_add_friend(const QString &username, QString type);

    void on_pushButton_logout_clicked();

private:
    Ui::ChatClient *ui;
    UserFrame *activeUserFrame;
};

#endif // CHATCLIENT_H
