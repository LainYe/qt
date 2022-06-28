#ifndef RULES_H
#define RULES_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Rules;
}

class Rules : public QWidget
{
    Q_OBJECT

public:
    explicit Rules(QWidget *parent = nullptr);
    ~Rules();
    MainWindow *father;

private:
    Ui::Rules *ui;
};

#endif // RULES_H
