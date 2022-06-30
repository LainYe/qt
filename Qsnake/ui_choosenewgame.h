/********************************************************************************
** Form generated from reading UI file 'choosenewgame.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSENEWGAME_H
#define UI_CHOOSENEWGAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *ChooseNewGame)
    {
        if (ChooseNewGame->objectName().isEmpty())
            ChooseNewGame->setObjectName(QString::fromUtf8("ChooseNewGame"));
        ChooseNewGame->resize(600, 400);
        ChooseNewGame->setMinimumSize(QSize(600, 400));
        ChooseNewGame->setMaximumSize(QSize(600, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChooseNewGame->setWindowIcon(icon);
        widget = new QWidget(ChooseNewGame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(220, 150, 151, 151));
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
        pushButton_4->setGeometry(QRect(432, 310, 101, 21));
        pushButton_4->setMinimumSize(QSize(0, 0));
        pushButton_4->setMaximumSize(QSize(600, 400));
        label = new QLabel(ChooseNewGame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, -330, 511, 861));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/headline.png);"));
        label_2 = new QLabel(ChooseNewGame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-10, -90, 611, 491));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/background.gif);"));
        label_2->raise();
        label->raise();
        widget->raise();
        pushButton_4->raise();

        retranslateUi(ChooseNewGame);

        QMetaObject::connectSlotsByName(ChooseNewGame);
    } // setupUi

    void retranslateUi(QWidget *ChooseNewGame)
    {
        ChooseNewGame->setWindowTitle(QCoreApplication::translate("ChooseNewGame", "\346\226\260\346\270\270\346\210\217", nullptr));
        singlemode->setText(QCoreApplication::translate("ChooseNewGame", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        endlessmode->setText(QCoreApplication::translate("ChooseNewGame", "\346\227\240\345\260\275\346\250\241\345\274\217", nullptr));
        pairmode->setText(QCoreApplication::translate("ChooseNewGame", "\345\217\214\344\272\272\346\250\241\345\274\217", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ChooseNewGame", "back", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChooseNewGame: public Ui_ChooseNewGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSENEWGAME_H
