/********************************************************************************
** Form generated from reading UI file 'pause.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSE_H
#define UI_PAUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pause
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *back;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *read;
    QSpacerItem *horizontalSpacer;
    QPushButton *save;
    QPushButton *exit;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Pause)
    {
        if (Pause->objectName().isEmpty())
            Pause->setObjectName(QString::fromUtf8("Pause"));
        Pause->resize(400, 300);
        widget = new QWidget(Pause);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(143, 119, 221, 151));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        back = new QPushButton(widget);
        back->setObjectName(QString::fromUtf8("back"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(back->sizePolicy().hasHeightForWidth());
        back->setSizePolicy(sizePolicy);

        gridLayout->addWidget(back, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 4, 1, 1);

        read = new QPushButton(widget);
        read->setObjectName(QString::fromUtf8("read"));

        gridLayout->addWidget(read, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        save = new QPushButton(widget);
        save->setObjectName(QString::fromUtf8("save"));

        gridLayout->addWidget(save, 2, 3, 1, 1);

        exit = new QPushButton(widget);
        exit->setObjectName(QString::fromUtf8("exit"));

        gridLayout->addWidget(exit, 3, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);


        retranslateUi(Pause);

        QMetaObject::connectSlotsByName(Pause);
    } // setupUi

    void retranslateUi(QWidget *Pause)
    {
        Pause->setWindowTitle(QApplication::translate("Pause", "Form", nullptr));
        back->setText(QApplication::translate("Pause", "\345\233\236\345\210\260\346\270\270\346\210\217", nullptr));
        read->setText(QApplication::translate("Pause", "\350\257\273\346\241\243", nullptr));
        save->setText(QApplication::translate("Pause", "\345\255\230\346\241\243\351\200\200\345\207\272", nullptr));
        exit->setText(QApplication::translate("Pause", "\347\273\223\346\235\237\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pause: public Ui_Pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
