#include "snake.h"
#include "board.h"
#include <QDebug>
#include <QString>
Snake::Snake(Board *_board)
{
    board = _board;
    len = 2;
    dx = 0;
    dy = 1;

    s[0][0] = s[1][0] = board->length/2;
    s[0][1] = board->length/2;
    s[1][1] = s[0][1] - 1;
    update();
}

void Snake::eat()
{
    int tx = s[0][0] + dx;
    int ty = s[0][1] + dy;
    for(int i = len; i > 0; --i){
        s[i][0] = s[i - 1][0];
        s[i][1] = s[i - 1][1];
    }
    s[0][0] = tx;
    s[0][1] = ty;
    len++;
    board->map[tx][ty] = 0;
    board->reset_interval();
    board->get_score();
}

int Snake::detect()
{
    int tx = s[0][0] + dx;
    int ty = s[0][1] + dy;
    return board->map[tx][ty];
}

void Snake::update(){
    for(int i = 0; i < len; ++i)
    {
        board->map[ s[i][0] ][ s[i][1] ] = 0;
    }
    return;
}

void Snake::forward()
{
    //擦掉蛇尾
    board->map[ s[len - 1][0]][ s[len - 1][1] ] = 1;
    //蛇内部的数组更新
    for(int i = len - 1; i > 0; --i)
    {
        s[i][0] = s[i - 1][0];
        s[i][1] = s[i - 1][1];
    }
    s[0][0] += dx;
    s[0][1] += dy;
    //更新地图
    update();
}


void Snake::turnUp()
{
    dx = -1;
    dy = 0;
}

void Snake::turnDown()
{
    dx = 1;
    dy = 0;
}

void Snake::turnLeft()
{
    dx = 0;
    dy = -1;
}

void Snake::turnRight()
{
    dx = 0;
    dy = 1;
}
