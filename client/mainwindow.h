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
    void log_out(QString username);
    void send_private_chat(QString message);

private:
    Ui::MainWindow *ui;
    RegisterDialog registerDialog;
    ChatClient chatClient;
    Client client;
};
#endif // MAINWINDOW_H
