#include <cstdlib>
#include <string>
#include <io.h>
using namespace std;

bool initial_test()
{
    string command;
    command = "mkdir ";
    if (_access("saves", 0) == -1)
        system((command + "saves").c_str());

    /*if (_access("rules", 0) == -1)
        return false;*/
    // rules文件夹构建中
    return true;
}
