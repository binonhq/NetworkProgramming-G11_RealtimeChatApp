/********************************************************************************
** Form generated from reading UI file 'groupchatframe.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATFRAME_H
#define UI_GROUPCHATFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GroupChatFrame
{
public:
    QPushButton *pushButton_chat;
    QPushButton *pushButton_manage;

    void setupUi(QFrame *GroupChatFrame)
    {
        if (GroupChatFrame->objectName().isEmpty())
            GroupChatFrame->setObjectName("GroupChatFrame");
        GroupChatFrame->resize(243, 25);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GroupChatFrame->sizePolicy().hasHeightForWidth());
        GroupChatFrame->setSizePolicy(sizePolicy);
        GroupChatFrame->setMinimumSize(QSize(243, 25));
        GroupChatFrame->setMaximumSize(QSize(243, 25));
        pushButton_chat = new QPushButton(GroupChatFrame);
        pushButton_chat->setObjectName("pushButton_chat");
        pushButton_chat->setGeometry(QRect(10, 0, 171, 21));
        QFont font;
        font.setPointSize(13);
        pushButton_chat->setFont(font);
        pushButton_chat->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_chat->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: transparent;\n"
"text-align: left;"));
        pushButton_manage = new QPushButton(GroupChatFrame);
        pushButton_manage->setObjectName("pushButton_manage");
        pushButton_manage->setGeometry(QRect(190, 0, 51, 21));
        QFont font1;
        font1.setPointSize(10);
        pushButton_manage->setFont(font1);
        pushButton_manage->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_manage->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: #1E90FF"));

        retranslateUi(GroupChatFrame);

        pushButton_chat->setDefault(true);
        pushButton_manage->setDefault(true);


        QMetaObject::connectSlotsByName(GroupChatFrame);
    } // setupUi

    void retranslateUi(QFrame *GroupChatFrame)
    {
        GroupChatFrame->setWindowTitle(QCoreApplication::translate("GroupChatFrame", "Frame", nullptr));
        pushButton_chat->setText(QCoreApplication::translate("GroupChatFrame", "Chat", nullptr));
        pushButton_manage->setText(QCoreApplication::translate("GroupChatFrame", "Manage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupChatFrame: public Ui_GroupChatFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATFRAME_H
