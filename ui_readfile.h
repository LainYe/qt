/********************************************************************************
** Form generated from reading UI file 'readfile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READFILE_H
#define UI_READFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readFile
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QPushButton *choosefile;
    QPushButton *back;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *readFile)
    {
        if (readFile->objectName().isEmpty())
            readFile->setObjectName(QString::fromUtf8("readFile"));
        readFile->resize(400, 300);
        widget = new QWidget(readFile);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 40, 161, 121));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        choosefile = new QPushButton(widget);
        choosefile->setObjectName(QString::fromUtf8("choosefile"));

        gridLayout->addWidget(choosefile, 2, 1, 1, 1);

        back = new QPushButton(widget);
        back->setObjectName(QString::fromUtf8("back"));

        gridLayout->addWidget(back, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);


        retranslateUi(readFile);

        QMetaObject::connectSlotsByName(readFile);
    } // setupUi

    void retranslateUi(QWidget *readFile)
    {
        readFile->setWindowTitle(QApplication::translate("readFile", "Form", nullptr));
        choosefile->setText(QApplication::translate("readFile", "\351\200\211\346\213\251\345\255\230\346\241\243\346\226\207\344\273\266", nullptr));
        back->setText(QApplication::translate("readFile", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readFile: public Ui_readFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READFILE_H
