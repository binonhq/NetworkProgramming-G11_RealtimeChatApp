#include "chatclient.h"
#include "ui_chatclient.h"
#include <QMessageBox>

ChatClient::ChatClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatClient)
{
    ui->setupUi(this);
    ui->label_username->setText(username);
}

ChatClient::~ChatClient()
{
    delete ui;
}

void ChatClient::get_active_users(QString data){
    QStringList activeUsers = data.split(',');

    QWidget *containerWidget = new QWidget;
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    for (const QString& username : activeUsers) {
        ActiveUserFrame *userFrame = new ActiveUserFrame(this);

        connect(userFrame, SIGNAL(userClicked(QString)), this, SLOT(set_receiver(QString)));

        userFrame->setUsername(username);
        containerLayout->addWidget(userFrame);
    }

    ui->scrollArea_activeList->setWidget(containerWidget);
}

void ChatClient::on_pushButton_logout_clicked()
{
    hide();
    emit logOut(this->username);
    QMessageBox::information(this, "Log out","Log out successfull!");
}

void ChatClient::set_receiver(const QString &clickedUsername) {
    receiver = clickedUsername;
    ui->label_nameChat->setText(receiver);
    qDebug() << "Receiver set to: " << receiver;
}

void ChatClient::set_username(QString username) {
    this->username = username;
    ui->label_username->setText(username);
}

void ChatClient::on_pushButton_sendMsg_clicked()
{
    QString message = ui->lineEdit_input->text();
    emit sendPrivateMessage(message);
    ui->lineEdit_input->clear();
}

