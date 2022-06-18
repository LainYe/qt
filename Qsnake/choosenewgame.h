#ifndef CHOOSENEWGAME_H
#define CHOOSENEWGAME_H

#include <QWidget>

namespace Ui {
class ChooseNewGame;
}

class ChooseNewGame : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseNewGame(QWidget *parent = nullptr);
    Ui::ChooseNewGame *_ui;//对外的ui指针
    ~ChooseNewGame();

private:
    Ui::ChooseNewGame *ui;
};

#endif // CHOOSENEWGAME_H
