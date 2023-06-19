/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *submitButton;
    QLabel *nameLabel;
    QPushButton *drawButton;
    QPushButton *passButton;
    QPushButton *resignButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(953, 848);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 761, 831));
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(780, 765, 166, 80));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(780, 470, 171, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(15);
        font.setBold(true);
        nameLabel->setFont(font);
        drawButton = new QPushButton(centralwidget);
        drawButton->setObjectName("drawButton");
        drawButton->setGeometry(QRect(780, 606, 166, 80));
        passButton = new QPushButton(centralwidget);
        passButton->setObjectName("passButton");
        passButton->setGeometry(QRect(780, 685, 166, 80));
        resignButton = new QPushButton(centralwidget);
        resignButton->setObjectName("resignButton");
        resignButton->setGeometry(QRect(780, 528, 166, 80));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "l", nullptr));
        drawButton->setText(QCoreApplication::translate("MainWindow", "Draw New", nullptr));
        passButton->setText(QCoreApplication::translate("MainWindow", "Pass", nullptr));
        resignButton->setText(QCoreApplication::translate("MainWindow", "Resign", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
