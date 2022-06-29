#include "board.h"
#include "snake.h"
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>

using namespace std;

Board::Board(int _length, int _mode)
{
    mode = _mode;
    score = 0;
    move_interval = 300;
    food_interval = 5000;
    length = _length;
    snake = new Snake(this);
    //读取最大值
    QString filename;
    if(mode == 1){
        filename=QString("maxscore.endless");
    }
    else if(mode == 2){
        filename=QString("maxscore.single");
    }
    else if(mode == 3){
        filename=QString("maxscore.pair");
    }
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly|QIODevice::Truncate)){
        QTextStream infile(&file);
        infile >> maxScore;
        file.close();

        file.setFileName(filename);
        file.open(QIODevice::WriteOnly);
        QTextStream outfile(&file);
        if(maxScore<score)
            maxScore=score;
        outfile<<maxScore;
        file.close();
    }
    else
    {
        maxScore = 0;
    }

    //初始化地图
    memset(map,1,sizeof (map));
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
        fstream file;
        if(mode == 1){
            file.open("maxscore.endless",ios::out);
        }
        else if(mode == 2){
            file.open("maxscore.single",ios::out);
        }
        else if(mode == 3){
             file.open("maxscore.pair",ios::out);
        }
        file << score;
        file.close();
    }
}

void Board::reset_size(int size_old, int size_new){
    length = size_new;
    for(int i = 0; i<= size_old + 1; ++i)
    {
        if(map[0][i] == -1) map[0][i] = 1;
        if(map[i][0] == -1) map[i][0] = 1;
        if(map[size_old + 1][i] == -1) map[size_old + 1][i] = 1;
        if(map[i][size_old + 1] == -1) map[i][size_old + 1] = 1;
    }
    for(int i = 0; i<= size_new + 1; ++i)
    {
        map[0][i] = -1;
        map[i][0] = -1;
        map[size_new + 1][i] = -1;
        map[i][size_new + 1] = -1;
    }
    for(int i = 0; i <= size_new + 1; ++i){
        for(int j = 0; j <= size_new + 1;++j){
            if(map[i][j] < -1 || map[i][j] > 4){
                map[i][j] = 1;
            }
        }
    }
}
