/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelTextWebAddres;
    QLabel *labelImage;
    QLineEdit *lineEditWebAddres;
    QPushButton *pushButtonSendRequest;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonDownloadImage;
    QPushButton *pushButtonNext;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(896, 658);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelTextWebAddres = new QLabel(centralwidget);
        labelTextWebAddres->setObjectName("labelTextWebAddres");
        labelTextWebAddres->setGeometry(QRect(20, 40, 131, 31));
        labelImage = new QLabel(centralwidget);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(30, 90, 761, 421));
        lineEditWebAddres = new QLineEdit(centralwidget);
        lineEditWebAddres->setObjectName("lineEditWebAddres");
        lineEditWebAddres->setGeometry(QRect(120, 40, 471, 28));
        pushButtonSendRequest = new QPushButton(centralwidget);
        pushButtonSendRequest->setObjectName("pushButtonSendRequest");
        pushButtonSendRequest->setGeometry(QRect(650, 40, 181, 29));
        pushButtonBack = new QPushButton(centralwidget);
        pushButtonBack->setObjectName("pushButtonBack");
        pushButtonBack->setGeometry(QRect(30, 550, 121, 29));
        pushButtonDownloadImage = new QPushButton(centralwidget);
        pushButtonDownloadImage->setObjectName("pushButtonDownloadImage");
        pushButtonDownloadImage->setGeometry(QRect(292, 550, 201, 29));
        pushButtonNext = new QPushButton(centralwidget);
        pushButtonNext->setObjectName("pushButtonNext");
        pushButtonNext->setGeometry(QRect(662, 550, 111, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 896, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelTextWebAddres->setText(QCoreApplication::translate("MainWindow", "Web addres:", nullptr));
        labelImage->setText(QString());
        pushButtonSendRequest->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\271", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButtonDownloadImage->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\260\321\207\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\320\265\321\200\321\221\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
