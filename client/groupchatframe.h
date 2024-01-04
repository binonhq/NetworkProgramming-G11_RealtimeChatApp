#ifndef GROUPCHATFRAME_H
#define GROUPCHATFRAME_H

#include <QFrame>

namespace Ui {
class GroupChatFrame;
}

class GroupChatFrame : public QFrame
{
    Q_OBJECT

public:
    explicit GroupChatFrame(QWidget *parent = nullptr);
    ~GroupChatFrame();
    
    void setGroupName(QString name);

signals:
    void userClicked(const QString &groupName, QString type);
    void manageGroup(const QString &groupName);

private slots:
    void on_pushButton_chat_clicked();
    void on_pushButton_manage_clicked();

private:
    Ui::GroupChatFrame *ui;
};

#endif // GROUPCHATFRAME_H
