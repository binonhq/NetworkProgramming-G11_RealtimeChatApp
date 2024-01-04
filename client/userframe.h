#ifndef USERFRAME_H
#define USERFRAME_H

#include <QFrame>

namespace Ui {
class ActiveUserFrame;
}

class UserFrame : public QFrame
{
    Q_OBJECT


public:
    explicit UserFrame(QWidget *parent = nullptr);
    ~UserFrame();

    void setUsername(QString username);
    void hideStatus();
    void hideAddFriendButton();
    void setFriendButton(QString status);

signals:
    void userClicked(const QString &username, QString type);
    void requestAddFriend(const QString &username, QString type);

private slots:
    void on_pushButton_chat_clicked();
    void on_pushButton_addFriend_clicked();
    void on_pushButton_rejectAddFriend_clicked();

private:
    Ui::ActiveUserFrame *ui;
};

#endif // USERFRAME_H
