#include "board.h"

Board::Board(int _length)
{
    score = 0;
    maxScore = 0;//待修改
    move_interval = 500;
    food_interval = 5000;
    length = _length;

    //初始化地图
    for(int i = 0; i< length; ++i)
    {
        map[0][i] = map[i][0] = map[length + 1][i] = map[i][length + 1] = 0;
    }
    //初始一个食物
    int food_x = (rand()%length) + 1;
    int food_y = (rand()%length) + 1;
    map[food_x][food_y] = 2;
}

void Board::makeFood()
{
    int food_x = 0, food_y = 0;
    while(map[food_x][food_y] != 1)
    {
        food_x = rand()%length + 1;
        food_y = rand()%length + 1;
    }
    map[food_x][food_y] = 2;
    return;
}
