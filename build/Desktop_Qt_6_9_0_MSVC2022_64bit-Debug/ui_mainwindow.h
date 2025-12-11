/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *HBox;
    QVBoxLayout *VBox_red;
    QHBoxLayout *CenterVBox_red;
    QSlider *verticalSlider_red;
    QSpinBox *spinBox_red;
    QVBoxLayout *VBox_green;
    QHBoxLayout *CenterVBox_green;
    QSlider *verticalSlider_green;
    QSpinBox *spinBox_green;
    QVBoxLayout *VBox_blue;
    QHBoxLayout *CenterVBox_blue;
    QSlider *verticalSlider_blue;
    QSpinBox *spinBox_blue;
    QLabel *label_red;
    QLabel *label_green;
    QLabel *label_blue;
    QLabel *label_color;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(320, 370);
        MainWindow->setMinimumSize(QSize(320, 370));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(19, 39, 281, 281));
        HBox = new QHBoxLayout(horizontalLayoutWidget_2);
        HBox->setObjectName("HBox");
        HBox->setContentsMargins(0, 0, 0, 0);
        VBox_red = new QVBoxLayout();
        VBox_red->setObjectName("VBox_red");
        CenterVBox_red = new QHBoxLayout();
        CenterVBox_red->setObjectName("CenterVBox_red");
        verticalSlider_red = new QSlider(horizontalLayoutWidget_2);
        verticalSlider_red->setObjectName("verticalSlider_red");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalSlider_red->sizePolicy().hasHeightForWidth());
        verticalSlider_red->setSizePolicy(sizePolicy);
        verticalSlider_red->setStyleSheet(QString::fromUtf8("QSlider::handle:vertical {\n"
"	background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 red);\n"
"	border: 1px solid #999999;\n"
"	border-radius: 5px;\n"
"}"));
        verticalSlider_red->setMaximum(255);
        verticalSlider_red->setOrientation(Qt::Orientation::Vertical);

        CenterVBox_red->addWidget(verticalSlider_red);


        VBox_red->addLayout(CenterVBox_red);

        spinBox_red = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_red->setObjectName("spinBox_red");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        spinBox_red->setFont(font);
        spinBox_red->setMaximum(255);

        VBox_red->addWidget(spinBox_red);


        HBox->addLayout(VBox_red);

        VBox_green = new QVBoxLayout();
        VBox_green->setObjectName("VBox_green");
        CenterVBox_green = new QHBoxLayout();
        CenterVBox_green->setObjectName("CenterVBox_green");
        verticalSlider_green = new QSlider(horizontalLayoutWidget_2);
        verticalSlider_green->setObjectName("verticalSlider_green");
        sizePolicy.setHeightForWidth(verticalSlider_green->sizePolicy().hasHeightForWidth());
        verticalSlider_green->setSizePolicy(sizePolicy);
        verticalSlider_green->setStyleSheet(QString::fromUtf8("QSlider::handle:vertical {\n"
"	background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 green);\n"
"	border: 1px solid #999999;\n"
"	border-radius: 5px;\n"
"}"));
        verticalSlider_green->setMaximum(255);
        verticalSlider_green->setOrientation(Qt::Orientation::Vertical);

        CenterVBox_green->addWidget(verticalSlider_green);


        VBox_green->addLayout(CenterVBox_green);

        spinBox_green = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_green->setObjectName("spinBox_green");
        spinBox_green->setFont(font);
        spinBox_green->setMaximum(255);

        VBox_green->addWidget(spinBox_green);


        HBox->addLayout(VBox_green);

        VBox_blue = new QVBoxLayout();
        VBox_blue->setObjectName("VBox_blue");
        CenterVBox_blue = new QHBoxLayout();
        CenterVBox_blue->setObjectName("CenterVBox_blue");
        verticalSlider_blue = new QSlider(horizontalLayoutWidget_2);
        verticalSlider_blue->setObjectName("verticalSlider_blue");
        sizePolicy.setHeightForWidth(verticalSlider_blue->sizePolicy().hasHeightForWidth());
        verticalSlider_blue->setSizePolicy(sizePolicy);
        verticalSlider_blue->setStyleSheet(QString::fromUtf8("QSlider::handle:vertical {\n"
"	background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 blue);\n"
"	border: 1px solid #999999;\n"
"	border-radius: 5px;\n"
"}"));
        verticalSlider_blue->setMaximum(255);
        verticalSlider_blue->setOrientation(Qt::Orientation::Vertical);

        CenterVBox_blue->addWidget(verticalSlider_blue);


        VBox_blue->addLayout(CenterVBox_blue);

        spinBox_blue = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_blue->setObjectName("spinBox_blue");
        spinBox_blue->setFont(font);
        spinBox_blue->setMaximum(255);

        VBox_blue->addWidget(spinBox_blue);


        HBox->addLayout(VBox_blue);

        label_red = new QLabel(centralwidget);
        label_red->setObjectName("label_red");
        label_red->setGeometry(QRect(39, 16, 51, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(18);
        font1.setBold(true);
        label_red->setFont(font1);
        label_red->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_green = new QLabel(centralwidget);
        label_green->setObjectName("label_green");
        label_green->setGeometry(QRect(119, 16, 91, 21));
        label_green->setFont(font1);
        label_green->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_blue = new QLabel(centralwidget);
        label_blue->setObjectName("label_blue");
        label_blue->setGeometry(QRect(220, 16, 71, 21));
        label_blue->setFont(font1);
        label_blue->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_color = new QLabel(centralwidget);
        label_color->setObjectName("label_color");
        label_color->setGeometry(QRect(20, 340, 281, 21));
        label_color->setFont(font1);
        label_color->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"}"));
        label_color->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RGB Viewer v1", nullptr));
        label_red->setText(QCoreApplication::translate("MainWindow", "RED", nullptr));
        label_green->setText(QCoreApplication::translate("MainWindow", "GREEN", nullptr));
        label_blue->setText(QCoreApplication::translate("MainWindow", "BLUE", nullptr));
        label_color->setText(QCoreApplication::translate("MainWindow", "COLOR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
