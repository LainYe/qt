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
void Rules::ScrollCation(){
    static int pos=0;
    if (pos>strScrollCation.length())
        pos=0;

}
Rules::~Rules()
{
    delete ui;
}
