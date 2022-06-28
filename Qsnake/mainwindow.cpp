#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "choosenewgame.h"
#include "ui_choosenewgame.h"
#include "rules.h"
#include "ui_rules.h"
#include "readfile.h"
#include "endlessmode.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //主界面“新游戏”
    connect(ui->newGame, &QPushButton::clicked,[=](){
        this->hide();
        ChooseNewGame *newgame = new ChooseNewGame();
        newgame->father = this;
        newgame->show();
    } );
    //主界面“退出”
    connect(ui->quit, &QPushButton::clicked,[=](){

        QMessageBox box(QMessageBox::Question,"退出游戏","确定退出吗？",
                        QMessageBox::Yes|QMessageBox::No,this);
        box.setButtonText(QMessageBox::Yes,"退出");
        box.setButtonText(QMessageBox::No,"再想想...");
        int tmp = box.exec();
        if(tmp == QMessageBox::Yes){
           this->close();
        }
        else{
            show();
        }
    });
    //主界面“规则”
    connect(ui->rules, &QPushButton::clicked,[=](){
        this->hide();
        Rules *rule = new Rules();
        rule->father = this;
        rule->show();
    });
    //主界面“读档”
    connect(ui->readFile, &QPushButton::clicked,[=](){
        this->hide();
        readFile *readf = new readFile();
        readf->father = this;
        readf->show();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

