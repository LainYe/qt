#ifndef ENDLESSMODE_H
#define ENDLESSMODE_H

#include <QWidget>
#include <QObject>
#include <board.h>
#include <QKeyEvent>

namespace Ui {
class EndlessMode;
}

class QPaintEvent;

class EndlessMode : public QWidget
{
    Q_OBJECT

public:
    explicit EndlessMode(QWidget *parent = nullptr);
    ~EndlessMode();
    bool pause;//是否暂停状态
    bool flag;//用来保证1个时间间隔只处理一个有效键盘事件
    QTimer *timer;//计时器
    QTimer *timer2;//用于生成食物
    Board *board;//地图
    QWidget *father;

    void paintEvent(QPaintEvent *);//重写绘图函数
    void keyPressEvent(QKeyEvent *);//重写键盘事件函数
    void saveFile(std::string);//存档函数

public slots:
    void timerEvent();//计时器到时的槽函数

private:
    Ui::EndlessMode *ui;
};

#endif // ENDLESSMODE_H
