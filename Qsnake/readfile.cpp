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
#include "QDebug"
#include "QByteArray"
#include "QFile"


using namespace std;
# pragma execution_character_set("utf-8")

readFile::readFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::readFile)
{
    ui->setupUi(this);
    connect(ui->back, &QPushButton::clicked,[=](){
        hide();
        father->show();
    });
    connect(ui->choosefile, &QPushButton::clicked,[=](){
        char buffer[256];
        _getcwd(buffer,sizeof(buffer));
        QString filepath = QFileDialog::getOpenFileName(this,"请选择游戏存档","C:\\Users\\abc\\Desktop");
        QString dirpath = QDir::currentPath();
        filepath = filepath.mid(dirpath.length()+1);
        QString res = filepath + QString(".txt");
        QByteArray a = res.toLatin1();
        char* filename = a.data();
        qDebug()<<filename;
        fstream infile("endlessmode_game.txt",ios::in);
        this->hide();
        EndlessMode *endlessmode = new EndlessMode(this->father);
        if(infile){
            infile >> endlessmode->board->score;
            qDebug()<<endlessmode->board->score;
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
                infile >> endlessmode->board->snake->s[i][0] >> endlessmode->board->snake->s[0][1];
            }
            infile >> endlessmode->board->snake->dx;
            infile >> endlessmode->board->snake->dy;
            if(endlessmode->board->snake2)
            {
                infile >> endlessmode->board->snake2->len;
                for(int i = 0; i < endlessmode->board->snake2->len; ++i)
                {
                    infile >> endlessmode->board->snake2->s[i][0] >> endlessmode->board->snake2->s[0][1];
                }
                infile >> endlessmode->board->snake2->dx;
                infile >> endlessmode->board->snake2->dy;
            }
            infile.close();
            endlessmode->show();
        }
    });

}

readFile::~readFile()
{
    delete ui;
}
