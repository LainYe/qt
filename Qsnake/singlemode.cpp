#include "singlemode.h"
#include "ui_singlemode.h"
#include "pause.h"
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <string>
#include <QFile>

using namespace std;
# pragma execution_character_set("utf-8")


SingleMode::SingleMode(QWidget *_father,int Dead_Time) :
    QWidget(),
    ui(new Ui::SingleMode),
    dead_time(Dead_Time)
{
    ui->setupUi(this);
    father = _father;

    setWindowTitle("贪吃蛇 单人模式");
    board = new Board(20,2);
    pause = 0;
    flag = 0;
    QString filename=":/SingleModeMaps/maps/level_0.single";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream infile(&file);
    char space;
    int temp_mode;
    infile >> temp_mode>>space;//mode
    infile >> level>>space;
    infile >> board->move_interval>>space;
    infile >> board->length>>space>>space;
    for(int i = 0; i < 500; ++i)
    {
        for(int j = 0; j < 500; ++j)
        {
            infile >> board->map[i][j]>>space;
        }
        infile >>space;
    }
    infile >> board->snake->total_len>>space;
    infile >> board->snake->len>>space>>space;
    for(int i = 0; i < board->snake->len; ++i)
    {
        infile >> board->snake->s[i][0] >>space>> board->snake->s[i][1]>>space;
    }
    infile >>space>> board->snake->dx>>space;
    infile >> board->snake->dy>>space;
    file.close();








    //初始化定时器
    timer = new QTimer(this);
    stable_timer =new QTimer(this);
    stable_timer->setSingleShot(true);
    //为定时器设置连接函数
    connect(timer, &QTimer::timeout, this, &SingleMode::timerEvent);
    connect(stable_timer,&QTimer::timeout,this,&SingleMode::stable_timerEvent);
    timer->start();
    stable_timer->start(dead_time);
    resize(1000,800);
}

SingleMode::~SingleMode()
{
    delete ui;
}
void SingleMode::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);//设置画家区域
    int Rectsize = 20;

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
            else if(board->map[i][j] == -1){//墙
                painter.setBrush(Qt::lightGray);
                painter.drawRect(j*Rectsize,i*Rectsize,Rectsize,Rectsize);
            }
            else if(board->map[i][j] == -2)//出口
            {
                painter.setBrush(Qt::red);
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

    painter.drawText((board->length+3)*20+60, 2*20, "关卡");
    painter.drawText((board->length+3)*20+60, 5*20, QString().number(level));


    painter.drawText((board->length+3)*20+60, 7*20, "速度");
    double speed = (double)1/(board->move_interval/1000.0);
    painter.drawText((board->length+3)*20+60, 10*20, QString("%1 /s").arg(speed,0,'g',3));


    painter.drawText((board->length+3)*20+60, 12*20, "最高分");
    painter.drawText((board->length+3)*20+60, 15*20, QString().number(board->maxScore));

    painter.drawText((board->length+3)*20+60, 17*20, "当前");
    painter.drawText((board->length+3)*20+60, 20*20, QString().number(board->score));

    painter.drawText((board->length+3)*20+60, 22*20, "洞外长度");
    painter.drawText((board->length+3)*20+60, 25*20, QString().number(board->snake->total_len-board->snake->len));

    painter.drawText((board->length+3)*20+60, 27*20, "总剩余时间/s");
    painter.drawText((board->length+3)*20+60, 30*20, QString().number(stable_timer->remainingTime()/1000));
    dead_time=stable_timer->remainingTime();

    //more
}

