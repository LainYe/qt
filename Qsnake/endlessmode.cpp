#include "endlessmode.h"
#include "ui_endlessmode.h"
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <QMessageBox>

# pragma execution_character_set("utf-8")

EndlessMode::EndlessMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndlessMode)
{
    ui->setupUi(this);

    setWindowTitle("贪吃蛇");
    board = new Board(20);
    Pause = 0;

    //初始化定时器
    timer = new QTimer(this);
    timer->setInterval(board->move_interval);

    //为定时器设置连接函数
    connect(timer, &QTimer::timeout, this, &EndlessMode::timerEvent);

    timer->start();
    resize(600,600);
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
}
void EndlessMode::keyPressEvent(QKeyEvent *ev)
{

}
void EndlessMode:: timerEvent()
{

}
