/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *fileLineEdit;
    QHBoxLayout *horizontalLayout;
    QGroupBox *typeGroupBOx;
    QVBoxLayout *verticalLayout;
    QRadioButton *matrixRadioButton;
    QRadioButton *listRadioButton;
    QGroupBox *fileGroupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *txtRadioButton;
    QRadioButton *csvRadioButton;
    QPushButton *loadPushButton;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *cameraGroupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QDoubleSpinBox *cameraXSpin;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QDoubleSpinBox *cameraYSpin;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QDoubleSpinBox *cameraZSpin;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *cameraListWidget;
    QGridLayout *gridLayout;
    QPushButton *cameraAddPushbutton;
    QPushButton *cameraDeletePushbutton;
    QPushButton *cameraSetPushbutton;
    QPushButton *cameraMoveButton;
    QGroupBox *objectGroupBox;
    QVBoxLayout *verticalLayout_11;
    QListWidget *objectListWidget;
    QPushButton *objectDeletePushbutton;
    QPushButton *objectCompositePushbutton;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_5;
    QDoubleSpinBox *obkectMoveXSpin;
    QLabel *label_8;
    QDoubleSpinBox *objectMoveYSpin;
    QLabel *label_12;
    QDoubleSpinBox *objectMoveZSpin;
    QPushButton *objectMovePushbutton;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_6;
    QDoubleSpinBox *objectRotateXSpin;
    QLabel *label_10;
    QDoubleSpinBox *objectRotateYSpin;
    QLabel *label_11;
    QDoubleSpinBox *objectRotateZSpin;
    QPushButton *objectRotatePushbutton;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_7;
    QDoubleSpinBox *objectScaleXSpin;
    QLabel *label_9;
    QDoubleSpinBox *objectScaleYSpin;
    QLabel *label_13;
    QDoubleSpinBox *objectScaleZSpin;
    QPushButton *objectScalePushbutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1008, 884);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_6 = new QHBoxLayout(centralwidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        fileLineEdit = new QLineEdit(frame);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));

        verticalLayout_3->addWidget(fileLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        typeGroupBOx = new QGroupBox(frame);
        typeGroupBOx->setObjectName(QString::fromUtf8("typeGroupBOx"));
        verticalLayout = new QVBoxLayout(typeGroupBOx);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        matrixRadioButton = new QRadioButton(typeGroupBOx);
        matrixRadioButton->setObjectName(QString::fromUtf8("matrixRadioButton"));

        verticalLayout->addWidget(matrixRadioButton);

        listRadioButton = new QRadioButton(typeGroupBOx);
        listRadioButton->setObjectName(QString::fromUtf8("listRadioButton"));
        listRadioButton->setChecked(true);

        verticalLayout->addWidget(listRadioButton);


        horizontalLayout->addWidget(typeGroupBOx);

        fileGroupBox = new QGroupBox(frame);
        fileGroupBox->setObjectName(QString::fromUtf8("fileGroupBox"));
        verticalLayout_2 = new QVBoxLayout(fileGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        txtRadioButton = new QRadioButton(fileGroupBox);
        txtRadioButton->setObjectName(QString::fromUtf8("txtRadioButton"));
        txtRadioButton->setChecked(true);

        verticalLayout_2->addWidget(txtRadioButton);

        csvRadioButton = new QRadioButton(fileGroupBox);
        csvRadioButton->setObjectName(QString::fromUtf8("csvRadioButton"));
        csvRadioButton->setChecked(false);

        verticalLayout_2->addWidget(csvRadioButton);


        horizontalLayout->addWidget(fileGroupBox);


        verticalLayout_3->addLayout(horizontalLayout);

        loadPushButton = new QPushButton(frame);
        loadPushButton->setObjectName(QString::fromUtf8("loadPushButton"));

        verticalLayout_3->addWidget(loadPushButton);


        horizontalLayout_5->addWidget(frame);


        verticalLayout_14->addLayout(horizontalLayout_5);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_14->addWidget(graphicsView);


        horizontalLayout_6->addLayout(verticalLayout_14);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        cameraGroupBox = new QGroupBox(centralwidget);
        cameraGroupBox->setObjectName(QString::fromUtf8("cameraGroupBox"));
        verticalLayout_7 = new QVBoxLayout(cameraGroupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(cameraGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        cameraXSpin = new QDoubleSpinBox(cameraGroupBox);
        cameraXSpin->setObjectName(QString::fromUtf8("cameraXSpin"));

        verticalLayout_4->addWidget(cameraXSpin);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(cameraGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        cameraYSpin = new QDoubleSpinBox(cameraGroupBox);
        cameraYSpin->setObjectName(QString::fromUtf8("cameraYSpin"));

        verticalLayout_5->addWidget(cameraYSpin);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(cameraGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_6->addWidget(label_4);

        cameraZSpin = new QDoubleSpinBox(cameraGroupBox);
        cameraZSpin->setObjectName(QString::fromUtf8("cameraZSpin"));

        verticalLayout_6->addWidget(cameraZSpin);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cameraListWidget = new QListWidget(cameraGroupBox);
        cameraListWidget->setObjectName(QString::fromUtf8("cameraListWidget"));

        horizontalLayout_3->addWidget(cameraListWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cameraAddPushbutton = new QPushButton(cameraGroupBox);
        cameraAddPushbutton->setObjectName(QString::fromUtf8("cameraAddPushbutton"));

        gridLayout->addWidget(cameraAddPushbutton, 1, 1, 1, 1);

        cameraDeletePushbutton = new QPushButton(cameraGroupBox);
        cameraDeletePushbutton->setObjectName(QString::fromUtf8("cameraDeletePushbutton"));

        gridLayout->addWidget(cameraDeletePushbutton, 0, 0, 1, 1);

        cameraSetPushbutton = new QPushButton(cameraGroupBox);
        cameraSetPushbutton->setObjectName(QString::fromUtf8("cameraSetPushbutton"));

        gridLayout->addWidget(cameraSetPushbutton, 1, 0, 1, 1);

        cameraMoveButton = new QPushButton(cameraGroupBox);
        cameraMoveButton->setObjectName(QString::fromUtf8("cameraMoveButton"));

        gridLayout->addWidget(cameraMoveButton, 0, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout_7->addLayout(horizontalLayout_3);


        verticalLayout_13->addWidget(cameraGroupBox);

        objectGroupBox = new QGroupBox(centralwidget);
        objectGroupBox->setObjectName(QString::fromUtf8("objectGroupBox"));
        verticalLayout_11 = new QVBoxLayout(objectGroupBox);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        objectListWidget = new QListWidget(objectGroupBox);
        objectListWidget->setObjectName(QString::fromUtf8("objectListWidget"));
        objectListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_11->addWidget(objectListWidget);

        objectDeletePushbutton = new QPushButton(objectGroupBox);
        objectDeletePushbutton->setObjectName(QString::fromUtf8("objectDeletePushbutton"));

        verticalLayout_11->addWidget(objectDeletePushbutton);

        objectCompositePushbutton = new QPushButton(objectGroupBox);
        objectCompositePushbutton->setObjectName(QString::fromUtf8("objectCompositePushbutton"));

        verticalLayout_11->addWidget(objectCompositePushbutton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_5 = new QLabel(objectGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_8->addWidget(label_5);

        obkectMoveXSpin = new QDoubleSpinBox(objectGroupBox);
        obkectMoveXSpin->setObjectName(QString::fromUtf8("obkectMoveXSpin"));
        obkectMoveXSpin->setMinimum(-500.000000000000000);
        obkectMoveXSpin->setMaximum(500.000000000000000);
        obkectMoveXSpin->setValue(10.000000000000000);

        verticalLayout_8->addWidget(obkectMoveXSpin);

        label_8 = new QLabel(objectGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_8->addWidget(label_8);

        objectMoveYSpin = new QDoubleSpinBox(objectGroupBox);
        objectMoveYSpin->setObjectName(QString::fromUtf8("objectMoveYSpin"));
        objectMoveYSpin->setMinimum(-500.000000000000000);
        objectMoveYSpin->setMaximum(500.000000000000000);
        objectMoveYSpin->setValue(10.000000000000000);

        verticalLayout_8->addWidget(objectMoveYSpin);

        label_12 = new QLabel(objectGroupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_8->addWidget(label_12);

        objectMoveZSpin = new QDoubleSpinBox(objectGroupBox);
        objectMoveZSpin->setObjectName(QString::fromUtf8("objectMoveZSpin"));
        objectMoveZSpin->setMinimum(-500.000000000000000);
        objectMoveZSpin->setMaximum(500.000000000000000);
        objectMoveZSpin->setValue(10.000000000000000);

        verticalLayout_8->addWidget(objectMoveZSpin);

        objectMovePushbutton = new QPushButton(objectGroupBox);
        objectMovePushbutton->setObjectName(QString::fromUtf8("objectMovePushbutton"));

        verticalLayout_8->addWidget(objectMovePushbutton);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_6 = new QLabel(objectGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_9->addWidget(label_6);

        objectRotateXSpin = new QDoubleSpinBox(objectGroupBox);
        objectRotateXSpin->setObjectName(QString::fromUtf8("objectRotateXSpin"));
        objectRotateXSpin->setMinimum(-360.000000000000000);
        objectRotateXSpin->setMaximum(360.000000000000000);
        objectRotateXSpin->setValue(10.000000000000000);

        verticalLayout_9->addWidget(objectRotateXSpin);

        label_10 = new QLabel(objectGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_9->addWidget(label_10);

        objectRotateYSpin = new QDoubleSpinBox(objectGroupBox);
        objectRotateYSpin->setObjectName(QString::fromUtf8("objectRotateYSpin"));
        objectRotateYSpin->setMinimum(-360.000000000000000);
        objectRotateYSpin->setMaximum(360.000000000000000);
        objectRotateYSpin->setValue(10.000000000000000);

        verticalLayout_9->addWidget(objectRotateYSpin);

        label_11 = new QLabel(objectGroupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_9->addWidget(label_11);

        objectRotateZSpin = new QDoubleSpinBox(objectGroupBox);
        objectRotateZSpin->setObjectName(QString::fromUtf8("objectRotateZSpin"));
        objectRotateZSpin->setMinimum(-360.000000000000000);
        objectRotateZSpin->setMaximum(360.000000000000000);
        objectRotateZSpin->setValue(10.000000000000000);

        verticalLayout_9->addWidget(objectRotateZSpin);

        objectRotatePushbutton = new QPushButton(objectGroupBox);
        objectRotatePushbutton->setObjectName(QString::fromUtf8("objectRotatePushbutton"));

        verticalLayout_9->addWidget(objectRotatePushbutton);


        horizontalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_7 = new QLabel(objectGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_10->addWidget(label_7);

        objectScaleXSpin = new QDoubleSpinBox(objectGroupBox);
        objectScaleXSpin->setObjectName(QString::fromUtf8("objectScaleXSpin"));
        objectScaleXSpin->setMinimum(-100.000000000000000);
        objectScaleXSpin->setMaximum(100.000000000000000);
        objectScaleXSpin->setValue(1.500000000000000);

        verticalLayout_10->addWidget(objectScaleXSpin);

        label_9 = new QLabel(objectGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_10->addWidget(label_9);

        objectScaleYSpin = new QDoubleSpinBox(objectGroupBox);
        objectScaleYSpin->setObjectName(QString::fromUtf8("objectScaleYSpin"));
        objectScaleYSpin->setMinimum(-100.000000000000000);
        objectScaleYSpin->setMaximum(100.000000000000000);
        objectScaleYSpin->setValue(1.500000000000000);

        verticalLayout_10->addWidget(objectScaleYSpin);

        label_13 = new QLabel(objectGroupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_10->addWidget(label_13);

        objectScaleZSpin = new QDoubleSpinBox(objectGroupBox);
        objectScaleZSpin->setObjectName(QString::fromUtf8("objectScaleZSpin"));
        objectScaleZSpin->setMinimum(-100.000000000000000);
        objectScaleZSpin->setMaximum(100.000000000000000);
        objectScaleZSpin->setValue(1.500000000000000);

        verticalLayout_10->addWidget(objectScaleZSpin);

        objectScalePushbutton = new QPushButton(objectGroupBox);
        objectScalePushbutton->setObjectName(QString::fromUtf8("objectScalePushbutton"));

        verticalLayout_10->addWidget(objectScalePushbutton);


        horizontalLayout_4->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_4);


        verticalLayout_13->addWidget(objectGroupBox);


        horizontalLayout_6->addLayout(verticalLayout_13);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1008, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", nullptr));
        fileLineEdit->setText(QCoreApplication::translate("MainWindow", "./data/cube.txt", nullptr));
        typeGroupBOx->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        matrixRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260", nullptr));
        listRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272", nullptr));
        fileGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264 \320\244\320\260\320\271\320\273\320\260", nullptr));
        txtRadioButton->setText(QCoreApplication::translate("MainWindow", "Txt", nullptr));
        csvRadioButton->setText(QCoreApplication::translate("MainWindow", "Csv", nullptr));
        loadPushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        cameraGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        cameraAddPushbutton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cameraDeletePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        cameraSetPushbutton->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        cameraMoveButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        objectGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        objectDeletePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265", nullptr));
        objectCompositePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\262 \320\272\320\276\320\274\320\277\320\276\320\267\320\270\321\202", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        objectMovePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ox", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Oy", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Oz", nullptr));
        objectRotatePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Kx", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Ky", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Kz", nullptr));
        objectScalePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INTERFACE_H
