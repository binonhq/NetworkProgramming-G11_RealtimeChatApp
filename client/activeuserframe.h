#ifndef ACTIVEUSERFRAME_H
#define ACTIVEUSERFRAME_H

#include <QFrame>

namespace Ui {
class ActiveUserFrame;
}

class ActiveUserFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ActiveUserFrame(QWidget *parent = nullptr);
    ~ActiveUserFrame();

    void setUsername(QString username);

signals:
    void userClicked(const QString &username);

private slots:
    void on_pushButton_chat_clicked();

private:
    Ui::ActiveUserFrame *ui;
};

#endif // ACTIVEUSERFRAME_H
