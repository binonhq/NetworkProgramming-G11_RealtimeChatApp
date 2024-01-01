/********************************************************************************
** Form generated from reading UI file 'chatclient.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATCLIENT_H
#define UI_CHATCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatClient
{
public:
    QLabel *label_username;
    QScrollArea *scrollArea_activeList;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_nameChat;
    QScrollArea *scrollArea_inboxContent;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_input;
    QPushButton *pushButton_sendMsg;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QScrollArea *scrollArea_privateChat;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *pushButton;
    QScrollArea *scrollArea_groupChat;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *pushButton_logout;

    void setupUi(QDialog *ChatClient)
    {
        if (ChatClient->objectName().isEmpty())
            ChatClient->setObjectName("ChatClient");
        ChatClient->resize(1008, 600);
        ChatClient->setStyleSheet(QString::fromUtf8(""));
        label_username = new QLabel(ChatClient);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(20, 20, 781, 24));
        QFont font;
        font.setPointSize(20);
        label_username->setFont(font);
        label_username->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollArea_activeList = new QScrollArea(ChatClient);
        scrollArea_activeList->setObjectName("scrollArea_activeList");
        scrollArea_activeList->setGeometry(QRect(790, 90, 201, 471));
        scrollArea_activeList->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 255, 232);\n"
"border-radius: 5px;\n"
"color:#111111;"));
        scrollArea_activeList->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 201, 471));
        scrollArea_activeList->setWidget(scrollAreaWidgetContents_4);
        label_2 = new QLabel(ChatClient);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(790, 60, 191, 16));
        QFont font1;
        font1.setPointSize(18);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(ChatClient);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(240, 60, 531, 511));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_nameChat = new QLabel(layoutWidget);
        label_nameChat->setObjectName("label_nameChat");
        label_nameChat->setFont(font1);

        verticalLayout->addWidget(label_nameChat);

        scrollArea_inboxContent = new QScrollArea(layoutWidget);
        scrollArea_inboxContent->setObjectName("scrollArea_inboxContent");
        scrollArea_inboxContent->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 255, 232);\n"
"padding:5px;\n"
"border-radius: 5px;\n"
"color:#111111;"));
        scrollArea_inboxContent->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 519, 425));
        scrollArea_inboxContent->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea_inboxContent);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        lineEdit_input = new QLineEdit(layoutWidget);
        lineEdit_input->setObjectName("lineEdit_input");
        lineEdit_input->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 255, 232);\n"
"border-radius: 3px;\n"
"color: #111111;\n"
"padding:2px\n"
""));

        horizontalLayout->addWidget(lineEdit_input);

        pushButton_sendMsg = new QPushButton(layoutWidget);
        pushButton_sendMsg->setObjectName("pushButton_sendMsg");

        horizontalLayout->addWidget(pushButton_sendMsg);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(ChatClient);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 60, 201, 501));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        verticalLayout_2->addWidget(label_4);

        scrollArea_privateChat = new QScrollArea(layoutWidget1);
        scrollArea_privateChat->setObjectName("scrollArea_privateChat");
        scrollArea_privateChat->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 255, 232);\n"
"padding:5px;\n"
"border-radius: 5px;\n"
"color:#111111;"));
        scrollArea_privateChat->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 189, 198));
        scrollArea_privateChat->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea_privateChat);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        scrollArea_groupChat = new QScrollArea(layoutWidget1);
        scrollArea_groupChat->setObjectName("scrollArea_groupChat");
        scrollArea_groupChat->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 255, 232);\n"
"padding:5px;\n"
"border-radius: 5px;\n"
"color:#111111;"));
        scrollArea_groupChat->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 189, 197));
        scrollArea_groupChat->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_2->addWidget(scrollArea_groupChat);

        pushButton_logout = new QPushButton(ChatClient);
        pushButton_logout->setObjectName("pushButton_logout");
        pushButton_logout->setGeometry(QRect(910, 20, 71, 32));

        retranslateUi(ChatClient);

        QMetaObject::connectSlotsByName(ChatClient);
    } // setupUi

    void retranslateUi(QDialog *ChatClient)
    {
        ChatClient->setWindowTitle(QCoreApplication::translate("ChatClient", "Dialog", nullptr));
        label_username->setText(QCoreApplication::translate("ChatClient", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("ChatClient", "Active", nullptr));
        label_nameChat->setText(QCoreApplication::translate("ChatClient", "Chat Room", nullptr));
        pushButton_sendMsg->setText(QCoreApplication::translate("ChatClient", "Send", nullptr));
        label_4->setText(QCoreApplication::translate("ChatClient", "Private Chat", nullptr));
        label_3->setText(QCoreApplication::translate("ChatClient", "Group chat", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatClient", "New group", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("ChatClient", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatClient: public Ui_ChatClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCLIENT_H
