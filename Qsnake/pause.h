#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>
#include "endlessmode.h"

namespace Ui {
class Pause;
}

class Pause : public QWidget
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = nullptr);
    ~Pause();
    EndlessMode *father;

private:
    Ui::Pause *ui;
};

#endif // PAUSE_H
