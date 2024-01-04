#include "server.h"
#include "JsonHelper.h"
#include <QTimer>
#include <QNetworkInterface>


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
#define SEND_PRIVATE "PRIVATE"
#define GET_PRIVATE_CHAT "GET_PRIVATE_CHAT"
#define GET_ALL_USERS "GET_ALL_USERS"


Server::Server(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address()) {
            quint16 portToBind = 0;
            if (socket->bind(ipAddressesList.at(i), portToBind)) {
                qDebug() << "======================================\n\n\n";
                qDebug() << "Server Started at: " + ipAddressesList.at(i).toString() + ":" + QString::number(socket->localPort());
                qDebug() << "\n\n\n======================================";
                connect(socket, SIGNAL(readyRead()), this, SLOT(getRequest()));
            } else {
                qCritical() << "Failed to bind the socket. Check the IP address and port.";
                return;
            }
        }
    }
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

            sendAllCurrentActive();

            QString groupChats = getGroupChatOfUser(username);
            sendResponse(sender, senderPort, "YOUR_GROUP", groupChats, "");

            sendAllUsersData(newConnection);

            return;
        }

        sendResponse(sender, senderPort, RESPONSE_LOG_IN_FAILURE, "", "");
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

    if (flag == REQUEST_LOG_OUT) {
        for (auto it = connections.begin(); it != connections.end(); ++it) {
            if (it->username == mainContent && it->host == sender && it->port == senderPort) {
                connections.erase(it);
                break;
            }
        }

        sendAllCurrentActive();
        return;
    }

    if (flag == SEND_PRIVATE) {
        CurrentActive from;
        for (const CurrentActive &user : connections) {
            if (user.host == sender && user.port == senderPort){
                from = user;
                break;
            }
        }

        addPrivateChat(from.username, mainContent, subContent);
        sendPrivateMessage(from.username, mainContent);
        return;
    }

    if (flag == GET_PRIVATE_CHAT) {
        QString data = getPrivateChat(mainContent, subContent);
        sendResponse(sender,senderPort,SEND_PRIVATE,subContent, data);
        
        return;
    }

    if (flag == GET_ALL_USERS) {
        QVector<User> listUser = getAllUsers();
        QString data;
        foreach (const User& user, listUser) {
            data += user.username + '|';
        }

        if (data != ""){
            data.chop(1);
        }

        sendResponse(sender,senderPort,GET_ALL_USERS,data,"");
        return;
    }

    if (flag == "CREATE_GROUP") {
        addGroup(mainContent, subContent);
        QStringList members = subContent.split('|');
        QString creator;

        foreach (const CurrentActive &user, connections) {
            if (members.contains(user.username)) {
                QString groupChats = getGroupChatOfUser(user.username);
                sendResponse(user.host, user.port, "YOUR_GROUP", groupChats, "");
            }
            if (user.host == sender && user.port==senderPort) {
                creator = user.username;
            }
        }

        addGroupChat("",mainContent,creator +" CREATES THE GROUP!");
        return;
    }

    if (flag == "GROUP") {
        CurrentActive from;
        QString group = mainContent;
        QStringList members = getGroupMember(group);
        QVector<CurrentActive> activeMembers;

        for (const CurrentActive &user : connections) {
            if (user.host == sender && user.port == senderPort){
                from = user;
            }
            if (members.contains(user.username)) {
                activeMembers.push_back(user);
            }
        }

        addGroupChat(from.username, group, subContent);
        sendGroupMessage(group, activeMembers);
        return;
    }

    if (flag == "GET_GROUP_CHAT") {
        QString data = getGroupChatMessage(mainContent);
        sendResponse(sender,senderPort,"GROUP_MESSAGE", mainContent, data);
        return;
    }

    if (flag == "ADD_FRIEND") {
        QStringList data = mainContent.split("|");
        QString senderName = data[0];
        QString receiver = data[1];
        QString type = subContent;

        checkFriendRequest(senderName,receiver,type);

        CurrentActive now;
        now.host = sender;
        now.port = senderPort;
        now.username = data[0];

        sendAllUsersData(now);


        foreach (const CurrentActive &user, connections) {
            if (user.username == receiver) {
                sendAllUsersData(user);
                return;
            }
        }
        return;
    }

    if (flag == "MANAGE_GROUP") {
        QStringList members = getGroupMember(mainContent);
        sendResponse(sender,senderPort,"MANAGE_GROUP", mainContent, members.join('|'));
        return;
    }

    if (flag == "LEAVE_GROUP") {
        removeFromGroup(subContent, mainContent);
        addGroupChat("",subContent,mainContent + " HAS LEAVE THE GROUP!");
        QString groupChats = getGroupChatOfUser(mainContent);
        sendResponse(sender, senderPort, "YOUR_GROUP", groupChats, "");

        QStringList members = getGroupMember(subContent);
        QVector<CurrentActive> activeMembers;

        for (const CurrentActive &user : connections) {
            if (members.contains(user.username)) {
                activeMembers.push_back(user);
            }
        }

        sendGroupMessage(subContent, activeMembers);

        return;
    }

    if (flag == "UPDATE_GROUP") {
        QStringList oldMembers = getGroupMember(mainContent);
        QStringList newMembers = subContent.split('|');
        QString groupName = mainContent;

        updateGroupMember(mainContent, newMembers);

        for (const QString &newMember : newMembers) {
            if (!oldMembers.contains(newMember)) {
                addGroupChat("", mainContent, newMember + " HAS BEEN ADDED TO THE GROUP!");
            }
        }

        for (const QString &oldMember : oldMembers) {
            if (!newMembers.contains(oldMember)) {
                addGroupChat("", mainContent, oldMember + " HAS BEEN REMOVED FROM THE GROUP!");
            }
        }

        QStringList members = getGroupMember(groupName);
        QVector<CurrentActive> activeMembers;

        foreach (const CurrentActive &user, connections) {
            if (members.contains(user.username)) {
                activeMembers.append(user);
                QString groupChats = getGroupChatOfUser(user.username);
                sendResponse(user.host, user.port, "YOUR_GROUP", groupChats, "");
            }
        }

        sendGroupMessage(mainContent, activeMembers);

        return;
    }

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

