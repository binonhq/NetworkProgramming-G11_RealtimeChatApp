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

    void setupUi(QFrame *ActiveUserFrame)
    {
        if (ActiveUserFrame->objectName().isEmpty())
            ActiveUserFrame->setObjectName("ActiveUserFrame");
        ActiveUserFrame->resize(176, 30);
        ActiveUserFrame->setMaximumSize(QSize(16777215, 30));
        label_username = new QLabel(ActiveUserFrame);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(0, 0, 81, 31));
        label_username->setStyleSheet(QString::fromUtf8("color: #111111;"));
        widget = new QWidget(ActiveUserFrame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 10, 8, 8));
        widget->setStyleSheet(QString::fromUtf8("background-color: #FFD801;border-radius:4px"));
        pushButton_chat = new QPushButton(ActiveUserFrame);
        pushButton_chat->setObjectName("pushButton_chat");
        pushButton_chat->setGeometry(QRect(110, 0, 61, 32));

        retranslateUi(ActiveUserFrame);

        pushButton_chat->setDefault(true);


        QMetaObject::connectSlotsByName(ActiveUserFrame);
    } // setupUi

    void retranslateUi(QFrame *ActiveUserFrame)
    {
        ActiveUserFrame->setWindowTitle(QCoreApplication::translate("ActiveUserFrame", "Frame", nullptr));
        label_username->setText(QCoreApplication::translate("ActiveUserFrame", "Username", nullptr));
        pushButton_chat->setText(QCoreApplication::translate("ActiveUserFrame", "Chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActiveUserFrame: public Ui_ActiveUserFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVEUSERFRAME_H
