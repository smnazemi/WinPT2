/********************************************************************************
** Form generated from reading ui file 'fwtest.ui'
**
** Created: Mon 5. Jan 17:58:42 2015
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
    QPushButton *sendUDP;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *fwtestClass)
    {
        if (fwtestClass->objectName().isEmpty())
            fwtestClass->setObjectName(QString::fromUtf8("fwtestClass"));
        fwtestClass->resize(826, 703);
        fwtestClass->setAutoFillBackground(false);
        centralWidget = new QWidget(fwtestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Un_Subscribe = new QPushButton(centralWidget);
        Un_Subscribe->setObjectName(QString::fromUtf8("Un_Subscribe"));
        Un_Subscribe->setEnabled(false);
        Un_Subscribe->setGeometry(QRect(660, 90, 75, 24));
        Subscribe = new QPushButton(centralWidget);
        Subscribe->setObjectName(QString::fromUtf8("Subscribe"));
        Subscribe->setEnabled(false);
        Subscribe->setGeometry(QRect(570, 90, 75, 24));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 70, 531, 61));
        ledAddress = new QLineEdit(groupBox);
        ledAddress->setObjectName(QString::fromUtf8("ledAddress"));
        ledAddress->setGeometry(QRect(80, 20, 113, 20));
        ledPort = new QLineEdit(groupBox);
        ledPort->setObjectName(QString::fromUtf8("ledPort"));
        ledPort->setGeometry(QRect(260, 20, 113, 20));
        Start_Framework = new QPushButton(groupBox);
        Start_Framework->setObjectName(QString::fromUtf8("Start_Framework"));
        Start_Framework->setGeometry(QRect(420, 20, 91, 24));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 41, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 20, 31, 16));
        workspaceCLIO = new QTextEdit(centralWidget);
        workspaceCLIO->setObjectName(QString::fromUtf8("workspaceCLIO"));
        workspaceCLIO->setGeometry(QRect(200, 156, 491, 191));
        workspaceCLIO->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 660, 161, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 151, 61));
        label_4->setAutoFillBackground(true);
        devCLIO = new QTextEdit(centralWidget);
        devCLIO->setObjectName(QString::fromUtf8("devCLIO"));
        devCLIO->setGeometry(QRect(200, 390, 491, 141));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Logical Workspace Components"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(10, 140, 171, 521));
        workspaceCLI = new QLineEdit(centralWidget);
        workspaceCLI->setObjectName(QString::fromUtf8("workspaceCLI"));
        workspaceCLI->setGeometry(QRect(200, 340, 491, 20));
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
        Events->setGeometry(QRect(200, 590, 491, 91));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(203, 139, 141, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 371, 121, 16));
        label_8->setFont(font);
        devCLI = new QLineEdit(centralWidget);
        devCLI->setObjectName(QString::fromUtf8("devCLI"));
        devCLI->setGeometry(QRect(200, 530, 491, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 570, 51, 21));
        label_6->setFont(font);
        sendUDP = new QPushButton(centralWidget);
        sendUDP->setObjectName(QString::fromUtf8("sendUDP"));
        sendUDP->setGeometry(QRect(390, 20, 161, 41));
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
        Start_Framework->setText(QApplication::translate("fwtestClass", "Start Framework", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("fwtestClass", "Address", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("fwtestClass", "Port", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("fwtestClass", "Curtin University of Technology", 0, QApplication::UnicodeUTF8));
        label_4->setStyleSheet(QApplication::translate("fwtestClass", "background-image: url(../newPrefix/curtin.jpg);", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_7->setText(QApplication::translate("fwtestClass", "Workspace Management", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("fwtestClass", "Device Management:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("fwtestClass", "Events:", 0, QApplication::UnicodeUTF8));
        sendUDP->setText(QApplication::translate("fwtestClass", "Start Communication With Mac", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(fwtestClass);
    } // retranslateUi

};

namespace Ui {
    class fwtestClass: public Ui_fwtestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FWTEST_H
