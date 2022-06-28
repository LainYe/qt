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
                infile >> endlessmode->board->maxScore;
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
                SingleMode *singlemode = new SingleMode(this->father);
                infile.get();
                infile >> singlemode->board->score;
                infile >> singlemode->board->maxScore;
                infile >> singlemode->board->move_interval;
                infile >> singlemode->board->food_interval;
                infile >> singlemode->board->length;
                for(int i = 0; i < 500; ++i)
                {
                    for(int j = 0; j < 500; ++j)
                    {
                        infile >> singlemode->board->map[i][j];
                    }
                }
                infile >> singlemode->board->snake->len;
                for(int i = 0; i < singlemode->board->snake->len; ++i)
                {
                    infile >> singlemode->board->snake->s[i][0] >> singlemode->board->snake->s[i][1];
                }
                infile >> singlemode->board->snake->dx;
                infile >> singlemode->board->snake->dy;
                if(singlemode->board->snake2)
                {
                    infile >> singlemode->board->snake2->len;
                    for(int i = 0; i < singlemode->board->snake2->len; ++i)
                    {
                        infile >> singlemode->board->snake2->s[i][0] >> singlemode->board->snake2->s[i][1];
                    }
                    infile >> singlemode->board->snake2->dx;
                    infile >> singlemode->board->snake2->dy;
                }
                infile.close();
                singlemode->show();
            }
        }
        //else if(mode == 3){}
        else if(mode==0)
        {

            QString filepath = QFileDialog::getOpenFileName(this,"请选择游戏存档","saves\\","(*endless)(*single)(*pair)");
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
                    infile >> endlessmode->board->maxScore;
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
                else if(temp_mode==2)
                {
                    SingleMode *singlemode = new SingleMode(this->father);
                    infile >> singlemode->board->score;
                    infile >> singlemode->board->maxScore;
                    infile >> singlemode->board->move_interval;
                    infile >> singlemode->board->food_interval;
                    infile >> singlemode->board->length;
                    for(int i = 0; i < 500; ++i)
                    {
                        for(int j = 0; j < 500; ++j)
                        {
                            infile >> singlemode->board->map[i][j];
                        }
                    }
                    infile >> singlemode->board->snake->len;
                    for(int i = 0; i < singlemode->board->snake->len; ++i)
                    {
                        infile >> singlemode->board->snake->s[i][0] >> singlemode->board->snake->s[i][1];
                    }
                    infile >> singlemode->board->snake->dx;
                    infile >> singlemode->board->snake->dy;
                    if(singlemode->board->snake2)
                    {
                        infile >> singlemode->board->snake2->len;
                        for(int i = 0; i < singlemode->board->snake2->len; ++i)
                        {
                            infile >> singlemode->board->snake2->s[i][0] >> singlemode->board->snake2->s[i][1];
                        }
                        infile >> singlemode->board->snake2->dx;
                        infile >> singlemode->board->snake2->dy;
                    }
                    infile.close();
                    singlemode->show();
                }
                //else if(mode==3){}


            }
        }
    });
}

readFile::~readFile()
{
    delete ui;
}
