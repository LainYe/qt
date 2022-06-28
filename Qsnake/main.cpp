#include "mainwindow.h"
#include "test.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!initial_test())
        return 0;
    MainWindow w;
    w.show();
    qDebug()<<"可执行文件所在目录:"<<QCoreApplication::applicationDirPath();
    return a.exec();
}