void Server::sendPrivateMessage(QString fromName, QString toName) {
    QString data = getPrivateChat(fromName, toName);
    QString responseFlag = SEND_PRIVATE;

    CurrentActive from;
    CurrentActive to;

    for (const CurrentActive &user : connections) {
        if (user.username == fromName){
            from = user;
        }
        if (user.username == toName){
            to = user;
        }
    }

    if (from.username != "") {
        QString messageToSender = responseFlag + '\0' + toName + '\0' + data + '\0';
        socket->writeDatagram(messageToSender.toUtf8(), from.host, from.port);
        QString log = "--RESPONSE-- HOST: " + from.host.toString() + ", PORT: " + QString::number(from.port) + ", MSG--FLAG: " + responseFlag + ", MSG--MAINCONTENT: " + data +", MSG--SUBCONTENT: " + "";
        emit logReceived(log);
    }


    if(to.username != "") {
        QString messageToReceiver = responseFlag + '\0' + fromName + '\0' + data + '\0';
        socket->writeDatagram(messageToReceiver.toUtf8(), to.host, to.port);
        QString log = "--RESPONSE-- HOST: " + to.host.toString() + ", PORT: " + QString::number(to.port) + ", MSG--FLAG: " + responseFlag + ", MSG--MAINCONTENT: " + data +", MSG--SUBCONTENT: " + "";
        emit logReceived(log);
    }
};

void Server::sendGroupMessage(QString groupName, QVector<CurrentActive> activeMembers) {
    QString data = getGroupChatMessage(groupName);

    for (const CurrentActive &member : activeMembers) {
        QString responseFlag = "GROUP_MESSAGE";
        QString message = responseFlag + '\0' + groupName + '\0' + data + '\0';

        socket->writeDatagram(message.toUtf8(), member.host, member.port);

        QString log = "--SEND-- HOST: " + member.host.toString() + ", PORT: " + QString::number(member.port)
                      + ", MSG--FLAG: " + responseFlag + ", MSG--MAINCONTENT: " + groupName
                      + ", MSG--SUBCONTENT: " + data;

        emit logReceived(log);
    }
}

void Server::sendAllUsersData(CurrentActive now) {
    QVector<User> listUser = getAllUsers();
    QStringList listRequestAddFriend = getRequestAddFriend(now.username);
    QStringList listRequestedAddFriend = getRequestedAddFriend(now.username);
    QStringList listFriend = getListFriend(now.username);
    QString data;
    foreach (const User& user, listUser) {
        QString subData = user.username;
        if (listRequestAddFriend.contains(user.username)) {
            subData += "`1";
        } if (listRequestedAddFriend.contains(user.username)) {
            subData += "`2";
        } if (listFriend.contains(user.username)) {
            subData += "`3";
        } else {
            subData += "`0";
        }

        data += subData + '|';
    }

    if (data != ""){
        data.chop(1);
    }

    sendResponse(now.host,now.port,GET_ALL_USERS,data,"");
}







