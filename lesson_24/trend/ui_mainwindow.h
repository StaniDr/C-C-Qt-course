/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "glass.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    glass *GLASS;
    QLabel *label_13;
    QDoubleSpinBox *Radius_Edit;
    QFrame *frame_5;
    QFrame *frame_6;
    QPushButton *ChangeButton;
    QFrame *frame_7;
    QPushButton *btnColor;
    QFrame *frame_2;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *P_X_MIN;
    QDoubleSpinBox *P_Y_MIN;
    QLabel *label_16;
    QFrame *frame_3;
    QLabel *label_17;
    QLabel *label_18;
    QDoubleSpinBox *P_X_MAX;
    QDoubleSpinBox *P_Y_MAX;
    QLabel *label_19;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(887, 609);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GLASS = new glass(centralWidget);
        GLASS->setObjectName(QString::fromUtf8("GLASS"));
        GLASS->setGeometry(QRect(10, 110, 861, 431));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 20, 101, 20));
        Radius_Edit = new QDoubleSpinBox(centralWidget);
        Radius_Edit->setObjectName(QString::fromUtf8("Radius_Edit"));
        Radius_Edit->setGeometry(QRect(130, 20, 81, 22));
        Radius_Edit->setDecimals(0);
        Radius_Edit->setMaximum(1000.000000000000000);
        Radius_Edit->setValue(500.000000000000000);
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 10, 211, 41));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(230, 10, 151, 41));
        frame_6->setFrameShape(QFrame::Panel);
        frame_6->setFrameShadow(QFrame::Raised);
        ChangeButton = new QPushButton(frame_6);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));
        ChangeButton->setGeometry(QRect(10, 10, 131, 23));
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(230, 60, 151, 41));
        frame_7->setFrameShape(QFrame::Panel);
        frame_7->setFrameShadow(QFrame::Raised);
        btnColor = new QPushButton(frame_7);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));
        btnColor->setGeometry(QRect(10, 10, 131, 23));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(430, 10, 211, 91));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(90, 50, 31, 20));
        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(90, 20, 41, 20));
        P_X_MIN = new QDoubleSpinBox(frame_2);
        P_X_MIN->setObjectName(QString::fromUtf8("P_X_MIN"));
        P_X_MIN->setGeometry(QRect(110, 20, 81, 22));
        P_X_MIN->setAcceptDrops(false);
        P_X_MIN->setWrapping(false);
        P_X_MIN->setReadOnly(true);
        P_X_MIN->setMaximum(600.000000000000000);
        P_Y_MIN = new QDoubleSpinBox(frame_2);
        P_Y_MIN->setObjectName(QString::fromUtf8("P_Y_MIN"));
        P_Y_MIN->setGeometry(QRect(110, 50, 81, 22));
        P_Y_MIN->setAcceptDrops(false);
        P_Y_MIN->setWrapping(false);
        P_Y_MIN->setReadOnly(true);
        P_Y_MIN->setMaximum(600.000000000000000);
        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 40, 101, 20));
        QFont font;
        font.setPointSize(10);
        label_16->setFont(font);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(650, 10, 221, 91));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_17 = new QLabel(frame_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(100, 50, 31, 20));
        label_18 = new QLabel(frame_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(100, 20, 41, 20));
        P_X_MAX = new QDoubleSpinBox(frame_3);
        P_X_MAX->setObjectName(QString::fromUtf8("P_X_MAX"));
        P_X_MAX->setGeometry(QRect(120, 20, 81, 22));
        P_X_MAX->setAcceptDrops(false);
        P_X_MAX->setWrapping(false);
        P_X_MAX->setReadOnly(true);
        P_X_MAX->setMaximum(600.000000000000000);
        P_Y_MAX = new QDoubleSpinBox(frame_3);
        P_Y_MAX->setObjectName(QString::fromUtf8("P_Y_MAX"));
        P_Y_MAX->setGeometry(QRect(120, 50, 81, 22));
        P_Y_MAX->setAcceptDrops(false);
        P_Y_MAX->setWrapping(false);
        P_Y_MAX->setReadOnly(true);
        P_Y_MAX->setMaximum(600.000000000000000);
        label_19 = new QLabel(frame_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 40, 101, 20));
        label_19->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        frame_5->raise();
        GLASS->raise();
        label_13->raise();
        Radius_Edit->raise();
        frame_6->raise();
        frame_7->raise();
        frame_2->raise();
        frame_3->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 887, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(ChangeButton, SIGNAL(clicked()), MainWindow, SLOT(slotUpdateButton()));
        QObject::connect(btnColor, SIGNAL(clicked()), MainWindow, SLOT(slotColor()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        GLASS->setProperty("rows", QVariant(QApplication::translate("MainWindow", "100", nullptr)));
        GLASS->setProperty("colomns", QVariant(QApplication::translate("MainWindow", "100", nullptr)));
        label_13->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \321\202\320\276\321\207\320\265\320\272", nullptr));
        ChangeButton->setText(QApplication::translate("MainWindow", "Execute", nullptr));
        btnColor->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Y:</span></p></body></html>", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">X:</span></p></body></html>", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Y:</span></p></body></html>", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">X:</span></p></body></html>", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
