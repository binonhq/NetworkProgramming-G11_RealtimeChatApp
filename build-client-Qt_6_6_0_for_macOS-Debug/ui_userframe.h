/********************************************************************************
** Form generated from reading UI file 'userframe.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERFRAME_H
#define UI_USERFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActiveUserFrame
{
public:
    QWidget *widget;
    QPushButton *pushButton_addFriend;
    QPushButton *pushButton_rejectAddFriend;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_active;
    QPushButton *pushButton_chat;

    void setupUi(QFrame *ActiveUserFrame)
    {
        if (ActiveUserFrame->objectName().isEmpty())
            ActiveUserFrame->setObjectName("ActiveUserFrame");
        ActiveUserFrame->resize(260, 32);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ActiveUserFrame->sizePolicy().hasHeightForWidth());
        ActiveUserFrame->setSizePolicy(sizePolicy);
        ActiveUserFrame->setMinimumSize(QSize(260, 32));
        ActiveUserFrame->setMaximumSize(QSize(260, 32));
        ActiveUserFrame->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(ActiveUserFrame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 260, 31));
        widget->setMaximumSize(QSize(260, 16777215));
        widget->setStyleSheet(QString::fromUtf8(""));
        pushButton_addFriend = new QPushButton(widget);
        pushButton_addFriend->setObjectName("pushButton_addFriend");
        pushButton_addFriend->setGeometry(QRect(180, 0, 71, 20));
        QFont font;
        font.setPointSize(10);
        pushButton_addFriend->setFont(font);
        pushButton_addFriend->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_addFriend->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: #1E90FF;\n"
"border-radius: 3px;"));
        pushButton_rejectAddFriend = new QPushButton(widget);
        pushButton_rejectAddFriend->setObjectName("pushButton_rejectAddFriend");
        pushButton_rejectAddFriend->setGeometry(QRect(100, 0, 71, 20));
        pushButton_rejectAddFriend->setFont(font);
        pushButton_rejectAddFriend->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_rejectAddFriend->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: rgb(255, 27, 30);\n"
"border-radius: 3px;"));
        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(0, 0, 101, 22));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_active = new QLabel(widget1);
        label_active->setObjectName("label_active");
        label_active->setMaximumSize(QSize(8, 8));
        label_active->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 255, 130);\n"
"border-radius: 4px;"));

        horizontalLayout->addWidget(label_active);

        pushButton_chat = new QPushButton(widget1);
        pushButton_chat->setObjectName("pushButton_chat");
        QFont font1;
        font1.setPointSize(13);
        pushButton_chat->setFont(font1);
        pushButton_chat->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_chat->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: transparent;\n"
"text-align: left;\n"
"border: 0px;\n"
"padding-left:2px;"));

        horizontalLayout->addWidget(pushButton_chat);


        retranslateUi(ActiveUserFrame);

        pushButton_addFriend->setDefault(true);
        pushButton_rejectAddFriend->setDefault(true);
        pushButton_chat->setDefault(true);


        QMetaObject::connectSlotsByName(ActiveUserFrame);
    } // setupUi

    void retranslateUi(QFrame *ActiveUserFrame)
    {
        ActiveUserFrame->setWindowTitle(QCoreApplication::translate("ActiveUserFrame", "Frame", nullptr));
        pushButton_addFriend->setText(QCoreApplication::translate("ActiveUserFrame", "Add friend", nullptr));
        pushButton_rejectAddFriend->setText(QCoreApplication::translate("ActiveUserFrame", "Reject", nullptr));
        label_active->setText(QString());
        pushButton_chat->setText(QCoreApplication::translate("ActiveUserFrame", "Chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActiveUserFrame: public Ui_ActiveUserFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFRAME_H
