#include "direct.h"
#include "readfile.h"
#include "ui_readfile.h"
#include "QPushButton"
#include "QFileDialog"
#include "QString"
#include "cstring"
#include "iostream"
#include "fstream"
#include <QMessageBox>
#include "endlessmode.h"
#include "singlemode.h"
#include "QDebug"
#include "QByteArray"
#include "QFile"
#include "pairmode.h"

using namespace std;
# pragma execution_character_set("utf-8")

readFile::readFile(QWidget *parent, int mode) :
    QWidget(parent),
    ui(new Ui::readFile)
{
    ui->setupUi(this);
    connect(ui->back, &QPushButton::clicked,[=](){
        hide();
        father->show();
    });
    connect(ui->choosefile, &QPushButton::clicked,[=](){
        if(mode == 1){
            QString filepath = QFileDialog::getOpenFileName(this,"请选择游戏存档","saves\\","(*endless)");
            QString dirpath = QDir::currentPath();
            filepath = filepath.mid(dirpath.length()+1);
            filepath = filepath.mid(6);//去掉"saves/"
            filepath = QString("saves\\\\") + filepath;
            QByteArray a = filepath.toLatin1();
            char* filename = a.data();
            qDebug()<<filename;

            fstream infile(filename,ios::in);
            if(infile){
                this->hide();
                EndlessMode *endlessmode = new EndlessMode(this->father);
                infile.get();
                infile >> endlessmode->board->score;
                int maxscore;
                infile >> maxscore;
                if(endlessmode->board->maxScore<maxscore)
                {
                    endlessmode->board->maxScore=maxscore;
                }
                infile >> endlessmode->board->move_interval;
                infile >> endlessmode->board->food_interval;
                infile >> endlessmode->board->length;
                for(int i = 0; i < 500; ++i)
                {
                    for(int j = 0; j < 500; ++j)
                    {
                        infile >> endlessmode->board->map[i][j];
                    }
                }
                infile >> endlessmode->board->snake->len;
                for(int i = 0; i < endlessmode->board->snake->len; ++i)
                {
                    infile >> endlessmode->board->snake->s[i][0] >> endlessmode->board->snake->s[i][1];
                }
                infile >> endlessmode->board->snake->dx;
                infile >> endlessmode->board->snake->dy;
                if(endlessmode->board->snake2)
                {
                    infile >> endlessmode->board->snake2->len;
                    for(int i = 0; i < endlessmode->board->snake2->len; ++i)
                    {
                        infile >> endlessmode->board->snake2->s[i][0] >> endlessmode->board->snake2->s[i][1];
                    }
                    infile >> endlessmode->board->snake2->dx;
                    infile >> endlessmode->board->snake2->dy;
                }
                infile.close();
                endlessmode->show();
            }
        }
        else if(mode == 2){
            QString filepath = QFileDialog::getOpenFileName(this,"请选择游戏存档","saves\\","(*single)");
            QString dirpath = QDir::currentPath();
            filepath = filepath.mid(dirpath.length()+1);
            filepath = filepath.mid(6);//去掉"saves/"
            filepath = QString("saves\\\\") + filepath;
            QByteArray a = filepath.toLatin1();
            char* filename = a.data();
            qDebug()<<filename;

            fstream infile(filename,ios::in);
            if(infile){
                this->hide();
                infile.get();//mode
                int dead_time;
                infile >> dead_time;
                SingleMode *singlemode = new SingleMode(this->father,dead_time);
                infile >> singlemode->level;
                infile >> singlemode->board->score;
                int maxscore;
                infile >> maxscore;
                if(singlemode->board->maxScore<maxscore)
                {
                    singlemode->board->maxScore=maxscore;
                }
                infile >> singlemode->board->move_interval;
                infile >> singlemode->board->length;
                for(int i = 0; i < 500; ++i)
                {
                    for(int j = 0; j < 500; ++j)
                    {
                        infile >> singlemode->board->map[i][j];
                    }
                }
                infile >> singlemode->board->snake->total_len;
                infile >> singlemode->board->snake->len;
                for(int i = 0; i < singlemode->board->snake->len; ++i)
                {
                    infile >> singlemode->board->snake->s[i][0] >> singlemode->board->snake->s[i][1];
                }
                infile >> singlemode->board->snake->dx;
                infile >> singlemode->board->snake->dy;
                infile.close();
                singlemode->show();
            }
        }
        else if(mode == 3){
            QString filepath = QFileDialog::getOpenFileName(this,"请选择游戏存档","saves\\","(*pair)");
            QString dirpath = QDir::currentPath();
            filepath = filepath.mid(dirpath.length()+1);
            filepath = filepath.mid(6);//去掉"saves/"
            filepath = QString("saves\\\\") + filepath;
            QByteArray a = filepath.toLatin1();
            char* filename = a.data();
            qDebug()<<filename;

            fstream infile(filename,ios::in);
            if(infile){
                this->hide();
                PairMode *pairmode = new PairMode(this->father);
                infile.get();
                infile >> pairmode->board->score;
                int maxscore;
                infile >> maxscore;
                if(pairmode->board->maxScore<maxscore)
                {
                    pairmode->board->maxScore=maxscore;
                }
                infile >> pairmode->board->move_interval;
                infile >> pairmode->board->food_interval;
                infile >> pairmode->board->length;
                infile >>pairmode->value;
                for(int i = 0; i < 500; ++i)
                {
                    for(int j = 0; j < 500; ++j)
                    {
                        infile >> pairmode->board->map[i][j];
                    }
                }
                infile >> pairmode->board->snake->len;
                for(int i = 0; i < pairmode->board->snake->len; ++i)
                {
                    infile >> pairmode->board->snake->s[i][0] >> pairmode->board->snake->s[i][1];
                }
                infile >> pairmode->board->snake->dx;
                infile >> pairmode->board->snake->dy;

                    infile >> pairmode->board->snake2->len;
                    for(int i = 0; i < pairmode->board->snake2->len; ++i)
                    {
                        infile >> pairmode->board->snake2->s[i][0] >> pairmode->board->snake2->s[i][1];
                    }
                    infile >> pairmode->board->snake2->dx;
                    infile >> pairmode->board->snake2->dy;

                infile.close();
                pairmode->show();
            }
        }
        else if(mode==0)
        {

            QString filepath = QFileDialog::getOpenFileName(this,"请选择游戏存档","saves\\",
                                                            "ALL FILES(*.endless *.single *.pair);;ENDLESS(*.endless);;SINGLE(*.single);;PAIR(*.pair)");
            QString dirpath = QDir::currentPath();
            filepath = filepath.mid(dirpath.length()+1);
            filepath = filepath.mid(6);//去掉"saves/"
            filepath = QString("saves\\\\") + filepath;
            QByteArray a = filepath.toLatin1();
            char* filename = a.data();
            qDebug()<<filename;
            fstream infile(filename,ios::in);
            if(infile){
                this->hide();
                int temp_mode;
                infile>>temp_mode;
                if(temp_mode==1)
                {
                    EndlessMode *endlessmode = new EndlessMode(this->father);
                    infile >> endlessmode->board->score;
                    int maxscore;
                    infile >> maxscore;
                    if(endlessmode->board->maxScore<maxscore)
                    {
                        endlessmode->board->maxScore=maxscore;
                    }
                    infile >> endlessmode->board->move_interval;
                    infile >> endlessmode->board->food_interval;
                    infile >> endlessmode->board->length;
                    for(int i = 0; i < 500; ++i)
                    {
                        for(int j = 0; j < 500; ++j)
                        {
                            infile >> endlessmode->board->map[i][j];
                        }
                    }
                    infile >> endlessmode->board->snake->len;
                    for(int i = 0; i < endlessmode->board->snake->len; ++i)
                    {
                        infile >> endlessmode->board->snake->s[i][0] >> endlessmode->board->snake->s[i][1];
                    }
                    infile >> endlessmode->board->snake->dx;
                    infile >> endlessmode->board->snake->dy;
                    infile.close();
                    endlessmode->show();
                }
                else if(temp_mode==2)
                {
                    int dead_time;
                    infile >> dead_time;
                    SingleMode *singlemode = new SingleMode(this->father,dead_time);
                    infile >> singlemode->level;
                    infile >> singlemode->board->score;
                    int maxscore;
                    infile >> maxscore;
                    if(singlemode->board->maxScore<maxscore)
                    {
                        singlemode->board->maxScore=maxscore;
                    }
                    infile >> singlemode->board->move_interval;
                    infile >> singlemode->board->length;
                    for(int i = 0; i < 500; ++i)
                    {
                        for(int j = 0; j < 500; ++j)
                        {
                            infile >> singlemode->board->map[i][j];
                        }
                    }
                    infile >> singlemode->board->snake->total_len;
                    infile >> singlemode->board->snake->len;
                    for(int i = 0; i < singlemode->board->snake->len; ++i)
                    {
                        infile >> singlemode->board->snake->s[i][0] >> singlemode->board->snake->s[i][1];
                    }
                    infile >> singlemode->board->snake->dx;
                    infile >> singlemode->board->snake->dy;
                    infile.close();
                    singlemode->show();
                }
                else if(temp_mode==3)
                {
                    PairMode *pairmode = new PairMode(this->father);
                    infile >> pairmode->board->score;
                    int maxscore;
                    infile >> maxscore;
                    if(pairmode->board->maxScore<maxscore)
                    {
                        pairmode->board->maxScore=maxscore;
                    }
                    infile >> pairmode->board->move_interval;
                    infile >> pairmode->board->food_interval;
                    infile >> pairmode->board->length;
                    infile >> pairmode->value;
                    for(int i = 0; i < 500; ++i)
                    {
                        for(int j = 0; j < 500; ++j)
                        {
                            infile >> pairmode->board->map[i][j];
                        }
                    }
                    infile >> pairmode->board->snake->len;
                    for(int i = 0; i < pairmode->board->snake->len; ++i)
                    {
                        infile >> pairmode->board->snake->s[i][0] >> pairmode->board->snake->s[i][1];
                    }
                    infile >> pairmode->board->snake->dx;
                    infile >> pairmode->board->snake->dy;
                    infile >> pairmode->board->snake2->len;
                    for(int i = 0; i < pairmode->board->snake2->len; ++i)
                    {
                        infile >> pairmode->board->snake2->s[i][0] >> pairmode->board->snake2->s[i][1];
                    }
                    infile >> pairmode->board->snake2->dx;
                    infile >> pairmode->board->snake2->dy;
                    infile.close();
                    pairmode->show();
                }


            }
        }
    });
}

readFile::~readFile()
{
    delete ui;
}
