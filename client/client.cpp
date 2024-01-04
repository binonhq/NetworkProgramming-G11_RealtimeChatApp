#include "client.h"
#include "Response.h"
#include <mainwindow.h>

Client::Client(QObject *parent) :
    QObject(parent)
{
    mySocket = new QUdpSocket(this);
    mySocket->bind(QHostAddress::AnyIPv4, 5678);
    connect(mySocket,SIGNAL(readyRead()),this,SLOT(getResponse()));
}

void Client::SendRequest(QString flag, QString mainContent, QString subContent) {
    QString message = flag + '\0' + mainContent + '\0' + subContent + '\0';

    QHostAddress ipAddressServer("172.20.10.5");
    quint16 portServer = 1234;

    mySocket->writeDatagram(message.toUtf8(), ipAddressServer, portServer);
}

void Client::getResponse()
{
    while (mySocket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(mySocket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        mySocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

        QString request = QString(buffer);
        QStringList data = request.split('\0');

        qDebug() << "Message from: " << sender.toString();
        qDebug() << "Message port: " << senderPort;
        qDebug() << "Message: " << buffer;

        Response response;

        if (data.size() < 3) {
            qDebug() << "Invalid message format";
            return;
        }

        response.flag = data[0];
        response.mainContent = data[1];
        response.subContent = data[2];

        qDebug() << "Flag: " << response.flag;
        qDebug() << "Content main: " << response.mainContent;
        qDebug() << "Sub content: " << response.subContent;

        if (response.flag == "LI_SUCCESS") {
            QString username = response.mainContent;
            emit loginSuccess(username);
            return;
        }

        if (response.flag == "LI_FAILURE") {
            emit loginFailure();
            return;
        }

        if (response.flag == "SU_SUCCESS") {
            emit registerSuccess();
            return;
        }

        if (response.flag == "SU_FAILURE") {
            emit registerFailure();
            return;
        }


        if (response.flag == "LIST_ACTIVE_USERS") {
            emit getActiveUsers(response.mainContent);
            return;
        }

        if (response.flag == "PRIVATE" || response.flag == "GROUP_MESSAGE") {
            emit getMessages(response.mainContent, response.subContent);
        }

        if (response.flag == "GET_ALL_USERS") {
            emit getAllUsersResponse(response.mainContent);
        }

        if (response.flag == "YOUR_GROUP") {
            emit getMyGroups(response.mainContent);
        }

        if (response.flag == "MANAGE_GROUP") {
            emit manageGroup(response.mainContent, response.subContent.split('|'));
        }

    }
}
