﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "choosenewgame.h"
#include "ui_choosenewgame.h"
#include "rules.h"
#include "ui_rules.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ChooseNewGame *newgame = new ChooseNewGame();
    Rules *rule = new Rules();
    //主界面“新游戏”
    connect(ui->newGame, &QPushButton::clicked,[=](){
        this->hide();
        newgame->show();
    } );
    //主界面“退出”
    connect(ui->quit, &QPushButton::clicked,[=](){
        this->close();
    });
    //主界面“规则”
    connect(ui->rules, &QPushButton::clicked,[=](){
        this->hide();
        rule->show();
    });
    //新游戏“back”
    connect(newgame->_ui->pushButton_4,&QPushButton::clicked,[=](){
        newgame->hide();
        this->show();
    } );
    //规则“back”
    connect(rule->_ui->back,&QPushButton::clicked,[=](){
        rule->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

