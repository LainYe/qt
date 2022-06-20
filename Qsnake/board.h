#ifndef BOARD_H
#define BOARD_H
#include <QPoint>
#include "snake.h"
#include <QWidget>
class Board
{
public:
    int score;//当前分数
    int maxScore;//最高分
    int move_interval;//每次移动的间隔时间
    int food_interval;//刷新事物的间隔时间
    int length;//地图边长
    int map[500][500];//保存地图信息,可活动的区域是[1~length]*[1~length]
    //0代表蛇，1代表空地，2代表食物，-1代表墙
    Snake *snake;

    Board(int);//给定length
    void makeFood();
    void reset_interval();//调整速度
    void get_score();//得分
};

#endif // BOARD_H
