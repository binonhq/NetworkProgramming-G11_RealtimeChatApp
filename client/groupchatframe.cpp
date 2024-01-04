#include "groupchatframe.h"
#include "ui_groupchatframe.h"

GroupChatFrame::GroupChatFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GroupChatFrame)
{
    ui->setupUi(this);
}

GroupChatFrame::~GroupChatFrame()
{
    delete ui;
}

void GroupChatFrame::setGroupName(QString name){
    ui->pushButton_chat->setText(name);
}

void GroupChatFrame::on_pushButton_chat_clicked()
{
    emit userClicked(ui->pushButton_chat->text(), "group");
}

void GroupChatFrame::on_pushButton_manage_clicked()
{
    emit manageGroup(ui->pushButton_chat->text());
}

