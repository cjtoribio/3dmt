//
//  Drawer.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/2/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Drawer.h"

Drawer::Drawer()
{
    init();
}

Drawer::~Drawer()
{
    
}

void Drawer::init()
{
	cursor = 0;
	
    buff.init();
    
    planexy.setAxis(PLANEXY);
    planexz.setAxis(PLANEXZ);
    planeyz.setAxis(PLANEYZ);
    
    activePoints=vector<vec3>(2048);
    processors = map<char,vector<IProcessor*> >();

	processors['X'].push_back(new WindowAverager());
    processors['X'].push_back(new BiasDiscriminator());
    processors['X'].push_back(new PittySignalCanceller(0.05));
    processors['X'].push_back(new Integrator(10));
	processors['X'].push_back(new WindowAverager());
    processors['X'].push_back(new BiasDiscriminator());
	processors['X'].push_back(new Amplifier(30));
    processors['X'].push_back(new Integrator(10));
//	processors['X'].push_back(new WindowAverager());



	processors['Y'].push_back(new WindowAverager());
    processors['Y'].push_back(new BiasDiscriminator());
    processors['Y'].push_back(new PittySignalCanceller(0.05));
    processors['Y'].push_back(new Integrator(10));
	processors['Y'].push_back(new WindowAverager());
    processors['Y'].push_back(new BiasDiscriminator());
	processors['Y'].push_back(new Amplifier(30));
    processors['Y'].push_back(new Integrator(10));
//	processors['Y'].push_back(new WindowAverager());
//    processors['Y'].push_back(new Integrator(5));

//	processors['Z'].push_back(new WindowAverager());
//    processors['Z'].push_back(new BiasDiscriminator());
//    processors['Z'].push_back(new Integrator(10));
//    processors['Z'].push_back(new BiasDiscriminator());
//	processors['Z'].push_back(new WindowAverager());
    processors['Z'].push_back(new Amplifier(0));
	
	drawing = Drawing();
}

void Drawer::process1(SignalFilter::CD *VEC, int SZ)
{
	for(int i = 0; i < SZ; ++i)
		VEC[i].real(VEC[i].real() * (SZ - i) * (SZ - i) / (SZ*SZ)),
		VEC[i].imag(VEC[i].imag() * (SZ - i) * (SZ - i) / (SZ*SZ));
}
void Drawer::process2(SignalFilter::CD *VEC, int SZ)
{
	for(int i = 20; i < SZ; ++i)
		VEC[i] = 0;
//	VEC[0] = 0;
}
void Drawer::process3(SignalFilter::CD *VEC, int SZ)
{
	VEC[0] = 0;
}
void Drawer::process4(SignalFilter::CD *VEC, int SZ)
{
	for(int i = 4; i < SZ; ++i)
		VEC[i] = 0;
}

void Drawer::collectPoints()
{
    vector<vec3> readingPoints;

    buff.getFromArduino();
    while(!buff.isEmpty())
    {
        int x,y,z;
        buff.getNextPoint(x,y,z);
        readingPoints.push_back(vec3(
        		Formulas::toRelativeGravity(x),
        		Formulas::toRelativeGravity(y),
        		Formulas::toRelativeGravity(z)
        ));
    }
    
    for(int j = 0; j < processors['X'].size(); ++j)
    {
        for(int i = 0; i < readingPoints.size(); ++i)
            processors['X'][j]->push(readingPoints[i].x);
        for(int i = 0; i < readingPoints.size(); ++i)
        {
            readingPoints[i].x = processors['X'][j]->pop();
        }
    }
    
    for(int j = 0; j < processors['Y'].size(); ++j)
    {
        for(int i = 0; i < readingPoints.size(); ++i)
            processors['Y'][j]->push(readingPoints[i].y);
        for(int i = 0; i < readingPoints.size(); ++i)
            readingPoints[i].y = processors['Y'][j]->pop();
    }
    
    
    for(int j = 0; j < processors['Z'].size(); ++j)
    {
        for(int i = 0; i < readingPoints.size(); ++i)
            processors['Z'][j]->push(readingPoints[i].z);
        for(int i = 0; i < readingPoints.size(); ++i)
            readingPoints[i].z = processors['Z'][j]->pop();
    }
    
    for(int i = 0; i < readingPoints.size(); ++i)
    {
        activePoints[cursor] = readingPoints[i];
        cursor = (cursor + 1) % activePoints.size();
    }
}

void Drawer::draw()
{
    collectPoints();
    drawPlanes();
    drawCursor();
    drawDrawings();
    drawPoints();
}

void Drawer::drawDrawings()
{
	drawing.draw();
}
void Drawer::drawPlanes()
{
    glColor3f(0,0,0);
    
    glBegin(GL_LINES);
    for(int i=0;i<=PLANE_MAX;i+=10)
    {
        planexy.draw(i);
//        planexz.draw(i);
//        planeyz.draw(i);
    }
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(1, 10, 10);
}


void Drawer::drawCursor()
{
    vec3 p = activePoints[(cursor+activePoints.size() -1)%activePoints.size()];
	Point P(drawing.getMousePosition() + p);
	P.setColor(WHITE);
	P.radius = 1;
	P.draw();
}

void Drawer::pressKey(int key)
{
	if(key == 'z')
	{
		vec3 p = activePoints[(cursor+activePoints.size() -1)%activePoints.size()];
		drawing.setMousePosition(drawing.getMousePosition() + p);
	}
	if(key == 'x')
	{
		drawing.savePoint();
	}
}

void Drawer::drawPoints()
{
    
    //Line CL = Line(Point(0,0,0),Point(100,100,100),RED);
//    CL.setWidth(3);
    for(int i = cursor , j = (cursor + 1) % activePoints.size(); j != cursor; i = (i+1) % activePoints.size() , j = (j+1) % activePoints.size())
    {
        vec3 point1 = activePoints[i];
        vec3 point2 = activePoints[j];
        

        
        float t1 = 1.0 * i / activePoints.size() * 200;
        float t2 = 1.0 * j / activePoints.size() * 200;

       
        
//        Line(point1 + vec3(0,150,60), point2 + vec3(0,150,60),GREEN).draw();
        Line(vec3(t1,point1.x + 60,0) , vec3(t2,point2.x + 60,0), RED).draw();
//        Line(vec3(0,t1,0 + 200) , vec3(0,t2,0 + 200), WHITE).draw();
//        Line(vec3(0,t1,point1.y * 5 + 120) , vec3(0,t2,point2.y * 5 + 120), RED).draw();
//        Line(vec3(0,t1,0 + 120) , vec3(0,t2,0 + 120), WHITE).draw();
//        Line(vec3(0,t1,point1.z * 5 +  40) , vec3(0,t2,point2.z * 5 +  40), RED).draw();
//        Line(vec3(0,t1,0 +  40) , vec3(0,t2,0 +  40), WHITE).draw();


    }
}
