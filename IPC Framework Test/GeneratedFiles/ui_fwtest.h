/********************************************************************************
** Form generated from reading ui file 'fwtest.ui'
**
** Created: Sun 11. Jan 14:40:49 2015
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FWTEST_H
#define UI_FWTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fwtestClass
{
public:
    QWidget *centralWidget;
    QPushButton *Un_Subscribe;
    QPushButton *Subscribe;
    QGroupBox *groupBox;
    QLineEdit *ledAddress;
    QLineEdit *ledPort;
    QPushButton *Start_Framework;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ledAddress_2;
    QTextEdit *workspaceCLIO;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *devCLIO;
    QTreeWidget *treeWidget;
    QLineEdit *workspaceCLI;
    QTextEdit *Events;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *devCLI;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLineEdit *udpPort;
    QPushButton *startUDP;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *fwtestClass)
    {
        if (fwtestClass->objectName().isEmpty())
            fwtestClass->setObjectName(QString::fromUtf8("fwtestClass"));
        fwtestClass->resize(700, 714);
        fwtestClass->setAutoFillBackground(false);
        centralWidget = new QWidget(fwtestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Un_Subscribe = new QPushButton(centralWidget);
        Un_Subscribe->setObjectName(QString::fromUtf8("Un_Subscribe"));
        Un_Subscribe->setEnabled(false);
        Un_Subscribe->setGeometry(QRect(110, 110, 75, 24));
        Subscribe = new QPushButton(centralWidget);
        Subscribe->setObjectName(QString::fromUtf8("Subscribe"));
        Subscribe->setEnabled(false);
        Subscribe->setGeometry(QRect(20, 110, 75, 24));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(250, 10, 211, 81));
        ledAddress = new QLineEdit(groupBox);
        ledAddress->setObjectName(QString::fromUtf8("ledAddress"));
        ledAddress->setGeometry(QRect(80, 20, 113, 20));
        ledPort = new QLineEdit(groupBox);
        ledPort->setObjectName(QString::fromUtf8("ledPort"));
        ledPort->setGeometry(QRect(50, 50, 51, 20));
        Start_Framework = new QPushButton(groupBox);
        Start_Framework->setObjectName(QString::fromUtf8("Start_Framework"));
        Start_Framework->setGeometry(QRect(110, 50, 91, 24));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 41, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 31, 16));
        ledAddress_2 = new QLineEdit(groupBox);
        ledAddress_2->setObjectName(QString::fromUtf8("ledAddress_2"));
        ledAddress_2->setGeometry(QRect(70, 20, 113, 20));
        workspaceCLIO = new QTextEdit(centralWidget);
        workspaceCLIO->setObjectName(QString::fromUtf8("workspaceCLIO"));
        workspaceCLIO->setGeometry(QRect(200, 166, 491, 191));
        workspaceCLIO->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 670, 161, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 30, 151, 61));
        label_4->setAutoFillBackground(true);
        devCLIO = new QTextEdit(centralWidget);
        devCLIO->setObjectName(QString::fromUtf8("devCLIO"));
        devCLIO->setGeometry(QRect(200, 400, 491, 141));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Logical Workspace Components"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(10, 150, 171, 521));
        workspaceCLI = new QLineEdit(centralWidget);
        workspaceCLI->setObjectName(QString::fromUtf8("workspaceCLI"));
        workspaceCLI->setGeometry(QRect(200, 350, 491, 20));
        workspaceCLI->setAutoFillBackground(false);
        workspaceCLI->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);\n"
"border-top-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));
        Events = new QTextEdit(centralWidget);
        Events->setObjectName(QString::fromUtf8("Events"));
        Events->setGeometry(QRect(200, 600, 491, 91));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(210, 140, 141, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 291, 121, 16));
        label_8->setFont(font);
        devCLI = new QLineEdit(centralWidget);
        devCLI->setObjectName(QString::fromUtf8("devCLI"));
        devCLI->setGeometry(QRect(200, 540, 491, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(220, 370, 51, 21));
        label_6->setFont(font);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 10, 201, 81));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 30, 31, 16));
        udpPort = new QLineEdit(groupBox_2);
        udpPort->setObjectName(QString::fromUtf8("udpPort"));
        udpPort->setGeometry(QRect(50, 30, 51, 20));
        startUDP = new QPushButton(groupBox_2);
        startUDP->setObjectName(QString::fromUtf8("startUDP"));
        startUDP->setGeometry(QRect(110, 30, 71, 21));
        fwtestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(fwtestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        fwtestClass->setStatusBar(statusBar);

        retranslateUi(fwtestClass);

        QMetaObject::connectSlotsByName(fwtestClass);
    } // setupUi

    void retranslateUi(QMainWindow *fwtestClass)
    {
        fwtestClass->setWindowTitle(QApplication::translate("fwtestClass", "fwtest", 0, QApplication::UnicodeUTF8));
        Un_Subscribe->setText(QApplication::translate("fwtestClass", "Unsubscribe", 0, QApplication::UnicodeUTF8));
        Subscribe->setText(QApplication::translate("fwtestClass", "Subscribe", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("fwtestClass", "Communicate With Packet Tracer", 0, QApplication::UnicodeUTF8));
        ledAddress->setText(QApplication::translate("fwtestClass", "localhost", 0, QApplication::UnicodeUTF8));
        ledPort->setText(QApplication::translate("fwtestClass", "39000", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Start_Framework->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        Start_Framework->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        Start_Framework->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        Start_Framework->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        Start_Framework->setText(QApplication::translate("fwtestClass", "Start ...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("fwtestClass", "Address", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("fwtestClass", "Port", 0, QApplication::UnicodeUTF8));
        ledAddress_2->setText(QApplication::translate("fwtestClass", "localhost", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("fwtestClass", "Curtin University of Technology", 0, QApplication::UnicodeUTF8));
        label_4->setStyleSheet(QApplication::translate("fwtestClass", "background-image: url(../newPrefix/curtin.jpg);", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_7->setText(QApplication::translate("fwtestClass", "Workspace Management", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("fwtestClass", "Device Management:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("fwtestClass", "Events:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("fwtestClass", "Communicate With Mac OS", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("fwtestClass", "Port", 0, QApplication::UnicodeUTF8));
        udpPort->setText(QApplication::translate("fwtestClass", "7777", 0, QApplication::UnicodeUTF8));
        startUDP->setText(QApplication::translate("fwtestClass", "Start ...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(fwtestClass);
    } // retranslateUi

};

namespace Ui {
    class fwtestClass: public Ui_fwtestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FWTEST_H
