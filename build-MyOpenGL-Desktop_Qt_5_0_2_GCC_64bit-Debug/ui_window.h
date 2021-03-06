/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    MyGLWidget *myGLWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *rotYSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *rotZSlider;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSlider *rotZSlider_2;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(649, 464);
        widget = new QWidget(Window);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 202, 314));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        myGLWidget = new MyGLWidget(widget);
        myGLWidget->setObjectName(QStringLiteral("myGLWidget"));
        myGLWidget->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(myGLWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        rotYSlider = new QSlider(widget);
        rotYSlider->setObjectName(QStringLiteral("rotYSlider"));
        rotYSlider->setMaximum(360);
        rotYSlider->setSingleStep(16);
        rotYSlider->setPageStep(15);
        rotYSlider->setOrientation(Qt::Horizontal);
        rotYSlider->setTickPosition(QSlider::TicksAbove);
        rotYSlider->setTickInterval(15);

        horizontalLayout_3->addWidget(rotYSlider);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        rotZSlider = new QSlider(widget);
        rotZSlider->setObjectName(QStringLiteral("rotZSlider"));
        rotZSlider->setMaximum(360);
        rotZSlider->setSingleStep(16);
        rotZSlider->setPageStep(15);
        rotZSlider->setOrientation(Qt::Horizontal);
        rotZSlider->setTickPosition(QSlider::TicksAbove);
        rotZSlider->setTickInterval(15);

        horizontalLayout_2->addWidget(rotZSlider);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        rotZSlider_2 = new QSlider(widget);
        rotZSlider_2->setObjectName(QStringLiteral("rotZSlider_2"));
        rotZSlider_2->setMaximum(360);
        rotZSlider_2->setSingleStep(16);
        rotZSlider_2->setPageStep(15);
        rotZSlider_2->setOrientation(Qt::Horizontal);
        rotZSlider_2->setTickPosition(QSlider::TicksAbove);
        rotZSlider_2->setTickInterval(15);

        horizontalLayout->addWidget(rotZSlider_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Window);
        QObject::connect(rotZSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setZRotation(int)));
        QObject::connect(rotYSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setYRotation(int)));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", 0));
        label->setText(QApplication::translate("Window", "xRot", 0));
        label_2->setText(QApplication::translate("Window", "yrot", 0));
        label_3->setText(QApplication::translate("Window", "zRot", 0));
        label_4->setText(QApplication::translate("Window", "zRot", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
