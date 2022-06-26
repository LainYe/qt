#include "choosenewgame.h"
#include "ui_choosenewgame.h"

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
        EndlessMode *endlessmode = new EndlessMode(this);
        endlessmode->show();
    });


}

ChooseNewGame::~ChooseNewGame()
{
    delete ui;
}
