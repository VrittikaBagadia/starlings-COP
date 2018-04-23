#ifndef BOID_H
#define BOID_H
#include<vector>
class boid
{
public:
    double px,py,pz;	// position
    double vx,vy,vz;	// velocity
    //void ruleCOM(vector<boid> v);
    boid(double px1, double px2, double px3, double vx1, double vx2, double vx3)
    {
        px=px1;
        py=px2;
        pz=px3;
        vx=vx1;
        vy=vx2;
        vz=vx3;

    }
};
std::vector<boid> recompute();
#endif // BOID_H
