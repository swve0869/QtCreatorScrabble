/********************************************************************************
** Form generated from reading UI file 'blankcreater.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLANKCREATER_H
#define UI_BLANKCREATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_blankCreater
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *textEdit;

    void setupUi(QDialog *blankCreater)
    {
        if (blankCreater->objectName().isEmpty())
            blankCreater->setObjectName("blankCreater");
        blankCreater->resize(122, 129);
        pushButton = new QPushButton(blankCreater);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 80, 100, 32));
        label = new QLabel(blankCreater);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 101, 16));
        textEdit = new QLineEdit(blankCreater);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(50, 40, 21, 21));

        retranslateUi(blankCreater);

        QMetaObject::connectSlotsByName(blankCreater);
    } // setupUi

    void retranslateUi(QDialog *blankCreater)
    {
        blankCreater->setWindowTitle(QCoreApplication::translate("blankCreater", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("blankCreater", "Submit", nullptr));
        label->setText(QCoreApplication::translate("blankCreater", "Enter a letter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class blankCreater: public Ui_blankCreater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLANKCREATER_H
