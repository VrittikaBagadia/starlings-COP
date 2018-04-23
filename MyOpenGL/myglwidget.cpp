// myglwidget.cpp
#define PI 3.1415926535898
/*  Macro for sin & cos in degrees */
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define DEF_D 1
#include<boid.h>
#include <QtWidgets>
#include <QtOpenGL>
#include<vector>
#include <QtCore/QDebug>
#include "myglwidget.h"
//#include "main5cpp.h"
bool z=false;
using namespace std;
using namespace Qt;


#include <iostream>
#include <cstdio>
#include <ctime>

void vertex(double th2,double ph2, float x1, float y1, float z1)
{
   double x = Sin(th2)*Cos(ph2);
   double y = Cos(th2)*Cos(ph2);
   double z =          Sin(ph2);
   glVertex3d(x/40+x1,y/40+y1,z/40+z1);
}


MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(33);
}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        z=true;
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::startry(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

//    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}


void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    draw();

}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::draw()
{
    allp=recompute();
    int allsize=allp.size();
    for(int i=0; i<allsize;++i){

    for (int ph2=-90;ph2<90;ph2+=DEF_D) {
          glBegin(GL_QUAD_STRIP);
          for (int th2=0;th2<=360;th2+=2*DEF_D) {
        glColor3f(1.0,1.0,1.0); //green
        vertex(th2,ph2,allp[i].px,allp[i].py,allp[i].pz);
        glColor3f(0.0,1.0,1.0); //blue
        vertex(th2,ph2+DEF_D,allp[i].px,allp[i].py,allp[i].pz);
          }
    glEnd();}}
    //while(true)
    if(z==true)
    setXRotation(rand());
    //updateGL();

//    for (int ph2=-90;ph2<90;ph2+=DEF_D) {
//          glBegin(GL_QUAD_STRIP);
//          for (int th2=0;th2<=360;th2+=2*DEF_D) {
//        glColor3f(0.0,1.0,0.0); //green
//        vertex(th2,ph2, 0.5, 0.5, 0.5);
//        glColor3f(0.0,0.0,1.0); //blue
//        vertex(th2,ph2+DEF_D, 0.5, 0.5, 0.5);
//          }
//    glEnd();}

   //s updateGL();

//    qglColor(Qt::white);
//    glLineWidth(5);
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_LINES);
//    vector <Edg3> :: iterator i;
//      // // for printing the input vertices
//      for (i = eset.begin(); i != eset.end(); ++i)
//      {
//          glVertex3f((*i).s.x, (*i).s.y,(*i).s.z);
//          glVertex3f( (*i).e.x,(*i).e.y,(*i).e.z);
//      }



//    glEnd();
}
