#include "server.h"
#include "JsonHelper.h"
#include <QTimer>

#define SERVER_PORT 1234
#define REQUEST_LOG_IN_FLAG "LOGIN"
#define RESPONSE_LOG_IN_SUCCESS "LI_SUCCESS"
#define RESPONSE_LOG_IN_FAILURE "LI_FAILURE"

#define REQUEST_SIGN_UP_FLAG "SIGNUP"
#define RESPONSE_SIGN_UP_SUCCESS "SU_SUCCESS"
#define RESPONSE_SIGN_UP_FAILURE "SU_FAILURE"

#define REQUEST_GET_ACTIVE_USERS "GET_ACTIVE_USERS"
#define RESPONSE_ACTIVE_USERS "LIST_ACTIVE_USERS"

#define REQUEST_LOG_OUT "LOGOUT"


Server::Server(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(getRequest()));

    qDebug()<<"=============================";
    qDebug()<<"        Server Started       ";
    qDebug()<<"=============================";


}

void Server::sendResponse(QHostAddress sender, quint16 senderPort, QString responseFlag, QString mainContent, QString subContent){
    QString message = responseFlag + '\0' + mainContent + '\0' + subContent + '\0';
    socket->writeDatagram(message.toUtf8(), sender, senderPort);
    QString log = "--RESPONSE-- HOST: " + sender.toString() + ", PORT: " + QString::number(senderPort)+ ", MSG--FLAG: " + responseFlag + ", MSG--MAINCONTENT: " + mainContent +", MSG--SUBCONTENT: " + subContent;
    emit logReceived(log);
}

void Server::getRequest()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    QString request = QString(buffer);
    QStringList data = request.split('\0');

    if (data.size() < 3) {
        return;
    }

    QString flag = data[0];
    QString mainContent = data[1];
    QString subContent = data[2];

    QString log = "--REQUEST-- HOST: " + sender.toString() + ", PORT: " + QString::number(senderPort) + ", MSG--FLAG: " + flag + ", MSG--MAINCONTENT: " + mainContent +", MSG--SUBCONTENT: " + subContent;
    emit logReceived(log);

    if (flag == REQUEST_LOG_IN_FLAG) {
        QString username = loginHandler(mainContent,subContent);
        if (username != "" ) {
            sendResponse(sender, senderPort, RESPONSE_LOG_IN_SUCCESS, username, "");

            CurrentActive newConnection;
            newConnection.username = username;
            newConnection.host = sender;
            newConnection.port = senderPort;

            connections.push_back(newConnection);

//            addCurrentActive(username, sender.toString() , QString::number(senderPort));
//            QVector<CurrentActive> currentActive = getAllCurrentActive();
//            QString data;
//            for (const CurrentActive &user : currentActive) {
//                data += user.username + ",";
//            }

//            if (!data.isEmpty()) {
//                data.chop(1);
//            }

            QTimer::singleShot(3000, [=]() {
                sendAllCurrentActive();
            });

            return;
        }
        sendResponse(sender, senderPort, RESPONSE_LOG_IN_SUCCESS, "", "");
        return;
    }

    if (flag == REQUEST_SIGN_UP_FLAG) {
        bool newUser = signupHandler(mainContent, subContent);
        if (newUser) {
            sendResponse(sender, senderPort, RESPONSE_SIGN_UP_SUCCESS, "", "");
            return;
        }

        sendResponse(sender,senderPort, RESPONSE_SIGN_UP_FAILURE,"","");
        return;
    }

//    if (flag == REQUEST_GET_ACTIVE_USERS) {
//        QVector<CurrentActive> currentActive = getAllCurrentActive();
//        QString data;
//        for (const CurrentActive &user : currentActive) {
//            data += user.username + ",";
//        }

//        if (!data.isEmpty()) {
//            data.chop(1);
//        }

//        sendResponse(sender,senderPort, RESPONSE_ACTIVE_USERS, data ,"");
//        return;
//    }

    if (flag == REQUEST_LOG_OUT) {
//        CurrentActive u;
//        u.username = mainContent;
//        u.host = sender;
//        u.port = senderPort;

        for (auto it = connections.begin(); it != connections.end(); ++it) {
            if (it->username == mainContent && it->host == sender && it->port == senderPort) {
                connections.erase(it);
                break;
            }
        }

//        removeCurrentActive(u);
        sendAllCurrentActive();
        return;
    }

//    if (flag == "PRIVATE") {
//        QString from;
//        QString to;
//        QVector<CurrentActive> currentActive = getAllCurrentActive();
//        for (const CurrentActive &user : currentActive) {
//            if (user.host == sender.toString() && user.port == QString::number(senderPort)){
//                from = user.username;
//            }
//            if (user.username == mainContent) {
//                sendResponse("PRIVATE")
//            }
//        }
//        addPrivateChat(from, mainContent, subContent);
//    }
}

QString Server::loginHandler(QString username, QString password) {
    QVector<User> listUser = getAllUsers();
    foreach (const User& existingUser, listUser) {
        if (existingUser.username == username && existingUser.password == password) {
            return username;
        }
    }
    return "";
}

bool Server::signupHandler(QString username, QString password) {

    QVector<User> listUser = getAllUsers();

    foreach (const User& existingUser, listUser) {
        if (existingUser.username == username) {
            return false;
        }
    }

    User user;
    user.username = username;
    user.password = password;
    addUser(user);

    return true;
}

void Server::sendAllCurrentActive() {
//    QVector<CurrentActive> currentActive = getAllCurrentActive();
    QString data;

    for (const CurrentActive &user : connections) {
        data += user.username + ",";
    }

    if (!data.isEmpty()) {
        data.chop(1);
    }

    for (const CurrentActive &user : connections) {
        QString responseFlag = RESPONSE_ACTIVE_USERS;
        QString message = responseFlag + '\0' + data + '\0' + "" + '\0';

        socket->writeDatagram(message.toUtf8(), user.host, user.port);
        QString log = "--SEND-- HOST: " + user.host.toString() + ", PORT: " + QString::number(user.port) + ", MSG--FLAG: " + responseFlag + ", MSG--MAINCONTENT: " + data +", MSG--SUBCONTENT: " + "";

        emit logReceived(log);
    }
}



