#include <cstdlib>
#include <string>
#include <io.h>
#include <QString>
#include <QMessageBox>
#include <QDir>
#include <fstream>
using namespace std;
# pragma execution_character_set("utf-8")

bool initial_test()
{
    string command;
    command = "mkdir ";
    if (_access("saves", 0) == -1)
        system((command + "saves").c_str());
    QString maps_dirpath=":/SingleModeMaps/maps";
    QDir maps_dir(maps_dirpath);
    if (!maps_dir.exists()){
        QMessageBox::information(0,"出错","资源文件缺失");
        return false;
    }
    /*QString rules_dirpath="";
    QDir rules_dir(rules_dirpath);
    if (!rules_dir.exists())
        return false;*/
    // rules文件夹构建中
    return true;
}
