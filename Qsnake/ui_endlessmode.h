/********************************************************************************
** Form generated from reading UI file 'endlessmode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDLESSMODE_H
#define UI_ENDLESSMODE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndlessMode
{
public:

    void setupUi(QWidget *EndlessMode)
    {
        if (EndlessMode->objectName().isEmpty())
            EndlessMode->setObjectName(QString::fromUtf8("EndlessMode"));
        EndlessMode->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        EndlessMode->setWindowIcon(icon);

        retranslateUi(EndlessMode);

        QMetaObject::connectSlotsByName(EndlessMode);
    } // setupUi

    void retranslateUi(QWidget *EndlessMode)
    {
        EndlessMode->setWindowTitle(QCoreApplication::translate("EndlessMode", "\346\227\240\345\260\275\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndlessMode: public Ui_EndlessMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDLESSMODE_H
