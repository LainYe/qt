#include "pairmode.h"
#include "ui_pairmode.h"
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

PairMode::PairMode(QWidget *_father) :
    QWidget(),
    ui(new Ui::PairMode)
{
    ui->setupUi(this);
    father = _father;

    setWindowTitle("贪吃蛇 双人模式");
    board = new Board(20,3);
    pause = 0;
    flag = 0;
    flag1=0;
    //初始化定时器
    timer = new QTimer(this);
    timer->setInterval(board->move_interval);
    //用于生成食物的定时器
    timer2 = new QTimer(this);
    timer2->setInterval(board->food_interval);
    timer3=new QTimer(this);
    timer3->setInterval(1000);
    //为定时器设置连接函数
    connect(timer, &QTimer::timeout, this, &PairMode::timerEvent);
    connect(timer2, &QTimer::timeout, [=](){
        board->makeFood();
        repaint();
        timer2->setInterval(board->food_interval);
        timer2->start();
    });
    connect(timer3, &QTimer::timeout, this, &PairMode::countdown);
    timer->start();
    timer2->start();
    timer3->start();
    resize(1000,800);
}

PairMode::~PairMode()
{
    delete ui;
}
void PairMode::countdown(){
    value--;
    timer3->setInterval(1000);
    timer3->start();
}
void PairMode::paintEvent(QPaintEvent *ev)
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
                        painter.setBrush(Qt::darkRed);
                    painter.drawRect(j*Rectsize,i*Rectsize,Rectsize,Rectsize);
                }
                else if(board->map[i][j] == -1){
                    painter.setBrush(Qt::lightGray);
                    painter.drawRect(j*Rectsize,i*Rectsize,Rectsize,Rectsize);
                }
            }
        }


    //字体
    QFont font;
    font.setPointSize(20);
    painter.setFont(font);
    painter.setPen(Qt::blue);

    painter.drawText((board->length+3)*Rectsize+60, 3*20, "速度");
    double speed = (double)1/(board->move_interval/1000.0);
    painter.drawText((board->length+3)*Rectsize+60, 6*20, QString("%1 /s").arg(speed,0,'g',3));

    if (value<=60)
    {painter.setPen(Qt::green);}
    if (value<=30)
        {painter.setPen(Qt::yellow);}
    if (value<=10)
        {painter.setPen(Qt::red);}
    painter.drawText((board->length+3)*Rectsize+60, 10*20, "倒计时");
    painter.drawText((board->length+3)*Rectsize+60, 13*20, QString("%d /s").number(value));

    painter.setPen(Qt::blue);
    painter.drawText((board->length+3)*Rectsize+60, 16*20, "玩家1长度");
    painter.drawText((board->length+3)*Rectsize+60, 19*20, QString().number(board->snake->len));

    painter.drawText((board->length+3)*Rectsize+60, 21*20, "玩家2长度");
    painter.drawText((board->length+3)*Rectsize+60, 24*20, QString().number(board->snake2->len));
}

