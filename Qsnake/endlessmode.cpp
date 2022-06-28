#include "endlessmode.h"
#include "ui_endlessmode.h"
#include "pause.h"
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QDebug>
#include <QString>

using namespace std;

# pragma execution_character_set("utf-8")

EndlessMode::EndlessMode(QWidget *_father) :
    QWidget(),
    ui(new Ui::EndlessMode)
{
    ui->setupUi(this);
    father = _father;

    setWindowTitle("贪吃蛇 无尽模式");
    board = new Board(20,1);
    pause = 0;
    flag = 0;
    //初始化定时器
    timer = new QTimer(this);
    timer->setInterval(board->move_interval);
    //用于生成食物的定时器
    timer2 = new QTimer(this);
    timer2->setInterval(board->food_interval);

    //为定时器设置连接函数
    connect(timer, &QTimer::timeout, this, &EndlessMode::timerEvent);
    connect(timer2, &QTimer::timeout, [=](){
        board->makeFood();
        repaint();
        timer2->setInterval(board->food_interval);
        timer2->start();
    });
    timer->start();
    timer2->start();
    resize(1000,800);
}

EndlessMode::~EndlessMode()
{
    delete ui;
}
void EndlessMode::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);//设置画家区域

    //设置地图尺寸
    int Rectsize = 20;
    int l = board->snake->len;
    if(l >= 10 && l < 40){
        board->reset_size(20,40);
        Rectsize = 10;
    }
    else if(l > 40){
        board->reset_size(40,80);
        Rectsize = 10;
        resize(1500,1200);
    }

    for(int i = 0; i <= board->length + 1; ++i)
    {
        for(int j = 0; j <= board->length+ 1; ++j)
        {
            if(board->map[i][j] == 2)//食物
            {
                painter.setBrush(Qt::yellow);
                painter.drawRect(j*Rectsize,i*Rectsize,Rectsize,Rectsize);
            }
            else if(board->map[i][j] == 1){//空地
                continue;
            }
            else if(board->map[i][j] == 0 || board->map[i][j] == 3 || board->map[i][j] == 4){//蛇
                painter.setBrush(Qt::white);
                if(i == board->snake->s[0][0] && j == board->snake->s[0][1])
                    painter.setBrush(Qt::darkGreen);
                if(board->snake2 && i == board->snake2->s[0][0] && j == board->snake2->s[0][1])
                    painter.setBrush(Qt::darkGreen);
                painter.drawRect(j*Rectsize,i*Rectsize,Rectsize,Rectsize);
            }
            else if(board->map[i][j] == -1){
                painter.setBrush(Qt::lightGray);
                painter.drawRect(j*Rectsize,i*Rectsize,Rectsize,Rectsize);
            }
        }
    }

    //游戏信息
    //字体
    QFont font;
    font.setPointSize(20);
    painter.setFont(font);
    painter.setPen(Qt::blue);

    painter.drawText((board->length+3)*Rectsize+ 60, 3*20, "速度");
    double speed = (double)1/(board->move_interval/1000.0);
    painter.drawText((board->length+3)*Rectsize+60, 6*20, QString("%1 /s").arg(speed,0,'g',3));


    painter.drawText((board->length+3)*Rectsize+60, 10*20, "最高分");
    painter.drawText((board->length+3)*Rectsize+60, 13*20, QString().number(board->maxScore));

    painter.drawText((board->length+3)*Rectsize+60, 16*20, "当前");
    painter.drawText((board->length+3)*Rectsize+60, 18*20, QString().number(board->score));
}

