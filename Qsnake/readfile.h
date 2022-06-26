#ifndef READFILE_H
#define READFILE_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class readFile;
}

class readFile : public QWidget
{
    Q_OBJECT

public:
    explicit readFile(QWidget *parent = nullptr);
    ~readFile();
    MainWindow *father;

private:
    Ui::readFile *ui;
};

#endif // READFILE_H
