/********************************************************************************
** Form generated from reading UI file 'pairmode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAIRMODE_H
#define UI_PAIRMODE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        PairMode->setWindowIcon(icon);

        retranslateUi(PairMode);

        QMetaObject::connectSlotsByName(PairMode);
    } // setupUi

    void retranslateUi(QWidget *PairMode)
    {
        PairMode->setWindowTitle(QCoreApplication::translate("PairMode", "\345\217\214\344\272\272\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PairMode: public Ui_PairMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAIRMODE_H