void EndlessMode::keyPressEvent(QKeyEvent *event)
{
    if(pause)
        return;
    //P暂停
    if(event->key() == Qt::Key_P)
    {
        timer->stop();
        timer2->stop();
        pause = 1;
        Pause *_pause = new Pause(this, this->mode);
        _pause->show();

    }
    //若1个间隔多次按方向键就忽略
    if(flag)
        return;
    if(event->key() == Qt::Key_Up)
    {
        if(board->snake->dx != 0)
            return;
        board->snake->turnUp();
        flag = true;
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(board->snake->dx != 0)
            return;
        {
            board->snake->turnDown();
            flag = true;
        }
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(board->snake->dy != 0)
            return;
        {
            board->snake->turnLeft();
            flag = true;
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(board->snake->dy != 0)
            return;
        {
            board->snake->turnRight();
            flag = true;
        }
    }
    //更新界面
    this->update();
}

void EndlessMode:: timerEvent()
{
    flag = 0;
    int next = board->snake->detect();
    //撞墙
    if(next == -1)
    {
        timer->stop();
        timer2->stop();
        if (QMessageBox::Yes ==
            QMessageBox::question(this, tr("Game Over"), tr("蛇撞墙了，开始新游戏吗?"),
                QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            board = new Board(20,1);
            timer->setInterval(board->move_interval);
            timer->start();
            timer2->setInterval(board->food_interval);
            timer2->start();
        }
        else
        {
            this->hide();
            father->show();
        }
    }
    //咬到自己了
    else if(next == 0)
    {
        timer->stop();
        timer2->stop();
        if (QMessageBox::Yes ==
            QMessageBox::question(this, tr("Game Over"), tr("蛇咬到自己了，开始新游戏吗?"),
                QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            board = new Board(20,1);
            timer->setInterval(board->move_interval);
            timer->start();
            timer2->setInterval(board->food_interval);
            timer2->start();
        }
        else
        {
            this->hide();
            father->show();
        }
    }
    //平地
    else if(next == 1)
    {
        board->snake->forward();
        repaint();
        timer->setInterval(board->move_interval);
        timer->start();
    }
    //吃食物
    else if(next == 2)
    {
        board->snake->eat();
        repaint();
        timer->setInterval(board->move_interval);
        timer->start();
    }

}

int EndlessMode::saveFile(std::string fileName)
{
    std::ifstream infile(fileName);//先看看有没有重名文件
    if(infile)
    {
        if (QMessageBox::Yes ==
            QMessageBox::question(this, tr("存档"), tr("存档已经存在，确认要覆盖吗?"),
                QMessageBox::Yes | QMessageBox::No, QMessageBox::No))
        {
            std::ofstream outfile;
            outfile.open(fileName);
            outfile << mode << " ";
            outfile << board->score << " ";
            outfile << board->maxScore << " ";
            outfile << board->move_interval << " ";
            outfile << board->food_interval << " ";
            outfile << board->length << " ";
            for(int i = 0; i < 500; ++i)
            {
                for(int j = 0; j < 500; ++j)
                {
                    outfile << board->map[i][j] << " ";
                }
                outfile << endl;
            }
            outfile << board->snake->len << " ";
            for(int i = 0; i < board->snake->len; ++i)
            {
                outfile << board->snake->s[i][0] << " " << board->snake->s[i][1] << " ";
            }
            outfile << endl;
            outfile << board->snake->dx << " ";
            outfile << board->snake->dy << " ";
            if(board->snake2)
            {
                outfile << board->snake2->len << " ";
                for(int i = 0; i < board->snake2->len; ++i)
                {
                    outfile << board->snake2->s[i][0] << " " << board->snake2->s[i][1] << " ";
                }
                outfile << endl;
                outfile << board->snake2->dx << " ";
                outfile << board->snake2->dy << " ";
             }
            infile.close();
            outfile.close();
            return 0;
        }
        else
        {
            infile.close();
            return 1;
        }
    }
    else
    {
        std::ofstream outfile;
        outfile.open(fileName);
        outfile << mode << " ";
        outfile << board->score << " ";
        outfile << board->maxScore << " ";
        outfile << board->move_interval << " ";
        outfile << board->food_interval << " ";
        outfile << board->length << " ";
        for(int i = 0; i < 500; ++i)
        {
            for(int j = 0; j < 500; ++j)
            {
                outfile << board->map[i][j] << " ";
            }
        }
        outfile << board->snake->len << " ";
        for(int i = 0; i < board->snake->len; ++i)
        {
            outfile << board->snake->s[i][0] << " " << board->snake->s[0][1] << " ";
        }
        outfile << board->snake->dx << " ";
        outfile << board->snake->dy << " ";
        if(board->snake2)
        {
            outfile << board->snake2->len << " ";
            for(int i = 0; i < board->snake2->len; ++i)
            {
                outfile << board->snake2->s[i][0] << " " << board->snake2->s[0][1] << " ";
            }
            outfile << board->snake2->dx << " ";
            outfile << board->snake2->dy << " ";
         }
        outfile.close();
    }
    return 0;
}
