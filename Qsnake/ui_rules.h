/********************************************************************************
** Form generated from reading UI file 'rules.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULES_H
#define UI_RULES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rules
{
public:
    QTreeWidget *treeWidget;
    QPushButton *back;

    void setupUi(QWidget *Rules)
    {
        if (Rules->objectName().isEmpty())
            Rules->setObjectName(QString::fromUtf8("Rules"));
        Rules->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Rules->sizePolicy().hasHeightForWidth());
        Rules->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        Rules->setWindowIcon(icon);
        treeWidget = new QTreeWidget(Rules);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem6);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 601, 401));
        back = new QPushButton(Rules);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(440, 330, 80, 20));

        retranslateUi(Rules);

        QMetaObject::connectSlotsByName(Rules);
    } // setupUi

    void retranslateUi(QWidget *Rules)
    {
        Rules->setWindowTitle(QCoreApplication::translate("Rules", "\350\247\204\345\210\231", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Rules", "1", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("Rules", "\346\270\270\346\210\217\347\256\200\344\273\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("Rules", "\345\206\205\345\256\271\357\274\232", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("Rules", "\346\234\254\346\270\270\346\210\217\345\220\215\344\270\272\342\200\234\350\264\252\345\220\203\350\233\207\345\244\247\344\275\234\346\210\230\342\200\235\357\274\214\346\230\257\344\270\200\346\254\276\350\275\273\346\235\276\343\200\201\347\233\212", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("Rules", "\346\231\272\343\200\201\344\274\221\351\227\262\347\232\204\345\260\217\346\270\270\346\210\217\343\200\202\346\270\270\346\210\217\345\210\206\344\270\272\344\270\211\347\247\215\346\250\241\345\274\217\357\274\214\345\210\206\345\210\253", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem2->child(2);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("Rules", "\344\270\272\346\214\221\346\210\230\346\231\272\345\212\233\347\232\204\345\215\225\344\272\272\346\250\241\345\274\217\343\200\201\350\266\205\350\266\212\346\236\201\351\231\220\347\232\204\346\227\240\345\260\275\346\250\241\345\274\217", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem2->child(3);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("Rules", "\345\222\214PK\350\203\275\345\212\233\347\232\204\345\217\214\344\272\272\346\250\241\345\274\217\343\200\202\346\234\254\346\270\270\346\210\217\345\205\205\345\210\206\345\215\217\350\260\203\344\272\206\345\215\225\344\272\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem2->child(4);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("Rules", "\344\274\221\351\227\262\344\270\216\345\217\214\344\272\272\345\250\261\344\271\220\347\232\204\345\212\237\350\203\275\357\274\214\346\230\257\344\270\200\346\254\276\344\274\230\347\247\200\347\232\204\345\260\217\346\270\270\346\210\217\343\200\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("Rules", "\345\210\266\344\275\234\350\200\205\357\274\232", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("Rules", "\345\210\266\344\275\234\350\200\205\344\270\272\345\214\227\344\272\254\345\244\247\345\255\246\344\277\241\346\201\257\347\247\221\345\255\246\346\212\200\346\234\257\345\255\246\351\231\242\345\220\214\345\255\246\350\265\265\346\275\207", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("Rules", "\346\231\227\343\200\201\346\257\233\345\230\211\346\245\267\343\200\201\350\277\236\347\203\250\357\274\210\351\230\237\351\225\277\357\274\211\344\270\211\344\275\215\345\220\214\345\255\246\347\273\204\346\210\220\347\232\204\342\200\234\345\244\252", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem8->child(2);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("Rules", "\351\230\237\344\272\206\345\223\245\342\200\235\347\250\213\345\272\217\350\256\276\350\256\241\345\256\236\344\271\240\350\257\276\347\250\213\345\260\217\347\273\204\357\274\214\345\210\266\344\275\234\344\272\2162022", nullptr));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem8->child(3);
        ___qtreewidgetitem12->setText(0, QCoreApplication::translate("Rules", "\345\271\2646\346\234\210\343\200\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem13->setText(0, QCoreApplication::translate("Rules", "\347\211\271\345\210\253\351\270\243\350\260\242\357\274\232", nullptr));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem13->child(0);
        ___qtreewidgetitem14->setText(0, QCoreApplication::translate("Rules", "\350\241\267\345\277\203\346\204\237\350\260\242\345\274\240\345\213\244\345\273\272\350\200\201\345\270\210\347\232\204\346\225\231\345\257\274\344\270\216\351\273\204\350\207\264\347\204\225\345\255\246\351\225\277\347\255\211", nullptr));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem13->child(1);
        ___qtreewidgetitem15->setText(0, QCoreApplication::translate("Rules", "\345\212\251\346\225\231\347\232\204\345\270\256\345\212\251\357\274\201", nullptr));
        QTreeWidgetItem *___qtreewidgetitem16 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem16->setText(0, QCoreApplication::translate("Rules", "\346\270\270\346\210\217\346\250\241\345\274\217", nullptr));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem16->child(0);
        ___qtreewidgetitem17->setText(0, QCoreApplication::translate("Rules", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem17->child(0);
        ___qtreewidgetitem18->setText(0, QCoreApplication::translate("Rules", "\347\216\251\345\256\266\346\216\247\345\210\266\350\264\252\345\220\203\350\233\207\357\274\214\351\200\232\350\277\207\344\270\212\344\270\213\345\267\246\345\217\263\346\214\211\351\222\256\357\274\214\350\277\233\350\241\214\344\270\212", nullptr));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem17->child(1);
        ___qtreewidgetitem19->setText(0, QCoreApplication::translate("Rules", "\344\270\213\345\267\246\345\217\263\347\232\204\346\223\215\344\275\234\343\200\202\347\242\260\345\210\260\345\242\231\346\210\226\345\222\254\345\210\260\350\207\252\345\267\261\345\210\231\346\255\273\344\272\241\357\274\214\351\200\211", nullptr));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem17->child(2);
        ___qtreewidgetitem20->setText(0, QCoreApplication::translate("Rules", "\346\213\251\346\230\257\345\220\246\351\207\215\346\226\260\346\270\270\346\210\217\343\200\202\350\264\252\345\220\203\350\233\207\345\220\203\345\210\260\350\213\271\346\236\234\344\274\232\345\242\236\345\212\240\351\225\277\345\272\246\343\200\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem21 = ___qtreewidgetitem17->child(3);
        ___qtreewidgetitem21->setText(0, QCoreApplication::translate("Rules", "\350\264\252\345\220\203\350\233\207\351\200\232\350\277\207\346\210\220\345\212\237\350\277\233\345\205\245\346\264\236\345\217\243\350\277\233\345\205\245\344\270\213\344\270\200\345\205\263\347\232\204\346\270\270\346\210\217\343\200\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem22 = ___qtreewidgetitem17->child(4);
        ___qtreewidgetitem22->setText(0, QCoreApplication::translate("Rules", "\346\257\217\344\270\200\345\205\263\346\270\270\346\210\217\347\232\204\345\234\260\345\233\276\344\270\216\350\233\207\347\232\204\345\210\235\345\247\213\347\212\266\346\200\201\351\203\275\344\270\215\345\220\214\343\200\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem23 = ___qtreewidgetitem16->child(1);
        ___qtreewidgetitem23->setText(0, QCoreApplication::translate("Rules", "\346\227\240\345\260\275\346\250\241\345\274\217", nullptr));
        QTreeWidgetItem *___qtreewidgetitem24 = ___qtreewidgetitem23->child(0);
        ___qtreewidgetitem24->setText(0, QCoreApplication::translate("Rules", "\346\227\240\345\260\275\346\250\241\345\274\217\344\270\255\357\274\214\347\216\251\345\256\266\346\216\247\345\210\266\350\264\252\345\220\203\350\233\207\357\274\214\351\200\232\350\277\207\344\270\212\344\270\213\345\267\246\345\217\263", nullptr));
        QTreeWidgetItem *___qtreewidgetitem25 = ___qtreewidgetitem23->child(1);
        ___qtreewidgetitem25->setText(0, QCoreApplication::translate("Rules", "\346\214\211\351\222\256\357\274\214\350\277\233\350\241\214\344\270\212\344\270\213\345\267\246\345\217\263\347\232\204\346\223\215\344\275\234\343\200\202\347\242\260\345\210\260\345\242\231\346\210\226\345\222\254\345\210\260\350\207\252", nullptr));
        QTreeWidgetItem *___qtreewidgetitem26 = ___qtreewidgetitem23->child(2);
        ___qtreewidgetitem26->setText(0, QCoreApplication::translate("Rules", "\345\267\261\345\210\231\346\255\273\344\272\241\357\274\214\351\200\211\346\213\251\346\230\257\345\220\246\351\207\215\346\226\260\346\270\270\346\210\217\343\200\202\350\264\252\345\220\203\350\233\207\345\220\203\345\210\260\350\213\271", nullptr));
        QTreeWidgetItem *___qtreewidgetitem27 = ___qtreewidgetitem23->child(3);
        ___qtreewidgetitem27->setText(0, QCoreApplication::translate("Rules", "\346\236\234\344\274\232\345\242\236\345\212\240\351\225\277\345\272\246\343\200\202\345\234\260\345\233\276\344\270\272\345\233\272\345\256\232\347\232\204\346\255\243\346\226\271\345\275\242\347\212\266\346\200\201\343\200\202\346\257\217", nullptr));
        QTreeWidgetItem *___qtreewidgetitem28 = ___qtreewidgetitem23->child(4);
        ___qtreewidgetitem28->setText(0, QCoreApplication::translate("Rules", "\351\232\224\344\270\200\346\256\265\346\227\266\351\227\264\357\274\214\345\234\260\345\233\276\345\260\261\344\274\232\346\211\251\345\244\247\357\274\210\345\257\271\345\272\224\347\235\200\350\264\252\345\220\203\350\233\207\345\260\261", nullptr));
        QTreeWidgetItem *___qtreewidgetitem29 = ___qtreewidgetitem23->child(5);
        ___qtreewidgetitem29->setText(0, QCoreApplication::translate("Rules", "\344\274\232\347\274\251\345\260\217\357\274\211\357\274\214\344\273\245\345\272\224\345\257\271\350\264\252\345\220\203\350\233\207\350\203\200\345\244\247\347\232\204\350\272\253\344\275\223\343\200\202\350\264\252\345\220\203\350\233\207", nullptr));
        QTreeWidgetItem *___qtreewidgetitem30 = ___qtreewidgetitem23->child(6);
        ___qtreewidgetitem30->setText(0, QCoreApplication::translate("Rules", "\347\232\204\351\200\237\345\272\246\343\200\201\345\210\206\346\225\260\343\200\201\346\234\200\351\253\230\345\210\206\346\225\260\345\234\250\344\270\200\346\227\201\345\235\207\344\274\232\346\234\211\346\211\200\346\230\276\347\244\272\343\200\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem31 = ___qtreewidgetitem16->child(2);
        ___qtreewidgetitem31->setText(0, QCoreApplication::translate("Rules", "\345\217\214\344\272\272\346\250\241\345\274\217", nullptr));
        QTreeWidgetItem *___qtreewidgetitem32 = ___qtreewidgetitem31->child(0);
        ___qtreewidgetitem32->setText(0, QCoreApplication::translate("Rules", "\345\217\214\344\272\272\346\250\241\345\274\217\344\270\255\357\274\214\344\270\244\345\220\215\347\216\251\345\256\266\346\223\215\346\216\247\344\270\244\346\235\241\350\264\252\345\220\203\350\233\207\343\200\202\344\270\200\345\220\215", nullptr));
        QTreeWidgetItem *___qtreewidgetitem33 = ___qtreewidgetitem31->child(1);
        ___qtreewidgetitem33->setText(0, QCoreApplication::translate("Rules", "\347\216\251\345\256\266\351\200\232\350\277\207W\357\274\214S\357\274\214A\357\274\214D\345\233\233\344\270\252\346\214\211\351\224\256\346\223\215\346\216\247\350\264\252\345\220\203\350\233\207Pl", nullptr));
        QTreeWidgetItem *___qtreewidgetitem34 = ___qtreewidgetitem31->child(2);
        ___qtreewidgetitem34->setText(0, QCoreApplication::translate("Rules", "ayer1,\344\270\200\345\220\215\347\216\251\345\256\266\351\200\232\350\277\207\344\270\212\344\270\213\345\267\246\345\217\263\346\214\211\351\224\256\346\223\215\346\216\247\350\264\252\345\220\203\350\233\207", nullptr));
        QTreeWidgetItem *___qtreewidgetitem35 = ___qtreewidgetitem31->child(3);
        ___qtreewidgetitem35->setText(0, QCoreApplication::translate("Rules", "Player2\343\200\202\344\273\273\344\275\225\344\270\200\346\235\241\350\233\207\347\242\260\345\242\231\346\210\226\350\200\205\345\222\254\345\210\260\350\207\252\345\267\261\345\235\207\350\247\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem36 = ___qtreewidgetitem31->child(4);
        ___qtreewidgetitem36->setText(0, QCoreApplication::translate("Rules", "\344\270\272\346\255\273\344\272\241\357\274\214\345\217\246\344\270\200\346\226\271\350\216\267\350\203\234\343\200\202\345\220\214\346\227\266\346\255\273\344\272\241\345\210\231\350\247\206\344\270\272\345\271\263\345\261\200\343\200\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem37 = ___qtreewidgetitem31->child(5);
        ___qtreewidgetitem37->setText(0, QCoreApplication::translate("Rules", "\344\273\273\344\275\225\344\270\200\346\235\241\350\233\207\345\220\203\345\210\260\350\213\271\346\236\234\344\274\232\345\242\236\345\212\240\351\225\277\345\272\246\343\200\202\344\270\200\346\235\241\350\233\207\345\222\254\345\210\260", nullptr));
        QTreeWidgetItem *___qtreewidgetitem38 = ___qtreewidgetitem31->child(6);
        ___qtreewidgetitem38->setText(0, QCoreApplication::translate("Rules", "\345\217\246\344\270\200\346\235\241\350\233\207\347\232\204\345\260\276\351\203\250\357\274\214\344\274\232\345\260\206\345\205\266\345\222\254\346\226\255\357\274\214\344\273\244\345\205\266\345\217\252\344\277\235\347\225\231\346\222\225", nullptr));
        QTreeWidgetItem *___qtreewidgetitem39 = ___qtreewidgetitem31->child(7);
        ___qtreewidgetitem39->setText(0, QCoreApplication::translate("Rules", "\345\222\254\345\244\204\345\210\260\345\244\264\351\203\250\347\232\204\351\225\277\345\272\246\343\200\202\350\213\245\344\270\244\346\235\241\350\233\207\347\232\204\345\244\264\351\203\250\347\233\270\347\242\260\357\274\214\350\247\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem40 = ___qtreewidgetitem31->child(8);
        ___qtreewidgetitem40->setText(0, QCoreApplication::translate("Rules", "\344\270\272\345\271\263\345\261\200\343\200\202\346\257\217\345\261\200\346\270\270\346\210\217\346\227\266\351\227\264\344\270\272\344\270\244\345\210\206\351\222\237\357\274\214\346\227\266\351\227\264\345\210\260\346\227\266\357\274\214", nullptr));
        QTreeWidgetItem *___qtreewidgetitem41 = ___qtreewidgetitem31->child(9);
        ___qtreewidgetitem41->setText(0, QCoreApplication::translate("Rules", "\346\233\264\351\225\277\347\232\204\344\270\200\346\226\271\350\216\267\350\203\234\357\274\214\350\213\245\344\270\200\346\240\267\351\225\277\357\274\214\345\210\231\350\247\206\344\270\272\345\271\263\345\261\200\343\200\202\345\200\222", nullptr));
        QTreeWidgetItem *___qtreewidgetitem42 = ___qtreewidgetitem31->child(10);
        ___qtreewidgetitem42->setText(0, QCoreApplication::translate("Rules", "\350\256\241\346\227\266\350\256\276\347\275\256\345\234\250\345\217\263\346\226\271\357\274\214\345\271\266\344\270\224\351\232\217\346\227\266\345\261\225\347\244\272\344\270\244\346\235\241\350\233\207\347\232\204\351\225\277\345\272\246", nullptr));
        QTreeWidgetItem *___qtreewidgetitem43 = ___qtreewidgetitem31->child(11);
        ___qtreewidgetitem43->setText(0, QCoreApplication::translate("Rules", "\344\270\216\351\200\237\345\272\246\357\274\210\344\270\244\346\235\241\350\233\207\347\232\204\351\200\237\345\272\246\345\220\214\346\227\266\345\242\236\345\212\240\357\274\211\343\200\202\345\275\223\345\200\222\350\256\241\346\227\266", nullptr));
        QTreeWidgetItem *___qtreewidgetitem44 = ___qtreewidgetitem31->child(12);
        ___qtreewidgetitem44->setText(0, QCoreApplication::translate("Rules", "\345\210\260\350\276\27660\347\247\222\357\274\21430\347\247\222\345\222\21410\347\247\222\346\227\266\357\274\214\345\200\222\350\256\241\346\227\266\344\274\232\345\210\206\345\210\253\345\217\230", nullptr));
        QTreeWidgetItem *___qtreewidgetitem45 = ___qtreewidgetitem31->child(13);
        ___qtreewidgetitem45->setText(0, QCoreApplication::translate("Rules", "\344\270\272\347\273\277\350\211\262\343\200\201\351\273\204\350\211\262\343\200\201\347\272\242\350\211\262\344\273\245\346\217\220\347\244\272\347\216\251\345\256\266\343\200\202", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        back->setText(QCoreApplication::translate("Rules", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rules: public Ui_Rules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULES_H
