/********************************************************************************
** Form generated from reading UI file 'opendialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENDIALOG_H
#define UI_OPENDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_openDialog
{
public:
    QLabel *label;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *fourButton;
    QLabel *label_2;

    void setupUi(QDialog *openDialog)
    {
        if (openDialog->objectName().isEmpty())
            openDialog->setObjectName("openDialog");
        openDialog->resize(618, 280);
        label = new QLabel(openDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 20, 311, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        twoButton = new QPushButton(openDialog);
        twoButton->setObjectName("twoButton");
        twoButton->setGeometry(QRect(110, 150, 91, 81));
        QFont font1;
        font1.setPointSize(30);
        twoButton->setFont(font1);
        threeButton = new QPushButton(openDialog);
        threeButton->setObjectName("threeButton");
        threeButton->setGeometry(QRect(260, 150, 91, 81));
        threeButton->setFont(font1);
        fourButton = new QPushButton(openDialog);
        fourButton->setObjectName("fourButton");
        fourButton->setGeometry(QRect(420, 150, 91, 81));
        fourButton->setFont(font1);
        label_2 = new QLabel(openDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 100, 111, 16));

        retranslateUi(openDialog);

        QMetaObject::connectSlotsByName(openDialog);
    } // setupUi

    void retranslateUi(QDialog *openDialog)
    {
        openDialog->setWindowTitle(QCoreApplication::translate("openDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("openDialog", "Welcome to Swami's Super Scrabble!", nullptr));
        twoButton->setText(QCoreApplication::translate("openDialog", "2", nullptr));
        threeButton->setText(QCoreApplication::translate("openDialog", "3", nullptr));
        fourButton->setText(QCoreApplication::translate("openDialog", "4", nullptr));
        label_2->setText(QCoreApplication::translate("openDialog", "How many Players", nullptr));
    } // retranslateUi

};

namespace Ui {
    class openDialog: public Ui_openDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENDIALOG_H
