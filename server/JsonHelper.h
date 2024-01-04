#ifndef JSONHELPER_H
#define JSONHELPER_H
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QVector>
#include <QString>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include "user.h"

#define USERS_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/users.txt"
#define ACTIVE_USERS_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/current_active.txt"
#define PRIVATE_CHAT_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/private_chat.txt"
#define GROUP_MEMBER_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/group_members.txt"
#define GROUP_CHAT_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/group_chat.txt"
#define FRIEND_REQUEST_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/friend_requests.txt"
#define FRIEND_LIST_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/list_friends.txt"

QVector<User> getAllUsers(){
    QString fileName = USERS_FILE;
    QVector<User> result;
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        return result;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split(",");
        if(fields.size() < 2) continue;
        User u;
        u.username = fields[0];
        u.password = fields[1];
        result.push_back(u);
    }
    file.close();
    return result;
}

void addUser(User user){
    QString fileName = USERS_FILE;
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }

    QTextStream out(&file);
    out << user.username << "," << user.password << "\n";
    file.close();
}


void addPrivateChat(QString sender, QString receiver, QString message){
    QString fileName = PRIVATE_CHAT_FILE;
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }

    QTextStream out(&file);

    if (sender < receiver) {
        out <<  sender + '\0' + receiver << '\0' << '[' + QDateTime::currentDateTime().toString() + ']' + " " + sender + ": " + message << "\n";
    } else {
        out <<  receiver << '\0' << sender << '\0' << '[' + QDateTime::currentDateTime().toString() + ']' + " " + sender + ": " + message << "\n";
    }

    file.close();
}

QString getPrivateChat(QString user1, QString user2) {
    QString fileName = PRIVATE_CHAT_FILE;
    QFile file(fileName);
    QString data;

    if(user1 > user2) {
        QString tmp;
        tmp = user1;
        user1 = user2;
        user2 = tmp;
    }

    if(!file.open(QIODevice::ReadOnly)) {
        return data;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split('\0');
        if(fields[0] == user1 && fields[1] == user2){
            data += fields[2] + '|';
        }
    }

    if (data != ""){
        data.chop(1);
    }

    file.close();
    return data;
}

void addGroup(QString groupName, QString members){
    QString fileName = GROUP_MEMBER_FILE;
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }

    QTextStream out(&file);
    out <<  groupName + '\0' + members << "\n";
    file.close();
}

QString getGroupChatOfUser(QString username){
    QString fileName = GROUP_MEMBER_FILE;
    QFile file(fileName);
    QStringList groupChats;

    if(!file.open(QIODevice::ReadOnly)) {
        return "";
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split('\0');
        QStringList users = fields[1].split('|');
        if (users.contains(username)) {
            groupChats << fields[0];
        }
    }

    QString data = groupChats.join('|');

    file.close();
    return data;
}

QStringList getGroupMember(QString group) {
    QString fileName = GROUP_MEMBER_FILE;
    QFile file(fileName);
    QStringList members;

    if(!file.open(QIODevice::ReadOnly)) {
        return members;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split('\0');
        if (fields[0] == group) {
            return fields[1].split('|');
        }
    }

    file.close();
    return members;
}

void addGroupChat(QString sender, QString group, QString message){
    QString fileName = GROUP_CHAT_FILE;
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }

    QTextStream out(&file);
    out <<  group + '\0'  << '[' + QDateTime::currentDateTime().toString() + ']' + " " + sender + ": " + message << "\n";

    file.close();
}

QString getGroupChatMessage(QString groupName) {
    QString fileName = GROUP_CHAT_FILE;
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        return "";
    }

    QTextStream in(&file);
    QString data;

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split('\0');
        if (fields[0] == groupName) {
            data += fields[1] + '|';
        }
    }

    if(data != "") {
        data.chop(1);
    }

    file.close();

    return data;
}

