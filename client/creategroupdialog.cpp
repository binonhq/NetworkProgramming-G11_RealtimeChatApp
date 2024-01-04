#include "creategroupdialog.h"
#include "ui_creategroupdialog.h"

CreateGroupDialog::CreateGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGroupDialog)
{
    ui->setupUi(this);
    ui->pushButton_leaveGroup->hide();
}

CreateGroupDialog::~CreateGroupDialog()
{
    delete ui;
}

void CreateGroupDialog::on_buttonBox_rejected()
{
    this->close();
}

void CreateGroupDialog::set_user_list(QStringList users){
    ui->listWidget->addItems(users);
}

void CreateGroupDialog::set_group_name(QString name){
    ui->groupNameLineEdit->setText(name);
}

void CreateGroupDialog::set_members(QStringList members){
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (members.contains(item->text())) {
            item->setSelected(true);
        }
    }
}

void CreateGroupDialog::on_buttonBox_accepted()
{
    if (ui->label_form->text() == "CREATE GROUP"){
        QString groupName = ui->groupNameLineEdit->text();
        QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();

        if(groupName == "") {
            QMessageBox::warning(this, "Create group fail!", "Please input group name!");
            return;
        }
        if(selectedItems.length() < 2) {
            QMessageBox::warning(this, "Create group fail!", "Please select more than 1 members");
            return;
        }

        QStringList members;

        for (QListWidgetItem *item : selectedItems) {
            members << item->text();
        }

        emit createGroup(groupName, members);

        QMessageBox::information(this, "Create group success!", "Create group success!");
        close();

        return;
    }

    if (ui->label_form->text() == "MANAGE GROUP"){
        QString groupName = ui->groupNameLineEdit->text();
        QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();

        if(selectedItems.length() < 2) {
            QMessageBox::warning(this, "Create group fail!", "Please select more than 1 members");
            return;
        }

        QStringList members;

        for (QListWidgetItem *item : selectedItems) {
            members << item->text();
        }

        emit updateGroup(groupName, members);

        QMessageBox::information(this, "Update group success!", "Update group success!");
        close();

        return;
    }
}

void CreateGroupDialog::on_manage_group(QString groupName, QStringList members){
    ui->groupNameLineEdit->setText(groupName);
    ui->groupNameLineEdit->setDisabled(true);
    ui->label_form->setText("MANAGE GROUP");
    ui->pushButton_leaveGroup->show();
    
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (members.contains(item->text())) {
            item->setSelected(true);
        }
    }
}

void CreateGroupDialog::on_pushButton_leaveGroup_clicked()
{
    emit leaveGroup(ui->groupNameLineEdit->text());
    close();
    QMessageBox::information(this, "Leave group!", "Leave group success!");
}

