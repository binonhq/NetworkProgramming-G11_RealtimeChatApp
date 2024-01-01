#include "activeuserframe.h"
#include "ui_activeuserframe.h"

ActiveUserFrame::ActiveUserFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ActiveUserFrame)
{
    ui->setupUi(this);
//    connect(ui->pushButton_chat, &QPushButton::clicked, [=]() {
//        emit userClicked(ui->label_username->text());
//    });
}

ActiveUserFrame::~ActiveUserFrame()
{
    delete ui;
}

void ActiveUserFrame::setUsername(QString username) {
    ui->label_username->setText(username);
}


void ActiveUserFrame::on_pushButton_chat_clicked()
{
    emit userClicked(ui->label_username->text());
}

