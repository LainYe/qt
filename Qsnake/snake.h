#ifndef SNAKE_H
#define SNAKE_H

class Board;

class Snake
{
public:
    int len;
    int s[10000][2] = {0};//0是蛇头
    int dx, dy;
    Board *board;

    Snake(Board *);
    //先detect,再决定调用forward还是eat还是死了
    void eat();
    int detect();//下一步发生的状态，目标点的map值
    void update();//根据当前位置更新地图
    void forward();//向前
    void turnUp();
    void turnDown();
    void turnLeft();
    void turnRight();
};

#endif // SNAKE_H
