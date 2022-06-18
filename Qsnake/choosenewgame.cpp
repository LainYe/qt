#include "choosenewgame.h"
#include "ui_choosenewgame.h"

ChooseNewGame::ChooseNewGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseNewGame)
{
    ui->setupUi(this);
    _ui = ui;
}

ChooseNewGame::~ChooseNewGame()
{
    delete ui;
}
