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
    const QString strScrollCation = QStringLiteral("“made by 太队了哥”");
    void ScrollCation();
private:
    Ui::Rules *ui;
};

#endif // RULES_H
