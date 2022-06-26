#include "mainwindow.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug()<<"可执行文件所在目录:"<<QCoreApplication::applicationDirPath();
    return a.exec();
}
