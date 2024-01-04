/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLineEdit *lineEdit_password;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_register;
    QPushButton *pushButton_login;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QLabel *label_2;
    QLineEdit *lineEdit_cfPassword;
    QLabel *label_4;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(800, 600);
        lineEdit_password = new QLineEdit(RegisterDialog);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(317, 231, 291, 21));
        lineEdit_password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        lineEdit_password->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(RegisterDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 231, 58, 16));
        verticalLayoutWidget_2 = new QWidget(RegisterDialog);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(199, 287, 411, 66));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_register = new QPushButton(verticalLayoutWidget_2);
        pushButton_register->setObjectName("pushButton_register");

        verticalLayout_3->addWidget(pushButton_register);

        pushButton_login = new QPushButton(verticalLayoutWidget_2);
        pushButton_login->setObjectName("pushButton_login");

        verticalLayout_3->addWidget(pushButton_login);

        label = new QLabel(RegisterDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(199, 137, 411, 42));
        QFont font;
        font.setPointSize(35);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        lineEdit_username = new QLineEdit(RegisterDialog);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(317, 200, 291, 21));
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 200, 61, 16));
        lineEdit_cfPassword = new QLineEdit(RegisterDialog);
        lineEdit_cfPassword->setObjectName("lineEdit_cfPassword");
        lineEdit_cfPassword->setGeometry(QRect(317, 262, 291, 21));
        lineEdit_cfPassword->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        lineEdit_cfPassword->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(RegisterDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 262, 109, 16));
        QWidget::setTabOrder(lineEdit_username, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, lineEdit_cfPassword);
        QWidget::setTabOrder(lineEdit_cfPassword, pushButton_register);
        QWidget::setTabOrder(pushButton_register, pushButton_login);

        retranslateUi(RegisterDialog);

        pushButton_register->setDefault(true);


        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterDialog", "Password", nullptr));
        pushButton_register->setText(QCoreApplication::translate("RegisterDialog", "Register", nullptr));
        pushButton_login->setText(QCoreApplication::translate("RegisterDialog", "Already have an account? Login", nullptr));
        label->setText(QCoreApplication::translate("RegisterDialog", "REGISTER", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterDialog", "Username", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterDialog", "Confirm password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
