#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QDialog>
#include <activeuserframe.h>

namespace Ui {
class ChatClient;
}

class ChatClient : public QDialog
{
    Q_OBJECT

public:
    explicit ChatClient(QWidget *parent = nullptr);
    ~ChatClient();
    QString username;
    QString receiver;
    void set_username(QString username);

signals:
    void logOut(QString username);
    void sendPrivateMessage(QString message);
private slots:
    void on_pushButton_logout_clicked();
    void get_active_users(QString data);
    void set_receiver(const QString &clickedUsername);


    void on_pushButton_sendMsg_clicked();

private:
    Ui::ChatClient *ui;
    ActiveUserFrame *activeUserFrame;
};

#endif // CHATCLIENT_H
