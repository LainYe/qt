/********************************************************************************
** Form generated from reading UI file 'singlemode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEMODE_H
#define UI_SINGLEMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleMode
{
public:

    void setupUi(QWidget *SingleMode)
    {
        if (SingleMode->objectName().isEmpty())
            SingleMode->setObjectName(QString::fromUtf8("SingleMode"));
        SingleMode->resize(400, 300);

        retranslateUi(SingleMode);

        QMetaObject::connectSlotsByName(SingleMode);
    } // setupUi

    void retranslateUi(QWidget *SingleMode)
    {
        SingleMode->setWindowTitle(QApplication::translate("SingleMode", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleMode: public Ui_SingleMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEMODE_H
