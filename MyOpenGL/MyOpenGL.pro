QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyOpenGL
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    myglwidget.cpp

HEADERS  += window.h \
    myglwidget.h \
    ../build-MyOpenGL-Desktop_Qt_5_0_2_GCC_64bit-Debug/ui_window.h \
    ui_window.h \
    boid.h


LIBS          = -L/usr/lib/x86_64-linux-gnu/ -lm  -larmadillo
LIBS += \
    -LC:\Armadillo\lib_win64 \



FORMS    += \
    window.ui

DISTFILES += \
    MyOpenGL.pro.user.-1
