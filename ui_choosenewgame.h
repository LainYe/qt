/********************************************************************************
** Form generated from reading UI file 'choosenewgame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSENEWGAME_H
#define UI_CHOOSENEWGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseNewGame
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *singlemode;
    QPushButton *endlessmode;
    QPushButton *pairmode;
    QPushButton *pushButton_4;

    void setupUi(QWidget *ChooseNewGame)
    {
        if (ChooseNewGame->objectName().isEmpty())
            ChooseNewGame->setObjectName(QString::fromUtf8("ChooseNewGame"));
        ChooseNewGame->resize(400, 300);
        widget = new QWidget(ChooseNewGame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 50, 151, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        singlemode = new QPushButton(widget);
        singlemode->setObjectName(QString::fromUtf8("singlemode"));

        verticalLayout->addWidget(singlemode);

        endlessmode = new QPushButton(widget);
        endlessmode->setObjectName(QString::fromUtf8("endlessmode"));

        verticalLayout->addWidget(endlessmode);

        pairmode = new QPushButton(widget);
        pairmode->setObjectName(QString::fromUtf8("pairmode"));

        verticalLayout->addWidget(pairmode);

        pushButton_4 = new QPushButton(ChooseNewGame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 230, 80, 20));

        retranslateUi(ChooseNewGame);

        QMetaObject::connectSlotsByName(ChooseNewGame);
    } // setupUi

    void retranslateUi(QWidget *ChooseNewGame)
    {
        ChooseNewGame->setWindowTitle(QApplication::translate("ChooseNewGame", "Form", nullptr));
        singlemode->setText(QApplication::translate("ChooseNewGame", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        endlessmode->setText(QApplication::translate("ChooseNewGame", "\346\227\240\345\260\275\346\250\241\345\274\217", nullptr));
        pairmode->setText(QApplication::translate("ChooseNewGame", "\345\217\214\344\272\272\346\250\241\345\274\217", nullptr));
        pushButton_4->setText(QApplication::translate("ChooseNewGame", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseNewGame: public Ui_ChooseNewGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSENEWGAME_H
