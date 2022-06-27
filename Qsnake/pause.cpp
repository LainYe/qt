#include "pause.h"
#include "ui_pause.h"
#include <QPushButton>
#include <QTimer>
#include <QInputDialog>
#include <QString>
#include <QByteArray>
#include <QDebug>

# pragma execution_character_set("utf-8")

Pause::Pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
    father = (EndlessMode*)parent;
    resize(800,600);
    connect(ui->back, &QPushButton::clicked,[=](){
        father->pause = 0;
        father->timer->start();
        father->timer2->start();
        close();
        delete this;
    });
    connect(ui->save, &QPushButton::clicked,[=](){
        QString filename = QInputDialog::getText(this,"游戏存档","请输入文件名:");
        QByteArray arr = filename.toLatin1();
        father->saveFile(arr.data());
        father->pause = 0;
        father->timer->start();
        father->timer2->start();
        delete this;
    });
    connect(ui->exit, &QPushButton::clicked,[=](){
        hide();
        father->hide();
        father->father->show();
        delete father;
    });

}

Pause::~Pause()
{
    delete ui;
}