void PairMode::keyPressEvent(QKeyEvent *event)
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
    if(flag&&flag1)
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
    else if(event->key()==Qt::Key_W)
    {
        if(board->snake2->dx != 0)
            return;
        {
            board->snake2->turnUp();
            flag1 = true;
        }
    }
    else if(event->key() == Qt::Key_S)
    {
        if(board->snake2->dx != 0)
            return;
        {
            board->snake2->turnDown();
            flag1 = true;
        }
    }
    else if(event->key() == Qt::Key_A)
    {
        if(board->snake2->dy != 0)
            return;
        {
            board->snake2->turnLeft();
            flag1 = true;
        }
    }
    else if(event->key() == Qt::Key_D)
    {
        if(board->snake2->dy != 0)
            return;
        {
            board->snake2->turnRight();
            flag1 = true;
        }
    }
    //更新界面
    this->update();
}
void PairMode::Player1win(){
    timer->stop();
    timer2->stop();
    timer3->stop();
    if (QMessageBox::Yes ==
        QMessageBox::question(this, tr("Game Over"), tr("玩家1获胜！开始新游戏吗？"),
            QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
        board = new Board(20,3);
        timer->setInterval(board->move_interval);
        timer->start();
        timer2->setInterval(board->food_interval);
        timer2->start();
        timer3->setInterval(1000);
        timer3->start();
        value=120;
    }
    else
    {
        this->hide();
        father->show();
    }
}
void PairMode::Player2win(){
    timer->stop();
    timer2->stop();
    timer3->stop();
    if (QMessageBox::Yes ==
        QMessageBox::question(this, tr("Game Over"), tr("玩家2获胜！开始新游戏吗？"),
            QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
        board = new Board(20,3);
        timer->setInterval(board->move_interval);
        timer->start();
        timer2->setInterval(board->food_interval);
        timer2->start();
        timer3->setInterval(1000);
        timer3->start();
        value=120;
    }
    else
    {
        this->hide();
        father->show();
    }
}
void PairMode::EndDraw(){
    timer->stop();
    timer2->stop();
    timer3->stop();
    if (QMessageBox::Yes ==
        QMessageBox::question(this, tr("Game Over"), tr("平局！开始新游戏吗?"),
            QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
        board = new Board(20,3);
        timer->setInterval(board->move_interval);
        timer->start();
        timer2->setInterval(board->food_interval);
        timer2->start();
        timer3->setInterval(1000);
        timer3->start();
         value=120;
    }
    else
    {
        this->hide();
        father->show();
    }
}
void PairMode:: timerEvent()
{
    bool go_on=1;//表示是否继续
    bool win1=0;bool win2=0;
    if (value<=0){
        int delta=board->snake->len-board->snake2->len;
        if (delta>0)
            Player1win();
        if (delta==0)
            EndDraw();
        if(delta<0)
            Player2win();
        go_on=0;
    }

    flag = 0;
    int action=0;
    int next = board->snake->detect();
    int tempmap[500][500];
    memcpy(tempmap,board->map,sizeof(tempmap));
    //先解决几个必死的局面，然后利用一个tempmap数组供player2研究
    //撞墙
    if(next == -1)
    {
        win2=1;
        go_on=0;
    }
    //咬到自己了
    else if(next == 3)
    {
         win2=1;
         go_on=0;
    }
    //平地或吃食物或咬到对方
    else if(next == 1)
    {
        board->snake->forward(3);
    }
    else if (next==2){
        board->snake->eat(3);
    }
    else if (next==4){
        int tx = board->snake->s[0][0] + board->snake->dx;
        int ty = board->snake->s[0][1] + board->snake->dy;
        if (tx==board->snake2->s[0][0]&&ty==board->snake2->s[0][1])
        {
            EndDraw();
        }
        for(int i=board->snake2->len-1;i>0;i--)
        {
            board->map[board->snake2->s[i][0]][board->snake2->s[i][1]]=1;
            board->snake2->len--;
            if(tx==board->snake2->s[i][0]&&ty==board->snake2->s[i][1])
            {
                break;
            }
        }
    }
    action=next;

    //在tempmap中研究
    int tx = board->snake2->s[0][0] + board->snake2->dx;
    int ty = board->snake2->s[0][1] + board->snake2->dy;
    next=tempmap[tx][ty];
    //咬到对方了
    if (next==3){
        if (tx==board->snake->s[0][0]&&ty==board->snake->s[0][1])
        {
            EndDraw();
             go_on=0;
        }
        for(int i=board->snake->len-1;i>0;i--)
        {
            board->snake->len--;
            board->map[board->snake->s[i][0]][board->snake->s[i][1]]=1;
            if(tx==board->snake->s[i][0]&&ty==board->snake->s[i][1])
            {
                break;
            }
        }
    }
    next=board->snake2->detect();//再在新地图研究
    if(next == -1)
    {
        win1=1;
        go_on=0;

    }
    //咬到自己了
    else if(next == 4)
    {
         win1=1;
         go_on=0;
    }
    else if (next==2){
        board->snake2->eat(4);
    }
    else if (next==1)
        board->snake2->forward(4);
    else if (next==3)
    {
        if (action!=2)//刚才player1没有吃到苹果，又在tempmap中没有出现3，则肯定是头
        {
            EndDraw();
             go_on=0;
        }
        else {
            if (tx==board->snake->s[0][0]&&ty==board->snake->s[0][1])
            {EndDraw();go_on=0;}
            else //说明是吃到尾巴
            {
                board->snake->len--;
                board->snake2->forward(4);
            }
        }
    }
    if (go_on){
    repaint();
    timer->setInterval(board->move_interval);
    timer->start();
    }
    else if (win1||win2){
        if (win1&&win2)
            EndDraw();
        else{
            if (win1)
                Player1win();
            else
                Player2win();
        }
    }
}


int PairMode::saveFile(std::string fileName)
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
            outfile << board->length << " \n";
            for(int i = 0; i < 500; ++i)
            {
                for(int j = 0; j < 500; ++j)
                {
                    outfile << board->map[i][j] << " ";
                }
                outfile << '\n';
            }
            outfile << board->snake->len << " ";
            for(int i = 0; i < board->snake->len; ++i)
            {
                outfile << board->snake->s[i][0] << " " << board->snake->s[i][1] << " ";
            }
            outfile << '\n';
            outfile << board->snake->dx << " ";
            outfile << board->snake->dy << " ";
            if(board->snake2)
            {
                outfile << board->snake2->len << " ";
                for(int i = 0; i < board->snake2->len; ++i)
                {
                    outfile << board->snake2->s[i][0] << " " << board->snake2->s[i][1] << " ";
                }
                outfile << '\n';
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
        outfile << board->length << " \n";
        for(int i = 0; i < 500; ++i)
        {
            for(int j = 0; j < 500; ++j)
            {
                outfile << board->map[i][j] << " ";
            }
            outfile << '\n';
        }
        outfile << board->snake->len << " ";
        for(int i = 0; i < board->snake->len; ++i)
        {
            outfile << board->snake->s[i][0] << " " << board->snake->s[i][1] << " ";
        }
        outfile << '\n';
        outfile << board->snake->dx << " ";
        outfile << board->snake->dy << " ";
        if(board->snake2)
        {
            outfile << board->snake2->len << " ";
            for(int i = 0; i < board->snake2->len; ++i)
            {
                outfile << board->snake2->s[i][0] << " " << board->snake2->s[i][1] << " ";
            }
            outfile << '\n';
            outfile << board->snake2->dx << " ";
            outfile << board->snake2->dy << " ";
         }
        outfile.close();
    }
    return 0;
}
