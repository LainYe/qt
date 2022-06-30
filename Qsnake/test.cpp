#include <cstdlib>
#include <string>
#include <io.h>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <fstream>
using namespace std;
# pragma execution_character_set("utf-8")

bool initial_test()
{
    string command;
    command = "mkdir ";
    if (_access("saves", 0) == -1)
        system((command + "saves").c_str());
    QString maps_dirpath=":/SingleModeMaps/maps/";
    bool flag=true;
    for(int i=0;i<7;i++)
    {
        QFile file(maps_dirpath+"level_"+char(i+48)+".single");
        if(!file.open(QIODevice::ReadOnly))
        {
            flag=false;
            break;
        }
        file.close();
        file.setFileName(maps_dirpath+"story_"+char(i+48)+".txt");
        if(!file.open(QIODevice::ReadOnly))
        {
            flag=false;
            break;
        }
        file.close();
    }
    if(!flag)
    {
        QMessageBox::information(0,"错误","资源文件缺失");
        return false;
    }
    QString images_dirpath=":/new/prefix1/";
    QFile file(images_dirpath+"background.gif");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"错误","资源文件缺失");
        return false;
    }
    file.close();
    file.setFileName(images_dirpath+"headline.png");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"错误","资源文件缺失");
        return false;
    }
    file.close();
    file.setFileName(images_dirpath+"picture.png");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"错误","资源文件缺失");
        return false;
    }
    file.close();
    return true;
}
