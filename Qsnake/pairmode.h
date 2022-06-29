#ifndef PAIRMODE_H
#define PAIRMODE_H

#include <QWidget>
#include <QObject>
#include <board.h>
#include <QKeyEvent>

namespace Ui {
class PairMode;
}

class QPaintEvent;

class PairMode : public QWidget
{
    Q_OBJECT

public:
    explicit PairMode(QWidget *parent = nullptr);
    ~PairMode();
    bool pause;//是否暂停状态
    bool flag;//用来保证1个时间间隔只处理一个有效键盘事件
    bool flag1;
    const int mode = 3;
    QTimer *timer;//计时器
    QTimer *timer2;//用于生成食物
    QTimer *timer3;//用于游戏倒计时
    Board *board;//地图
    QWidget *father;
    int value=120;
    void paintEvent(QPaintEvent *);//重写绘图函数
    void keyPressEvent(QKeyEvent *);//重写键盘事件函数
    void countdown();//倒计时
    int saveFile(std::string);//存档函数,因为重名放弃存档返回1
    void EndDraw();//平局
    void Player1win();
    void Player2win();

public slots:
    void timerEvent();//计时器到时的槽函数

private:
    Ui::PairMode *ui;
};

#endif // PAIRMODE_H
