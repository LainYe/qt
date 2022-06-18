#ifndef RULES_H
#define RULES_H

#include <QWidget>

namespace Ui {
class Rules;
}

class Rules : public QWidget
{
    Q_OBJECT

public:
    explicit Rules(QWidget *parent = nullptr);
    ~Rules();
    Ui::Rules* _ui;//对外的ui指针

private:
    Ui::Rules *ui;
};

#endif // RULES_H
