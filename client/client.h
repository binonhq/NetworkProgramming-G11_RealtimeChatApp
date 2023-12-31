#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QUdpSocket>


class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    void SendRequest(QString flag, QString mainContent, QString subContent);

signals:
    void loginSuccess(QString userID);
    void loginFailure();
    void registerSuccess();
    void registerFailure();
    void getActiveUsers(QString data);
    void getMessages(QString from, QString messages);
    void getAllUsersResponse(QString userList);
    void getMyGroups(QString groups);
    void manageGroup(QString groupName, QStringList members);

public slots:
    void getResponse();

private:
    QUdpSocket *mySocket;
};

#endif // CLIENT_H
