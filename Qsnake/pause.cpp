#include "pause.h"
#include "ui_pause.h"
#include <QPushButton>
#include <QTimer>
Pause::Pause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
    father = (EndlessMode*)parent;
    resize(800,600);
    connect(ui->back, &QPushButton::clicked,[=](){
        parent->show();
        this->hide();
        father->pause = 0;
        father->timer->start();
        father->timer2->start();
    });
    connect(ui->save, &QPushButton::clicked,[=](){
        father->saveFile("endlessmode_game.txt");
        hide();
        father->hide();
        father->father->show();
        delete father;
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
