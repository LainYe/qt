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
    bool Pause;//是否暂停状态
    QTimer *timer;//计时器
    Board *board;//地图

    void paintEvent(QPaintEvent *);//重写绘图函数
    void keyPressEvent(QKeyEvent *);//重写键盘事件函数

public slots:
    void timerEvent();//计时器到时的槽函数

private:
    Ui::EndlessMode *ui;
};

#endif // ENDLESSMODE_H
