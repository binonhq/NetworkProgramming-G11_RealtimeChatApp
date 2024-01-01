#ifndef JSONHELPER_H
#define JSONHELPER_H
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include "user.h"
#include <current_active.h>
//#include "Question.h"
//#include "History.h"

#define USERS_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/users.txt"
#define ACTIVE_USERS_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/current_active.txt"
#define PRIVATE_CHAT_FILE "/Users/binonhq/NetworkProgramming-G11_RealtimeChatApp/server/private_chat.txt"


QString convert(QString data){
    return data;
}

//QVector<Question> readJson(QString fileName){
//    QFile file;
//    file.setFileName(fileName);
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    QJsonDocument jsonDocs;
//    QByteArray tmp = file.readAll();
//    QJsonParseError error;
//    jsonDocs = QJsonDocument::fromJson(tmp, &error);
//    file.close();


//    QVector<Question> result;
//    if(jsonDocs.isNull()) return result;

//    QJsonArray jsonArray = jsonDocs.array();

//    for(int i=0; i<jsonArray.size(); i++){
//        QJsonValue jsonValue = jsonArray.at(i);
//        QJsonObject obj = jsonValue.toObject();
//        //qDebug() << obj.value(QString("name"));

//        // convert
//        Question q;
//        q.question = convert(obj["question"].toString());
//        QJsonArray answerArray = obj.value(QString("answers")).toArray();
//        for(int j=0; j<answerArray.size(); j++){
//            q.answers.append(answerArray.at(j).toString());
//        }
//        q.correctAnswer = obj.value(QString("correctAnswer")).toInt();
//        q.hard = obj.value(QString("hard")).toInt();

//        result.append(q);
//    }

//    return result;
//}

//void print(QVector<Question> result){
//    for(int i=0; i<result.size(); i++){
//        qDebug() << result.at(i).question << " ";
//        for(int j=0; j<result.at(i).answers.size(); j++){
//            qDebug() << result.at(i).answers.at(j) << " ";

//        }
//    }
//}


//QVector<Question> convertByteArrayToQuestion(QByteArray tmp){
//    QJsonParseError error;
//    QJsonDocument jsonDocs = QJsonDocument::fromJson(tmp, &error);


//    QVector<Question> result;
//    if(jsonDocs.isNull()) return result;

//    QJsonArray jsonArray = jsonDocs.array();

//    for(int i=0; i<jsonArray.size(); i++){
//        QJsonValue jsonValue = jsonArray.at(i);
//        QJsonObject obj = jsonValue.toObject();
//        //qDebug() << obj.value(QString("name"));

//        // convert
//        Question q;
//        q.question = convert(obj["question"].toString());
//        QJsonArray answerArray = obj.value(QString("answers")).toArray();
//        for(int j=0; j<answerArray.size(); j++){
//            q.answers.append(answerArray.at(j).toString());
//        }
//        q.correctAnswer = obj.value(QString("correctAnswer")).toInt();
//        q.hard = obj.value(QString("hard")).toInt();

//        result.append(q);
//    }

//    return result;
//}

//QByteArray toJson(QVector<Question> datas){
//    QJsonArray arr;
//    for(int i=0; i<datas.size(); i++){
//        QJsonObject object;
//        object.insert("question", datas[i].question);

//        QJsonArray jsonAnswerArr;
//        for(QString d: datas[i].answers){
//            jsonAnswerArr.append(d);
//        }
//        object.insert("answers", jsonAnswerArr);
//        object.insert("correctAnswer", datas[i].correctAnswer);
//        object.insert("hard", datas[i].hard);

//        arr.append(object);
//    }

//    QJsonDocument jsonDoc;
//    jsonDoc.setArray(arr);
//    return jsonDoc.toJson();

//}

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

//void fflushUserData(QString fileName, QVector<User> users){
//    QFile file(fileName);
//    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
//        return;
//    }

//    QTextStream out(&file);
//    for(User user: users){
//        out << user.username << "," << user.password << "," << user.score << "," << user.rank << "\n";
//        qDebug() << user.score;
//    }
//    file.close();
//}

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

void addCurrentActive(QString username, QString host, QString port){
    QString fileName = ACTIVE_USERS_FILE;
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }
    QTextStream out(&file);

    out << username << "," << host << "," << port << "\n";
    file.close();
}

QVector<CurrentActive>getAllCurrentActive(){
    QString fileName = ACTIVE_USERS_FILE;
    QVector<CurrentActive> result;
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        return result;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split(",");
        if(fields.size() < 3) continue;
        CurrentActive u;
        u.username = fields[0];
        u.host = fields[1];
        u.port = fields[2];
        result.push_back(u);
    }
    file.close();
    return result;
}

void removeCurrentActive(const CurrentActive &userToRemove) {
    QString fileName = ACTIVE_USERS_FILE;
    QVector<CurrentActive> activeUsers = getAllCurrentActive();

    // Find the index of the userToRemove
    int indexToRemove = -1;
    for (int i = 0; i < activeUsers.size(); ++i) {
        if (activeUsers[i].username == userToRemove.username && activeUsers[i].port == userToRemove.port && activeUsers[i].host == userToRemove.host) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1) {
        activeUsers.remove(indexToRemove);
    }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const CurrentActive &user : activeUsers) {
            out << user.username << "," << user.host << "," << user.port << "\n";
        }
        file.close();
    }
}


void addPrivateChat(QString sender, QString receiver, QString message){
    QString fileName = PRIVATE_CHAT_FILE;
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        return;
    }
    QTextStream out(&file);
    out << sender << "," << receiver << message << "\n";
    file.close();
}

#endif // JSONHELPER_H
