#include "rules.h"
#include "ui_rules.h"
#include <QList>
Rules::Rules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rules)
{
    ui->setupUi(this);
    _ui = ui;
}

Rules::~Rules()
{
    delete ui;
}
