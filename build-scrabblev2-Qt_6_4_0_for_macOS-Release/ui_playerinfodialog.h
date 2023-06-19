/********************************************************************************
** Form generated from reading UI file 'playerinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERINFODIALOG_H
#define UI_PLAYERINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_playerInfoDialog
{
public:

    void setupUi(QDialog *playerInfoDialog)
    {
        if (playerInfoDialog->objectName().isEmpty())
            playerInfoDialog->setObjectName("playerInfoDialog");
        playerInfoDialog->resize(489, 280);

        retranslateUi(playerInfoDialog);

        QMetaObject::connectSlotsByName(playerInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *playerInfoDialog)
    {
        playerInfoDialog->setWindowTitle(QCoreApplication::translate("playerInfoDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playerInfoDialog: public Ui_playerInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERINFODIALOG_H
