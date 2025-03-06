/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ViewBooks;
    QPushButton *Accouting;
    QPushButton *AddBook;
    QPushButton *DeleteBook;
    QPushButton *GiveBook;
    QPushButton *ReturnBook;
    QTableWidget *tableWidget;
    QPushButton *ViewUsers;
    QPushButton *AddUser;
    QPushButton *DeleteUser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1293, 790);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ViewBooks = new QPushButton(centralwidget);
        ViewBooks->setObjectName("ViewBooks");
        ViewBooks->setGeometry(QRect(270, 0, 231, 81));
        Accouting = new QPushButton(centralwidget);
        Accouting->setObjectName("Accouting");
        Accouting->setGeometry(QRect(530, 0, 231, 81));
        AddBook = new QPushButton(centralwidget);
        AddBook->setObjectName("AddBook");
        AddBook->setGeometry(QRect(0, 190, 231, 71));
        DeleteBook = new QPushButton(centralwidget);
        DeleteBook->setObjectName("DeleteBook");
        DeleteBook->setGeometry(QRect(0, 260, 231, 71));
        GiveBook = new QPushButton(centralwidget);
        GiveBook->setObjectName("GiveBook");
        GiveBook->setGeometry(QRect(0, 540, 231, 71));
        ReturnBook = new QPushButton(centralwidget);
        ReturnBook->setObjectName("ReturnBook");
        ReturnBook->setGeometry(QRect(0, 610, 231, 71));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(260, 110, 771, 651));
        ViewUsers = new QPushButton(centralwidget);
        ViewUsers->setObjectName("ViewUsers");
        ViewUsers->setGeometry(QRect(790, 0, 231, 81));
        AddUser = new QPushButton(centralwidget);
        AddUser->setObjectName("AddUser");
        AddUser->setGeometry(QRect(1060, 540, 231, 71));
        DeleteUser = new QPushButton(centralwidget);
        DeleteUser->setObjectName("DeleteUser");
        DeleteUser->setGeometry(QRect(1060, 610, 231, 71));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1293, 25));
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
        ViewBooks->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\272\320\275\320\270\320\263", nullptr));
        Accouting->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\262\321\213\320\264\320\260\321\207\320\270\n"
" \320\270 \320\262\320\276\320\267\320\262\321\200\320\260\321\202\320\260 \320\272\320\275\320\270\320\263", nullptr));
        AddBook->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        DeleteBook->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        GiveBook->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\264\320\260\321\207\320\260 \320\272\320\275\320\270\320\263\320\270", nullptr));
        ReturnBook->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\320\262\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        ViewUsers->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\272\320\276 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\320\265\320\271\n"
" \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\270", nullptr));
        AddUser->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        DeleteUser->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
