#include <QApplication>
#include<iostream>
#include <QDesktopWidget>
#include<vector>
#include <QFileDialog>
#include<main_choice.h>
#include<fstream>
#include <math.h>
#include <QtGui>
#include<map>
#include <qlabel.h>
//#include "classes.h"
#include "threeto2main.h"
#include "window.h"
#include<cstdlib>
#include<boid.h>
using namespace std;

struct ret_type
{
    float x, y, z;
};

std::vector<boid> all, allmod;
int size;
float neigh_param;
float repel;
float dist(int n1, int n2)
{
    boid b1 (all[n1].px,all[n1].py,all[n1].pz,all[n1].vx,all[n1].vy,all[n1].vz);
    boid b2 (all[n2].px,all[n2].py,all[n2].pz,all[n2].vx,all[n2].vy,all[n2].vz);
    float ans = pow((pow((b1.px-b2.px),2.0) + pow((b1.py-b2.py),2.0) + pow((b1.pz-b2.pz),2)),(0.5));
    return ans;
}


vector<int> calc_neighbour(int n)
{
    //cout<<"enterss calc neighbour \n";
    std::vector<int> neighbour;
    for (int i = 0; i < size; ++i)
    {
        if (i!=n)
        {
            if(dist(i,n)<neigh_param)
                neighbour.push_back(i);
        }
    }
    return neighbour;
}
ret_type rule1COM(int n ,vector<int> neighbours)
{
    //cout<<"enterss rule1 \n";
    double cx=0,cy=0,cz=0;
    int no = neighbours.size();
    for(int i=0; i<no; i++)
        if (n!=neighbours[i])
        {
            cx+=all.at(neighbours[i]).px;
            cy+=all.at(neighbours[i]).py;
            cz+=all.at(neighbours[i]).pz;
        }

        cx = cx/(no-1);
        cy = cy/(no-1);
        cz = cz/(no-1);
    ret_type r;			/// SEE SYNTAX
    r.x = (cx - all[n].px)/80;
    r.y = (cy - all[n].py)/80;
    r.z = (cz - all[n].pz)/80;
    return r;
}

ret_type rule2a(int n ,vector<int> neighbours)
{
    //cout<<"enterss rule2 \n";
    ret_type r;
    r.x=0;r.y=0;r.z=0;
    for(int i=0; i<neighbours.size(); i++)
        {	int in = neighbours[i];
            if (n!=in)
                if (dist(n,in)<repel)	// float repel - global
                {
                    r.x = r.x + all[n].px - all[in].px;
                    r.y = r.y + all[n].py - all[in].py;
                    r.z = r.z + all[n].pz - all[in].pz;
                }
        }
    return r;

}

ret_type rule3a(int n ,vector<int> neighbours)
{
    //cout<<"enterss rule3 \n";
    ret_type r;
    r.x=0;r.y=0;r.z=0;
    int no = neighbours.size();
    for(int i=0; i<no; i++)
        {	int in = neighbours[i];
            if (n!=in)
                if (dist(n,in)<repel)	// float repel - global
                {
                    r.x = r.x + all[in].vx;
                    r.y = r.y + all[in].vy;
                    r.z = r.z + all[in].vz;
                }
        }
        //cout<<"hi\n";
        r.x=r.x/(no-1);
        r.y=r.y/(no-1);
        r.z=r.z/(no-1);

        r.x=(r.x-all[n].vx)/8;
        r.y=(r.y-all[n].vy)/8;
        r.z=(r.z-all[n].vz)/8;
        //cout<<"leaves \n";
    return r;
}

std::vector<boid> recompute()
{
    ret_type rule1, rule2, rule3;
    vector<int> neighbour;
    for (int i = 0; i < size; ++i)
    {
        //cout<<"enterss recompute \n";
        neighbour= calc_neighbour(i);
        rule1= rule1COM(i, neighbour);
        rule2= rule2a(i, neighbour);
        rule3= rule3a(i, neighbour);
        allmod[i].vx=all[i].vx+rule1.x+rule2.x+rule3.x;
        allmod[i].vy=all[i].vy+rule1.y+rule2.y+rule3.y;
        allmod[i].vz=all[i].vz+rule1.z+rule2.z+rule3.z;
        allmod[i].px=all[i].px+allmod[i].vx;
        allmod[i].py=all[i].py+allmod[i].vy;
        allmod[i].pz=all[i].pz+allmod[i].vz;

    }
    //cout<<"end of recompute \n ";
    all=allmod;
    return all;
}

QString s="";
using namespace std;

int op=1;

QString fn;
bool dr=true;
char *filename="input2.txt";
using namespace Qt;
using namespace std;
//using namespace arma;

int height = 800;
int width = 800;
int main(int argc, char *argv[])
{


    QApplication app(argc, argv);


               :: Window window;


    size = 100;
    neigh_param = 0.3;
    repel = 0.03;
    srand(time(NULL));
    //vector<boid> birds;
    for (int i=0; i<size; i++)
    {
        boid b1((std::rand()/16383000000.0),(std::rand()/16383000000.0),(std::rand()/16383000000.0),(std::rand()/16383000000.0),(std::rand()/16383000000.0),(std::rand()/16383000000.0));
        all.push_back(b1);
    }
    for (int i=0; i<size; i++)
    {
        boid b(0,0,0,0,0,0);
        allmod.push_back(b);
    }
//    for(int i=0; i<size; i++)
//        cout<<all[i].px<<" "<<all[i].py<<" "<<all[i].pz<<'\n';
    //all=recompute();
    //cout<<endl;
//	for(int i=0; i<size; i++)
//		cout<<all[i].px<<" "<<all[i].py<<" "<<all[i].pz<<'\n';


    window.resize(window.sizeHint());
    int desktopArea = QApplication::desktop()->width() *
                     QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();

    window.setWindowTitle("OpenGL with Qt");

    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();

    //updateGL();
    app.exec();

}