void checkFriendRequest(QString sender, QString receiver, QString type) {
    if (type == "add"){
        QString fileName = FRIEND_REQUEST_FILE;
        QFile file(fileName);

        if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);
        out <<  sender + '\0'  << receiver << "\n";
        file.close();
        return;
    }

    if (type == "unfriend") {
        QString fileName = FRIEND_LIST_FILE;
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QTextStream in(&file);
        QStringList fileContent;

        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.isEmpty()) continue;
            QStringList fields = line.split('\0');
            if ((fields[0] == receiver && fields[1] == sender) || (fields[1] == receiver && fields[0] == sender)) {
                continue;
            }
            fileContent.append(line);
        }

        file.close();

        if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);

        file.resize(0);

        for (const QString& line : fileContent) {
            out << line << '\n';
        }

        file.close();
        return;
    }

    if (type =="unrequest") {
        QString fileName = FRIEND_REQUEST_FILE;
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QTextStream in(&file);
        QStringList fileContent;

        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.isEmpty()) continue;
            QStringList fields = line.split('\0');
            if (fields[1] != receiver || fields[0] != sender) {
                fileContent.append(line);
            }
        }

        file.close();

        if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);

        file.resize(0);

        for (const QString& line : fileContent) {
            out << line << '\n';
        }

        file.close();
        return;
    }

    if (type == "accept") {
        QString fileName = FRIEND_LIST_FILE;
        QFile file(fileName);

        if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);
        out <<  sender + '\0'  << receiver << "\n";
        file.close();
    }

    QString fileName = FRIEND_REQUEST_FILE;
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QTextStream in(&file);
    QStringList fileContent;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.isEmpty()) continue;
        QStringList fields = line.split('\0');
        if (fields[0] != receiver || fields[1] != sender) {
            fileContent.append(line);
        }
    }

    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }

    QTextStream out(&file);

    file.resize(0);

    for (const QString& line : fileContent) {
        out << line << '\n';
    }

    file.close();
    return;
}

QStringList getRequestAddFriend(QString user) {
    QString fileName = FRIEND_REQUEST_FILE;
    QFile file(fileName);
    QStringList listRequest;

    if(!file.open(QIODevice::ReadOnly)) {
        return listRequest;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split('\0');
        if(fields[1] == user) {
            listRequest.append(fields[0]);
        }
    }

    file.close();

    return listRequest;
}

QStringList getRequestedAddFriend(QString user) {
    QString fileName = FRIEND_REQUEST_FILE;
    QFile file(fileName);
    QStringList listRequested;

    if(!file.open(QIODevice::ReadOnly)) {
        return listRequested;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split('\0');
        if(fields[0] == user) {
            listRequested.append(fields[1]);
        }
    }

    file.close();

    return listRequested;
}

QStringList getListFriend(QString user) {
    QString fileName = FRIEND_LIST_FILE;
    QFile file(fileName);
    QStringList listFriend;

    if(!file.open(QIODevice::ReadOnly)) {
        return listFriend;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split('\0');
        if(fields[0] == user) {
            listFriend.append(fields[1]);
        }
        if(fields[1] == user) {
            listFriend.append(fields[0]);
        }
    }

    file.close();

    return listFriend;
}

void removeFromGroup(QString groupName, QString user) {
    QString fileName = GROUP_MEMBER_FILE;
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QTextStream in(&file);
    QStringList fileContent;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.isEmpty()) continue;

        QStringList fields = line.split('\0');
        if (fields[0] != groupName) {
            fileContent.append(line);
            continue;
        }

        QStringList members = fields[1].split('|');
        members.removeOne(user);
        QString updateGroup = groupName + '\0' + members.join('|');
        fileContent.append(updateGroup);
    }

    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }

    QTextStream out(&file);

    file.resize(0);

    for (const QString& line : fileContent) {
        out << line << '\n';
    }

    file.close();
    return;
}

void updateGroupMember(QString groupName, QStringList newMembers) {
    QString fileName = GROUP_MEMBER_FILE;
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QTextStream in(&file);
    QStringList fileContent;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.isEmpty()) continue;

        QStringList fields = line.split('\0');
        if (fields[0] != groupName) {
            fileContent.append(line);
            continue;
        }

        QString updateGroup = groupName + '\0' + newMembers.join('|');
        fileContent.append(updateGroup);
    }

    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }

    QTextStream out(&file);

    file.resize(0);

    for (const QString& line : fileContent) {
        out << line << '\n';
    }

    file.close();
    return;
}

#endif // JSONHELPER_H
