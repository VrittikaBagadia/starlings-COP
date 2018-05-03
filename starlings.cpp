#include<iostream>
#include <vector>
#include<math.h>
#include<cstdlib>
using namespace std;

struct ret_type
{
	double x, y, z;	
};
ret_type vector_add (ret_type t1 , ret_type t2)
{
	ret_type t;
	t.x = t1.x + t2.x;
	t.y = t1.y + t2.y;
	t.z = t1.z + t2.z;
	return t;
}
ret_type vector_subtract (ret_type t1 , ret_type t2)
{
	ret_type t;
	t.x = t1.x - t2.x;
	t.y = t1.y - t2.y;
	t.z = t1.z - t2.z;
	return t;
}
ret_type vector_divide (ret_type t1 , double n)
{
	ret_type t;
	t.x = t1.x/n;
	t.y = t1.y/n;
	t.z = t1.z/n;
	return t;
}
ret_type vector_multiply (ret_type t1 , double n)
{
	ret_type t;
	t.x = t1.x*n;
	t.y = t1.y*n;
	t.z = t1.z*n;
	return t;
}

class boid
{
public:
	ret_type position;
	ret_type velocity;
	boid(ret_type p, ret_type v)
	{
		position = p;
		velocity = v;
	}
};


std::vector<boid> all, allmod;
int size;
float neigh_param;
float repel;

float dist(int n1, int n2)
{
	ret_type p1 = all[n1].position;
	ret_type p2 = all[n2].position; 
	float ans = pow((pow((p1.x-p2.x),2.0) + pow((p1.y-p2.y),2.0) + pow((p1.z-p2.z),2)),(0.5));
	return ans;
}
vector<int> calc_neighbour(int n)
{
	//cout<<"enterss calc neighbour \n";
	std::vector<int> neighbour;
	for (int i = 0; i < size; ++i)
	{
		if (i!=n)
			if(dist(i,n)<neigh_param)
				neighbour.push_back(i);
	}
	return neighbour;
}
ret_type rule1COM(int n ,vector<int> neighbours)
{
	//cout<<"enterss rule1 \n";
	ret_type c;
	c.x=0;c.y=0;c.z=0;
	int no = neighbours.size();
	for(int i=0; i<no; i++)
		if (n!=neighbours[i])
			c = vector_add(c,all.at(neighbours[i]).position);
	c = vector_divide(c,(no-1));		
	c = vector_subtract(c,all[n].position);
	c = vector_divide(c,100);
	return c;
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
					r = vector_add(r,all[n].position);
					r = vector_subtract(r,all[in].position);
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
					r = vector_add(r,all[in].velocity);
		}
		//cout<<"hi\n";
		r = vector_divide(r,(no-1));
		r = vector_subtract(r, all[n].velocity);
		r = vector_divide(r,8);
		//cout<<"leaves \n";
	return r;
}

void limit_velocity (float vlim, boid b)
{
	float speed = pow((pow((b.velocity.x),2.0) + pow((b.velocity.y),2.0) + pow((b.velocity.z),2)),(0.5));
	double factor = vlim / speed;
	if (speed > vlim)
		b.velocity = vector_multiply(b.velocity,factor);
}

void recompute()
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
		ret_type vv;
		vv = vector_add(rule1,rule2);
		vv = vector_add(vv,rule3);
		allmod[i].velocity = vector_add(all[i].velocity,vv);
		limit_velocity(0.5,allmod[i]);
		allmod[i].position = vector_add(all[i].position,allmod[i].velocity);		
	}
	//cout<<"end of recompute \n ";
	all=allmod;
}

int main()
{
	size = 10;
	neigh_param = 1;
	repel = 0.1;
	srand(time(NULL));
	//vector<boid> birds;
	for (int i=0; i<size; i++)
	{
		ret_type t1,t2;
		t1.x = (std::rand()/1638300000.0);
		t2.x = (std::rand()/1638300000.0);
		t1.y = (std::rand()/1638300000.0);
		t2.y = (std::rand()/1638300000.0);
		t1.z = (std::rand()/1638300000.0);
		t2.z = (std::rand()/1638300000.0);
		boid b1(t1,t2);
		all.push_back(b1);
	}
	for (int i=0; i<size; i++)
	{
		ret_type t1,t2;
		t1.x=0;t2.x=0;t1.y=0;t2.y=0;t1.z=0;t2.z=0;
		boid b(t1,t2);
		allmod.push_back(b);
	}
	for(int i=0; i<size; i++)
		cout<<all[i].position.x<<" "<<all[i].position.y<<" "<<all[i].position.z<<'\n';
	recompute();
	cout<<endl;
	for(int i=0; i<size; i++)
		cout<<all[i].position.x<<" "<<all[i].position.y<<" "<<all[i].position.z<<'\n';
	cout<<endl;
	for(int i=0; i<size; i++)
		cout<<all[i].velocity.x<<" "<<all[i].velocity.y<<" "<<all[i].velocity.z<<'\n';
	return 0;
}

