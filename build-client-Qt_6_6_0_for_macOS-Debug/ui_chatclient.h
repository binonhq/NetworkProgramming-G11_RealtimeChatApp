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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatClient
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QListWidget *listWidget_notifications;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *pushButton_createGroup;
    QScrollArea *scrollArea_groups;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_nameChat;
    QLabel *label_type;
    QListWidget *listWidget_inbox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_input;
    QPushButton *pushButton_sendMsg;
    QLabel *label_username;
    QPushButton *pushButton_logout;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QScrollArea *scrollArea_activeList;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QScrollArea *scrollArea_allUsers;
    QWidget *scrollAreaWidgetContents_3;

    void setupUi(QDialog *ChatClient)
    {
        if (ChatClient->objectName().isEmpty())
            ChatClient->setObjectName("ChatClient");
        ChatClient->resize(1273, 817);
        ChatClient->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(ChatClient);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 30, 1231, 751));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 50, 294, 681));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        QFont font;
        font.setPointSize(18);
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        listWidget_notifications = new QListWidget(layoutWidget);
        listWidget_notifications->setObjectName("listWidget_notifications");

        verticalLayout_2->addWidget(listWidget_notifications);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        pushButton_createGroup = new QPushButton(layoutWidget);
        pushButton_createGroup->setObjectName("pushButton_createGroup");
        pushButton_createGroup->setAutoDefault(false);

        horizontalLayout_3->addWidget(pushButton_createGroup);


        verticalLayout_2->addLayout(horizontalLayout_3);

        scrollArea_groups = new QScrollArea(layoutWidget);
        scrollArea_groups->setObjectName("scrollArea_groups");
        scrollArea_groups->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_groups->setStyleSheet(QString::fromUtf8("background-color:rgb(24, 24, 24);\n"
"border-radius: 5px;\n"
"color: #111111;\n"
"padding:2px;"));
        scrollArea_groups->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 288, 293));
        scrollArea_groups->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea_groups);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(340, 50, 521, 681));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        label_nameChat = new QLabel(layoutWidget1);
        label_nameChat->setObjectName("label_nameChat");
        label_nameChat->setFont(font);
        label_nameChat->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_nameChat);

        label_type = new QLabel(layoutWidget1);
        label_type->setObjectName("label_type");
        label_type->setFont(font);
        label_type->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_type);


        verticalLayout->addLayout(horizontalLayout_4);

        listWidget_inbox = new QListWidget(layoutWidget1);
        new QListWidgetItem(listWidget_inbox);
        new QListWidgetItem(listWidget_inbox);
        new QListWidgetItem(listWidget_inbox);
        new QListWidgetItem(listWidget_inbox);
        new QListWidgetItem(listWidget_inbox);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_inbox);
        __qlistwidgetitem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        listWidget_inbox->setObjectName("listWidget_inbox");

        verticalLayout->addWidget(listWidget_inbox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        lineEdit_input = new QLineEdit(layoutWidget1);
        lineEdit_input->setObjectName("lineEdit_input");
        lineEdit_input->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 255, 232);\n"
"border-radius: 3px;\n"
"color: #111111;\n"
"padding:4px\n"
""));

        horizontalLayout->addWidget(lineEdit_input);

        pushButton_sendMsg = new QPushButton(layoutWidget1);
        pushButton_sendMsg->setObjectName("pushButton_sendMsg");
        pushButton_sendMsg->setStyleSheet(QString::fromUtf8(""));
        pushButton_sendMsg->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_sendMsg);


        verticalLayout->addLayout(horizontalLayout);

        label_username = new QLabel(groupBox);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(10, 10, 781, 24));
        QFont font1;
        font1.setPointSize(20);
        label_username->setFont(font1);
        label_username->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_logout = new QPushButton(groupBox);
        pushButton_logout->setObjectName("pushButton_logout");
        pushButton_logout->setGeometry(QRect(1060, 10, 141, 32));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(880, 50, 321, 671));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        scrollArea_activeList = new QScrollArea(layoutWidget2);
        scrollArea_activeList->setObjectName("scrollArea_activeList");
        scrollArea_activeList->setStyleSheet(QString::fromUtf8("background-color:rgb(24, 24, 24);\n"
"border-radius: 5px;\n"
"color: #111111;\n"
"padding:2px;"));
        scrollArea_activeList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_activeList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 315, 296));
        scrollArea_activeList->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea_activeList);

        label = new QLabel(layoutWidget2);
        label->setObjectName("label");
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        scrollArea_allUsers = new QScrollArea(layoutWidget2);
        scrollArea_allUsers->setObjectName("scrollArea_allUsers");
        scrollArea_allUsers->setStyleSheet(QString::fromUtf8("background-color:rgb(24, 24, 24);\n"
"border-radius: 5px;\n"
"color: #111111;\n"
"padding:2px;"));
        scrollArea_allUsers->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_allUsers->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_allUsers->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 315, 295));
        scrollArea_allUsers->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_3->addWidget(scrollArea_allUsers);

        QWidget::setTabOrder(pushButton_sendMsg, lineEdit_input);
        QWidget::setTabOrder(lineEdit_input, pushButton_createGroup);
        QWidget::setTabOrder(pushButton_createGroup, listWidget_inbox);
        QWidget::setTabOrder(listWidget_inbox, scrollArea_activeList);
        QWidget::setTabOrder(scrollArea_activeList, scrollArea_allUsers);
        QWidget::setTabOrder(scrollArea_allUsers, scrollArea_groups);
        QWidget::setTabOrder(scrollArea_groups, listWidget_notifications);
        QWidget::setTabOrder(listWidget_notifications, pushButton_logout);

        retranslateUi(ChatClient);

        pushButton_createGroup->setDefault(true);
        pushButton_sendMsg->setDefault(true);


        QMetaObject::connectSlotsByName(ChatClient);
    } // setupUi

    void retranslateUi(QDialog *ChatClient)
    {
        ChatClient->setWindowTitle(QCoreApplication::translate("ChatClient", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("ChatClient", "Notifications", nullptr));
        label_3->setText(QCoreApplication::translate("ChatClient", "Group chats", nullptr));
        pushButton_createGroup->setText(QCoreApplication::translate("ChatClient", "New group", nullptr));
        label_nameChat->setText(QCoreApplication::translate("ChatClient", "Chat Room", nullptr));
        label_type->setText(QCoreApplication::translate("ChatClient", "Type", nullptr));

        const bool __sortingEnabled = listWidget_inbox->isSortingEnabled();
        listWidget_inbox->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_inbox->item(4);
        ___qlistwidgetitem->setText(QCoreApplication::translate("ChatClient", "==================          REALTIME CHAT APPLICATION        =================", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_inbox->item(5);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("ChatClient", "---------------------SELECT A USER OR GROUP TO START CHATTING -----------------", nullptr));
        listWidget_inbox->setSortingEnabled(__sortingEnabled);

        pushButton_sendMsg->setText(QCoreApplication::translate("ChatClient", "Send", nullptr));
        label_username->setText(QCoreApplication::translate("ChatClient", "Username", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("ChatClient", "Log out", nullptr));
        label_2->setText(QCoreApplication::translate("ChatClient", "Active", nullptr));
        label->setText(QCoreApplication::translate("ChatClient", "All Users", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatClient: public Ui_ChatClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCLIENT_H
