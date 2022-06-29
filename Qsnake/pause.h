#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>
#include "endlessmode.h"
#include "singlemode.h"
#include "pairmode.h"

namespace Ui {
class Pause;
}

class Pause : public QWidget
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = nullptr, int mode = 0);
    ~Pause();
    EndlessMode *father1 = 0;
    SingleMode *father2 = 0;
    PairMode *father3 = 0;
private:
    Ui::Pause *ui;
};

#endif // PAUSE_H
