/********************************************************************************
** Form generated from reading UI file 'readfile.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READFILE_H
#define UI_READFILE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readFile
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *choosefile;
    QSpacerItem *horizontalSpacer;
    QPushButton *back;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;

    void setupUi(QWidget *readFile)
    {
        if (readFile->objectName().isEmpty())
            readFile->setObjectName(QString::fromUtf8("readFile"));
        readFile->resize(600, 400);
        readFile->setMinimumSize(QSize(600, 400));
        readFile->setMaximumSize(QSize(600, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        readFile->setWindowIcon(icon);
        widget = new QWidget(readFile);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(180, 120, 211, 161));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        choosefile = new QPushButton(widget);
        choosefile->setObjectName(QString::fromUtf8("choosefile"));

        gridLayout->addWidget(choosefile, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        back = new QPushButton(widget);
        back->setObjectName(QString::fromUtf8("back"));

        gridLayout->addWidget(back, 4, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        label = new QLabel(readFile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, -50, 611, 451));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/background.gif);"));
        label->raise();
        widget->raise();

        retranslateUi(readFile);

        QMetaObject::connectSlotsByName(readFile);
    } // setupUi

    void retranslateUi(QWidget *readFile)
    {
        readFile->setWindowTitle(QCoreApplication::translate("readFile", "\350\257\273\346\241\243", nullptr));
        choosefile->setText(QCoreApplication::translate("readFile", "\351\200\211\346\213\251\345\255\230\346\241\243\346\226\207\344\273\266", nullptr));
        back->setText(QCoreApplication::translate("readFile", "\350\277\224\345\233\236", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class readFile: public Ui_readFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READFILE_H
