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

    explicit readFile(QWidget *parent = nullptr, int mode = 0);
    ~readFile();
    QWidget *father;

private:
    Ui::readFile *ui;
};

#endif // READFILE_H
