/********************************************************************************
** Form generated from reading UI file 'singlemode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEMODE_H
#define UI_SINGLEMODE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        SingleMode->setWindowIcon(icon);

        retranslateUi(SingleMode);

        QMetaObject::connectSlotsByName(SingleMode);
    } // setupUi

    void retranslateUi(QWidget *SingleMode)
    {
        SingleMode->setWindowTitle(QCoreApplication::translate("SingleMode", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleMode: public Ui_SingleMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEMODE_H
