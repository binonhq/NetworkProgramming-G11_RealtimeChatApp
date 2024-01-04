/********************************************************************************
** Form generated from reading UI file 'creategroupdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUPDIALOG_H
#define UI_CREATEGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateGroupDialog
{
public:
    QLabel *label_form;
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QLabel *label_2;
    QLabel *GroupName;
    QLineEdit *groupNameLineEdit;
    QPushButton *pushButton_leaveGroup;

    void setupUi(QDialog *CreateGroupDialog)
    {
        if (CreateGroupDialog->objectName().isEmpty())
            CreateGroupDialog->setObjectName("CreateGroupDialog");
        CreateGroupDialog->resize(400, 300);
        label_form = new QLabel(CreateGroupDialog);
        label_form->setObjectName("label_form");
        label_form->setGeometry(QRect(30, 10, 341, 20));
        QFont font;
        font.setBold(true);
        label_form->setFont(font);
        label_form->setTextFormat(Qt::AutoText);
        label_form->setAlignment(Qt::AlignCenter);
        buttonBox = new QDialogButtonBox(CreateGroupDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(220, 250, 151, 32));
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        listWidget = new QListWidget(CreateGroupDialog);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 90, 341, 151));
        listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        label_2 = new QLabel(CreateGroupDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 70, 101, 20));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        GroupName = new QLabel(CreateGroupDialog);
        GroupName->setObjectName("GroupName");
        GroupName->setGeometry(QRect(31, 41, 74, 16));
        groupNameLineEdit = new QLineEdit(CreateGroupDialog);
        groupNameLineEdit->setObjectName("groupNameLineEdit");
        groupNameLineEdit->setGeometry(QRect(113, 41, 251, 21));
        pushButton_leaveGroup = new QPushButton(CreateGroupDialog);
        pushButton_leaveGroup->setObjectName("pushButton_leaveGroup");
        pushButton_leaveGroup->setGeometry(QRect(30, 250, 100, 32));
        pushButton_leaveGroup->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_leaveGroup->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(CreateGroupDialog);

        QMetaObject::connectSlotsByName(CreateGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateGroupDialog)
    {
        CreateGroupDialog->setWindowTitle(QCoreApplication::translate("CreateGroupDialog", "Dialog", nullptr));
        label_form->setText(QCoreApplication::translate("CreateGroupDialog", "CREATE GROUP", nullptr));
        label_2->setText(QCoreApplication::translate("CreateGroupDialog", "Select members", nullptr));
        GroupName->setText(QCoreApplication::translate("CreateGroupDialog", "Group name", nullptr));
        pushButton_leaveGroup->setText(QCoreApplication::translate("CreateGroupDialog", "Leave group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroupDialog: public Ui_CreateGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUPDIALOG_H
