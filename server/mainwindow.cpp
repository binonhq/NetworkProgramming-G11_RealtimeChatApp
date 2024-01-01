#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&server, SIGNAL(logReceived(QString)), this, SLOT(addLog(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addLog(QString log){
    QString data = "[" + QTime::currentTime().toString() + "] " + log;
    qDebug() << data;
    ui->listWidget_log->addItem(data);
    this->repaint();
    qApp->processEvents();
}