void SingleMode::keyPressEvent(QKeyEvent *event)
{
    if(pause)
        return;
    //P暂停
    if(event->key() == Qt::Key_P)
    {
        timer->stop();
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
void SingleMode::stable_timerEvent()
{
    if(!stable_timer->isActive())
    {
        timer->stop();
        if (QMessageBox::Yes ==
                QMessageBox::question(this, tr("Game Over"), tr("你超时了，开始新游戏吗?"),
                                      QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            SingleMode *singlemode = new SingleMode(father);
            this->hide();
            singlemode->show();
        }
        else
        {
            this->hide();
            father->show();
        }
    }
}
void SingleMode:: timerEvent()
{
    flag = 0;
    int next = board->snake->detect();
    //撞墙
    if(next == -1)
    {
        timer->stop();
        if (QMessageBox::Yes ==
                QMessageBox::question(this, tr("Game Over"), tr("蛇撞墙了，重新开始本关吗?"),
                                      QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            timer->stop();
            next_level(level-1);
            board->score=initial_score;
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
        if (QMessageBox::Yes ==
                QMessageBox::question(this, tr("Game Over"), tr("蛇咬到自己了，重新开始本关吗?"),
                                      QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
        {
            timer->stop();
            next_level(level-1);
            board->score=initial_score;

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

        board->snake->single_forward();
        repaint();
        timer->setInterval(board->move_interval);
        timer->start();
    }
    //吃食物
    else if(next == 2)
    {
        board->snake->single_eat();
        repaint();
        timer->setInterval(board->move_interval);
        timer->start();
    }
    //下一关
    else if(next == -2)
    {
        initial_score=board->score;
        board->snake->single_forward();
        timer->stop();
        if(next_level(level))
        {
            repaint();
        }
        else
        {
            timer->stop();
            this->close();
            father->show();
        }
    }
}

int SingleMode::saveFile(std::string fileName)
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
            outfile << dead_time << " ";
            outfile << level <<" ";
            outfile << board->score << " ";
            outfile << board->maxScore << " ";
            outfile << board->move_interval << " ";
            outfile << board->length << " \n";
            for(int i = 0; i < 500; ++i)
            {
                for(int j = 0; j < 500; ++j)
                {
                    outfile << board->map[i][j] << " ";
                }
                outfile << '\n';
            }
            outfile<<board->snake->total_len<<" ";
            outfile << board->snake->len << " \n";
            for(int i = 0; i < board->snake->len; ++i)
            {
                outfile << board->snake->s[i][0] << " " << board->snake->s[i][1] << " ";
            }
            outfile << '\n';
            outfile << board->snake->dx << " ";
            outfile << board->snake->dy << " \n";
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
        outfile << dead_time << " ";
        outfile << level << " ";
        outfile << board->score << " ";
        outfile << board->maxScore << " ";
        outfile << board->move_interval << " ";
        outfile << board->length << " \n";
        for(int i = 0; i < 500; ++i)
        {
            for(int j = 0; j < 500; ++j)
            {
                outfile << board->map[i][j] << " ";
            }
            outfile<<'\n';
        }
        outfile<<board->snake->total_len<<" ";
        outfile << board->snake->len << " \n";
        for(int i = 0; i < board->snake->len; ++i)
        {
            outfile << board->snake->s[i][0] << " " << board->snake->s[i][1] << " ";
        }
        outfile << '\n';
        outfile << board->snake->dx << " ";
        outfile << board->snake->dy << " \n";
        outfile.close();
    }
    return 0;
}
bool SingleMode::next_level(int previous_level)
{

    QString filename=QString(":/SingleModeMaps/maps/level_")+char(previous_level+1+48)+QString(".single");
    QFile file(filename);
    int temp_mode;
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream infile(&file);
        char space;
        infile >> temp_mode>>space;//mode
        infile >> level>>space;
        infile >> board->move_interval>>space;
        infile >> board->length>>space>>space;
        for(int i = 0; i < 500; ++i)
        {
            for(int j = 0; j < 500; ++j)
            {
                infile >> board->map[i][j]>>space;
            }
            infile >> space;
        }
        infile >> board->snake->total_len>>space;
        infile >> board->snake->len>>space>>space;
        for(int i = 0; i < board->snake->len; ++i)
        {
            infile >> board->snake->s[i][0] >>space>> board->snake->s[i][1]>>space;
        }
        infile >>space>> board->snake->dx>>space;
        infile >> board->snake->dy>>space;
        file.close();
        timer->setInterval(board->move_interval);
        timer->stop();
        QString temp=QString("你即将进入第")+char(level+48)+QString("关");

        QMessageBox box(QMessageBox::Question,"进入下一关",temp,
                        QMessageBox::Yes|QMessageBox::No,this);
        box.setButtonText(QMessageBox::Yes,"进入游戏！");
        box.setButtonText(QMessageBox::No,"暂停一下");
        int tmp = box.exec();
        if(tmp == QMessageBox::No){
            timer->stop();
            pause = 1;
            Pause *_pause = new Pause(this, this->mode);
            _pause->show();
            return true;
        }
        else
        {
            timer->start();
            return true;
        }
    }
    else
    {
        QMessageBox::information(this,"恭喜","你已通关");
        stable_timer->stop();
        return false;
    }
}
