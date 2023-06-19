/********************************************************************************
** Form generated from reading UI file 'enddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDDIALOG_H
#define UI_ENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_endDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *endDialog)
    {
        if (endDialog->objectName().isEmpty())
            endDialog->setObjectName("endDialog");
        endDialog->resize(244, 180);
        label = new QLabel(endDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 81, 16));

        retranslateUi(endDialog);

        QMetaObject::connectSlotsByName(endDialog);
    } // setupUi

    void retranslateUi(QDialog *endDialog)
    {
        endDialog->setWindowTitle(QCoreApplication::translate("endDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("endDialog", "GAME OVER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class endDialog: public Ui_endDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDDIALOG_H
