/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *readFile;
    QPushButton *rules;
    QSpacerItem *horizontalSpacer;
    QPushButton *newGame;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *quit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(600, 400));
        centralwidget->setMaximumSize(QSize(600, 400));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 190, 281, 141));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        readFile = new QPushButton(layoutWidget);
        readFile->setObjectName(QString::fromUtf8("readFile"));

        gridLayout->addWidget(readFile, 1, 1, 1, 1);

        rules = new QPushButton(layoutWidget);
        rules->setObjectName(QString::fromUtf8("rules"));

        gridLayout->addWidget(rules, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        newGame = new QPushButton(layoutWidget);
        newGame->setObjectName(QString::fromUtf8("newGame"));

        gridLayout->addWidget(newGame, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        quit = new QPushButton(layoutWidget);
        quit->setObjectName(QString::fromUtf8("quit"));

        gridLayout->addWidget(quit, 1, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-20, -180, 621, 591));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(12540124, 16777215));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/headline.png);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-10, -80, 611, 491));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/background.gif);"));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label->raise();
        layoutWidget->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\264\252\345\220\203\350\233\207\345\244\247\344\275\234\346\210\230", nullptr));
        readFile->setText(QCoreApplication::translate("MainWindow", "\350\257\273\346\241\243", nullptr));
        rules->setText(QCoreApplication::translate("MainWindow", "\350\247\204\345\210\231", nullptr));
        newGame->setText(QCoreApplication::translate("MainWindow", "\346\226\260\346\270\270\346\210\217", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
