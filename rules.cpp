#include "rules.h"
#include "ui_rules.h"
#include <QList>
Rules::Rules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rules)
{
    ui->setupUi(this);
    //规则“back”
    connect(ui->back,&QPushButton::clicked,[=](){
        hide();
        father->show();
    });
}

Rules::~Rules()
{
    delete ui;
}
