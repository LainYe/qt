#ifndef CHOOSENEWGAME_H
#define CHOOSENEWGAME_H

#include <QWidget>
#include "mainwindow.h"
#include "endlessmode.h"
#include "singlemode.h"
#include "pairmode.h"

namespace Ui {
class ChooseNewGame;
}

class ChooseNewGame : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseNewGame(QWidget *parent = nullptr);
    MainWindow* father;
    ~ChooseNewGame();

private:
    Ui::ChooseNewGame *ui;
};

#endif // CHOOSENEWGAME_H
