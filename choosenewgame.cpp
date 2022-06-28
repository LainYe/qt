#include "choosenewgame.h"
#include "ui_choosenewgame.h"
#include "QMessageBox"

# pragma execution_character_set("utf-8")

ChooseNewGame::ChooseNewGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseNewGame)
{
    ui->setupUi(this);
    //新游戏“back”
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        hide();
        father->show();
    } );
    //新游戏“无尽模式”
    connect(ui->endlessmode, &QPushButton::clicked,[=](){
        hide();
        QMessageBox box(QMessageBox::Question,"进入无尽模式","无尽模式：去获得尽可能高的分数！",
                        QMessageBox::Yes|QMessageBox::No,this);
        box.setButtonText(QMessageBox::Yes,"进入游戏！");
        box.setButtonText(QMessageBox::No,"再想想...");
        int tmp = box.exec();
        if(tmp == QMessageBox::Yes){
            EndlessMode *endlessmode = new EndlessMode(this);
            endlessmode->show();
        }
        else{
            show();
        }
    });
    //新游戏“单人模式”
    connect(ui->singlemode, &QPushButton::clicked,[=](){
        hide();
        QMessageBox box(QMessageBox::Question,"进入单人模式","单人模式：活下去，获得尽可能高的分数！",
                        QMessageBox::Yes|QMessageBox::No,this);
        box.setButtonText(QMessageBox::Yes,"进入游戏！");
        box.setButtonText(QMessageBox::No,"再想想...");
        int tmp = box.exec();
        if(tmp == QMessageBox::Yes){
            SingleMode *singlemode = new SingleMode(this);
            singlemode->show();
        }
        else{
            show();
        }
    });

}

ChooseNewGame::~ChooseNewGame()
{
    delete ui;
}
