#ifndef CREATEGROUPDIALOG_H
#define CREATEGROUPDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class CreateGroupDialog;
}

class CreateGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGroupDialog(QWidget *parent = nullptr);
    ~CreateGroupDialog();

    void set_user_list(QStringList users);
    void set_group_name(QString name);
    void set_members(QStringList members);
    void on_manage_group(QString groupName, QStringList members);

signals:
    void createGroup(QString groupName, QStringList members);
    void updateGroup(QString groupName, QStringList members);
    void leaveGroup(const QString groupName);

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void on_pushButton_leaveGroup_clicked();

private:
    Ui::CreateGroupDialog *ui;
};

#endif // CREATEGROUPDIALOG_H
