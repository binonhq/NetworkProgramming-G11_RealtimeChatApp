#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>
#include <user.h>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

    void sendResponse(QHostAddress sender, quint16 senderPort, QString responseFlag, QString mainContent, QString subContent);
    QString loginHandler(QString username, QString password);
    bool signupHandler(QString username, QString password);
    void sendAllCurrentActive();

signals:
    void logReceived(QString log);

public slots:
    void getRequest();

private:
    QUdpSocket *socket;
};

#endif // SERVER_H
