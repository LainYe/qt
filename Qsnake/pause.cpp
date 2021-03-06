#include "pause.h"
#include "ui_pause.h"
#include "readfile.h"
#include "qwaitingdialog.h"
#include <QPushButton>
#include <QTimer>
#include <QPainter>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include "pairmode.h"
# pragma execution_character_set("utf-8")

Pause::Pause(QWidget *parent, int mode) :
    QWidget(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
    resize(800,600);
    if(mode == 1){
        father1 = (EndlessMode*)parent;
        connect(ui->back, &QPushButton::clicked,[=](){
            QWaitingDialog *w = new QWaitingDialog(father1);
            w->Run(3);
            QTimer* timer = new QTimer(this);
            timer->setInterval(3000);
            connect(timer,&QTimer::timeout,[=](){
                father1->pause = 0;
                father1->timer->start();
                father1->timer2->start();
                close();
                delete this;
            });
            timer->start();
        });
        connect(ui->save, &QPushButton::clicked,[=](){
            QString filename = QInputDialog::getText(this,"游戏存档","请输入文件名:");
            //点了cancel，filename是空的
            if(filename.length() == 0){
                return;
            }
            filename = QString("saves\\") + filename + QString(".endless");
            qDebug()<<filename;
            QByteArray arr = filename.toLatin1();
            if(father1->saveFile(arr.data())){
                return;
            }
            father1->pause = 0;
            father1->timer->start();
            father1->timer2->start();
            delete this;
        });
        connect(ui->exit, &QPushButton::clicked,[=](){
            if(QMessageBox::Yes == QMessageBox::question(0,"退出无尽模式","本局游戏将丢失！继续吗")){
                hide();
                father1->hide();
                father1->father->show();
                delete father1;
            }

        });
        connect(ui->read, &QPushButton::clicked,[=](){
            if(QMessageBox::Yes == QMessageBox::question(0,"读档","本局游戏将丢失！继续吗")){
                readFile *readf = new readFile(nullptr,mode);
                readf->father = father1->father;
                delete father1;
                readf->show();
            }
        });
    }
    if(mode == 2){
        father2 = (SingleMode*)parent;
        QTimer* Timer = new QTimer(this);
        Timer->setInterval(100);
        Timer->start();
        connect(Timer,&QTimer::timeout,[=](){
            father2->repaint();
            Timer->setInterval(100);
            Timer->start();
        });
        connect(ui->back, &QPushButton::clicked,[=](){
            QWaitingDialog *w = new QWaitingDialog(father2);
            w->Run(3);
            QTimer* timer = new QTimer(this);
            timer->setInterval(3000);
            connect(timer,&QTimer::timeout,[=](){
                father2->pause = 0;
                father2->timer->start();
                close();
                delete this;
            });
            timer->start();
        });
        connect(ui->save, &QPushButton::clicked,[=](){
            QString filename = QInputDialog::getText(this,"游戏存档","请输入文件名:");
            //点了cancel，filename是空的
            if(filename.length() == 0){
                return;
            }
            filename = QString("saves\\") + filename + QString(".single");
            qDebug()<<filename;
            QByteArray arr = filename.toLatin1();
            if(father2->saveFile(arr.data())){
                return;
            }
            father2->pause = 0;
            father2->timer->start();
            delete this;
        });
        connect(ui->exit, &QPushButton::clicked,[=](){
            if(QMessageBox::Yes == QMessageBox::question(0,"退出单人模式","本局游戏将丢失！继续吗")){
                hide();
                father2->hide();
                father2->father->show();
                delete father2;
            }

        });
        connect(ui->read, &QPushButton::clicked,[=](){
            if(QMessageBox::Yes == QMessageBox::question(0,"读档","本局游戏将丢失！继续吗")){
                readFile *readf = new readFile(nullptr,mode);
                readf->father = father2->father;
                delete father2;
                readf->show();
            }
        });
    }
    if(mode == 3){
        father3 = (PairMode*)parent;
        connect(ui->back, &QPushButton::clicked,[=](){
            QWaitingDialog *w = new QWaitingDialog(father3);
            w->Run(3);
            QTimer* timer = new QTimer(this);
            timer->setInterval(3000);
            connect(timer,&QTimer::timeout,[=](){
                father3->pause = 0;
                father3->timer->start();
                father3->timer2->start();
                father3->timer3->start();
                close();
                delete this;
            });
            timer->start();
        });
        connect(ui->save, &QPushButton::clicked,[=](){
            QString filename = QInputDialog::getText(this,"游戏存档","请输入文件名:");
            //点了cancel，filename是空的
            if(filename.length() == 0){
                return;
            }
            filename = QString("saves\\") + filename + QString(".pair");
            qDebug()<<filename;
            QByteArray arr = filename.toLatin1();
            if(father3->saveFile(arr.data())){
                return;
            }
            father3->pause = 0;
            father3->timer->start();
            father3->timer2->start();
            father3->timer3->start();
            delete this;
        });
        connect(ui->exit, &QPushButton::clicked,[=](){
            if(QMessageBox::Yes == QMessageBox::question(0,"退出双人模式","本局游戏将丢失！继续吗")){
                hide();
                father3->hide();
                father3->father->show();
                delete father3;
            }

        });
        connect(ui->read, &QPushButton::clicked,[=](){
            if(QMessageBox::Yes == QMessageBox::question(0,"读档","本局游戏将丢失！继续吗")){
                readFile *readf = new readFile(nullptr,mode);
                readf->father = father3->father;
                delete father3;
                readf->show();
            }
        });
    }
}

Pause::~Pause()
{
    delete ui;
}


