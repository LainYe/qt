/********************************************************************************
** Form generated from reading UI file 'pairmode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAIRMODE_H
#define UI_PAIRMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PairMode
{
public:

    void setupUi(QWidget *PairMode)
    {
        if (PairMode->objectName().isEmpty())
            PairMode->setObjectName(QString::fromUtf8("PairMode"));
        PairMode->resize(400, 300);

        retranslateUi(PairMode);

        QMetaObject::connectSlotsByName(PairMode);
    } // setupUi

    void retranslateUi(QWidget *PairMode)
    {
        PairMode->setWindowTitle(QApplication::translate("PairMode", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PairMode: public Ui_PairMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAIRMODE_H
