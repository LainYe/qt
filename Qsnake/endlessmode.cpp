#include "endlessmode.h"
#include "ui_endlessmode.h"
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <QString>

# pragma execution_character_set("utf-8")

EndlessMode::EndlessMode(QWidget *_father) :
    QWidget(),
    ui(new Ui::EndlessMode)
{
    ui->setupUi(this);
    father = _father;
    setWindowTitle("贪吃蛇");
    board = new Board(20);
    Pause = 0;
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
        qDebug()<<QString("timer2");
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
    painter.setPen(Qt::lightGray);

    //画出地图
    for(int i=0; i<=board->length+1; i++)
    {
        painter.drawRect(0*20, i*20, 20, 20);
        painter.drawRect((board->length+1)*20, i*20, 20, 20);
        painter.drawRect(i*20, 0*20, 20, 20);
        painter.drawRect(i*20, (board->length+1)*20, 20, 20);
    }

    //蛇身
    painter.setBrush(Qt::white);
    for(int i=1; i<board->snake->len; i++)
        painter.drawRect(board->snake->s[i][1]*20, board->snake->s[i][0]*20, 20, 20);

    //蛇头
    painter.setBrush(Qt::darkGreen);
    painter.drawRect(board->snake->s[0][1]*20,
            board->snake->s[0][0]*20, 20, 20);

    //食物
    painter.setBrush(Qt::yellow);
    for(int i = 1; i <= board->length; ++i)
    {
        for(int j = 1; j <= board->length; ++j)
        {
            if(board->map[i][j] == 2)
            {
                painter.drawRect(j*20,i*20,20,20);
            }
        }
    }

    //游戏信息
    //字体
    QFont font;
    font.setPointSize(20);
    painter.setFont(font);
    painter.setPen(Qt::blue);

    painter.drawText((board->length+3)*20+60, 3*20, "速度");
    double speed = (double)1/(board->move_interval/1000.0);
    painter.drawText((board->length+3)*20+60, 6*20, QString("%1 /s").arg(speed,0,'g',3));


    painter.drawText((board->length+3)*20+60, 10*20, "最高分");
    painter.drawText((board->length+3)*20+60, 13*20, QString().number(board->maxScore));

    painter.drawText((board->length+3)*20+60, 16*20, "当前");
    painter.drawText((board->length+3)*20+60, 18*20, QString().number(board->score));
}

void EndlessMode::keyPressEvent(QKeyEvent *event)
{
    if(Pause)
        return;
    //P暂停
    if(event->key() == Qt::Key_P)
    {
        timer->stop();
        timer2->stop();
        Pause = 1;
        QMessageBox::information(this, tr("提醒"), tr("回到游戏"));
        Pause = 0;
        timer->start();

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
            board = new Board(20);
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
            board = new Board(20);
            timer->setInterval(board->move_interval);
            timer->start();
            timer2->setInterval(board->food_interval);
            timer2->start();
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
