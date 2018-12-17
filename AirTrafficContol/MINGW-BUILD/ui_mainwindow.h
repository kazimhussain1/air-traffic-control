/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
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
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLineEdit *VertexNameBox;
    QLabel *label;
    QLineEdit *SourceNameBox;
    QLineEdit *DestinationNameBox;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QComboBox *SourceCombo;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *DestinationCombo;
    QLabel *label_7;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1090, 90, 171, 521));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 110, 80, 21));
        pushButton->setLayoutDirection(Qt::LeftToRight);
        VertexNameBox = new QLineEdit(groupBox);
        VertexNameBox->setObjectName(QStringLiteral("VertexNameBox"));
        VertexNameBox->setGeometry(QRect(22, 70, 131, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 47, 20));
        SourceNameBox = new QLineEdit(groupBox);
        SourceNameBox->setObjectName(QStringLiteral("SourceNameBox"));
        SourceNameBox->setGeometry(QRect(20, 230, 131, 21));
        DestinationNameBox = new QLineEdit(groupBox);
        DestinationNameBox->setObjectName(QStringLiteral("DestinationNameBox"));
        DestinationNameBox->setGeometry(QRect(20, 290, 131, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 200, 51, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 260, 101, 20));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 330, 80, 21));
        pushButton_2->setLayoutDirection(Qt::LeftToRight);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1090, 90, 171, 521));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 131, 31));
        SourceCombo = new QComboBox(groupBox_2);
        SourceCombo->setObjectName(QStringLiteral("SourceCombo"));
        SourceCombo->setGeometry(QRect(50, 120, 72, 22));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 250, 80, 21));
        pushButton_3->setLayoutDirection(Qt::LeftToRight);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 90, 81, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 170, 111, 20));
        DestinationCombo = new QComboBox(groupBox_2);
        DestinationCombo->setObjectName(QStringLiteral("DestinationCombo"));
        DestinationCombo->setGeometry(QRect(50, 200, 72, 22));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(560, 0, 81, 21));
        label_7->setStyleSheet(QStringLiteral("font: 75 15pt \"MS Sans Serif\";"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(680, 0, 80, 21));
        MainWindow->setCentralWidget(centralwidget);
        groupBox_2->raise();
        groupBox->raise();
        label_7->raise();
        pushButton_4->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Edit Menu", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Add Vertex", nullptr));
        VertexNameBox->setPlaceholderText(QApplication::translate("MainWindow", "Enter Vertex Symbol", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Name</span></p></body></html>", nullptr));
        SourceNameBox->setPlaceholderText(QApplication::translate("MainWindow", "Enter Source", nullptr));
        DestinationNameBox->setPlaceholderText(QApplication::translate("MainWindow", "Enter Destination", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Source</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Destination</span></p></body></html>", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add Edge", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Departure and Arrival", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Departure</span></p></body></html>", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Depart", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Source</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Destination</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">YOLO</span></p></body></html>", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Increase Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
