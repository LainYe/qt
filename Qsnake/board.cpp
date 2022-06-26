#include "board.h"
#include "snake.h"
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

Board::Board(int _length)
{
    score = 0;
    move_interval = 300;
    food_interval = 5000;
    length = _length;
    snake = new Snake(this);
    //读取最大值
    fstream file("endlessmode_maxscore.txt",ios::in);
    if(file){
        file >> maxScore;
        file.close();
    }
    else
    {
        maxScore = 0;
    }

    //初始化地图
    for(int i = 0; i<= length + 1; ++i)
    {
        map[0][i] = map[i][0] = map[length + 1][i] = map[i][length + 1] = -1;
    }
    for(int i = 1; i<= length ;++i)
    {
        for(int j = 1; j<= length; ++j)
        {
            map[i][j] = 1;
        }
    }
    //初始一个食物
    int food_x = (rand()%length) + 1;
    int food_y = (rand()%length) + 1;
    map[food_x][food_y] = 2;
}

void Board::makeFood()
{
    srand( (unsigned)time( NULL ) );
    int food_x = 0, food_y = 0;
    while(map[food_x][food_y] != 1)
    {
        food_x = rand()%length + 1;
        food_y = rand()%length + 1;
    }
    map[food_x][food_y] = 2;
    return;
}

void Board::reset_interval()
{
    double rate = (double)snake->len/100;//长度100后就不加速了
    move_interval = fmax(20, 300 - 280 * rate);
    food_interval = length * move_interval;
    return;
}

void Board::get_score()
{
    score += 5;
    if(score > maxScore)
    {
        maxScore = score;
        fstream file("endlessmode_maxscore.txt",ios::out);
        char buffer[20];
        itoa(score,buffer,10);
        file.write(buffer,strlen(buffer));
        file.close();
    }
}
