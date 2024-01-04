/********************************************************************************
** Form generated from reading UI file 'activeuserframe.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVEUSERFRAME_H
#define UI_ACTIVEUSERFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActiveUserFrame
{
public:
    QLabel *label_username;
    QWidget *widget;
    QPushButton *pushButton_chat;
    QPushButton *pushButton_chat_2;

    void setupUi(QFrame *ActiveUserFrame)
    {
        if (ActiveUserFrame->objectName().isEmpty())
            ActiveUserFrame->setObjectName("ActiveUserFrame");
        ActiveUserFrame->resize(290, 30);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ActiveUserFrame->sizePolicy().hasHeightForWidth());
        ActiveUserFrame->setSizePolicy(sizePolicy);
        ActiveUserFrame->setMinimumSize(QSize(290, 0));
        ActiveUserFrame->setMaximumSize(QSize(290, 30));
        ActiveUserFrame->setStyleSheet(QString::fromUtf8(""));
        label_username = new QLabel(ActiveUserFrame);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(10, 0, 71, 21));
        label_username->setStyleSheet(QString::fromUtf8("color: #ffffff"));
        widget = new QWidget(ActiveUserFrame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 8, 8));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 255, 79);\n"
"border-radius:4px"));
        pushButton_chat = new QPushButton(ActiveUserFrame);
        pushButton_chat->setObjectName("pushButton_chat");
        pushButton_chat->setGeometry(QRect(220, 0, 51, 21));
        QFont font;
        font.setPointSize(10);
        pushButton_chat->setFont(font);
        pushButton_chat->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_chat->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: #1E90FF"));
        pushButton_chat_2 = new QPushButton(ActiveUserFrame);
        pushButton_chat_2->setObjectName("pushButton_chat_2");
        pushButton_chat_2->setGeometry(QRect(140, 0, 71, 21));
        pushButton_chat_2->setFont(font);
        pushButton_chat_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_chat_2->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: #1E90FF"));

        retranslateUi(ActiveUserFrame);

        pushButton_chat->setDefault(true);
        pushButton_chat_2->setDefault(true);


        QMetaObject::connectSlotsByName(ActiveUserFrame);
    } // setupUi

    void retranslateUi(QFrame *ActiveUserFrame)
    {
        ActiveUserFrame->setWindowTitle(QCoreApplication::translate("ActiveUserFrame", "Frame", nullptr));
        label_username->setText(QCoreApplication::translate("ActiveUserFrame", "Username", nullptr));
        pushButton_chat->setText(QCoreApplication::translate("ActiveUserFrame", "Chat", nullptr));
        pushButton_chat_2->setText(QCoreApplication::translate("ActiveUserFrame", "Addfriend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActiveUserFrame: public Ui_ActiveUserFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVEUSERFRAME_H
