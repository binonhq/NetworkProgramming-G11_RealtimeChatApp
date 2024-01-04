#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <registerdialog.h>
#include <chatclient.h>
#include <client.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void show_main();
    void login_failure();
    void login_success(QString username);
    void on_pushButton_register_clicked();
    void on_pushButton_login_clicked();
    void register_request(QString username, QString password);
    void get_all_users();


    void send_private_chat(QString message);
    void get_private_history();

    void create_group(QString nameGroup ,QStringList members);
    void get_group_history();
    void send_group_chat(QString message);
    void request_manage_group(const QString groupName);
    void request_leave_group(const QString groupName);
    void request_update_group(const QString groupName, QStringList members);

    void request_add_friend(const QString username, QString type);
    void log_out(QString username);

private:
    Ui::MainWindow *ui;
    RegisterDialog registerDialog;
    ChatClient chatClient;
    Client client;
};
#endif // MAINWINDOW_H
