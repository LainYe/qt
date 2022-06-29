#ifndef SINGLEMODE_H
#define SINGLEMODE_H

#include <QWidget>
#include <QObject>
#include <board.h>
#include <QKeyEvent>

namespace Ui {
class SingleMode;
}

class QPaintEvent;

class SingleMode : public QWidget
{
    Q_OBJECT

public:
    explicit SingleMode(QWidget *parent = nullptr, int Dead_Time=3000000);
    ~SingleMode();
    bool pause;//是否暂停状态
    bool flag;//用来保证1个时间间隔只处理一个有效键盘事件
    int level = 0;//关卡
    const int mode = 2;
    QTimer *timer;//计时器
    QTimer *stable_timer;//稳定计时器
    int dead_time;//时间界限
    Board *board;//地图
    QWidget *father;
    int initial_score = 0;//进入地图时的分数
    int hole[2]={};//洞口
    void paintEvent(QPaintEvent *);//重写绘图函数
    void keyPressEvent(QKeyEvent *);//重写键盘事件函数
    int saveFile(std::string);//存档函数,因为重名放弃存档返回1
    bool next_level(int);
public slots:
    void timerEvent();//计时器到时的槽函数
    void stable_timerEvent();//稳定计时器到时的槽函数
private:
    Ui::SingleMode *ui;
};

#endif // SINGLEMODE_H
