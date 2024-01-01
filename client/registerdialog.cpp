#include "registerdialog.h"
#include "ui_registerdialog.h"
//#include "Response.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_pushButton_login_clicked()
{
    hide();
    emit logIn();
}


void RegisterDialog::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString cfPassword = ui->lineEdit_cfPassword->text();

    if (password != cfPassword) {
        QMessageBox::warning(this, "Register fail!", "Confirm password isn't match password.");
        return;
    }

    emit registerReq(username, password);
    return;
}

void RegisterDialog::register_success(){
    QMessageBox::warning(this, "Register successful!", "You can login into your account now.");
    return;
}

void RegisterDialog::register_failure(){
    QMessageBox::warning(this, "Register fail!", "Username existed!");
    return;
}
