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
    planexy.setAxis(PLANEXY);
    planexz.setAxis(PLANEXZ);
    planeyz.setAxis(PLANEYZ);
    activePoints=vector<vec3>(256);
    arduino.init();
    processors = map<char,vector<IProcessor*> >();
    
    processors['X'].push_back(new SignalFilter(process2));
    processors['X'].push_back(new Integrator(10));
    //processors['X'].push_back(new SignalFilter(process3));
    //processors['X'].push_back(new Integrator(10));
    
    processors['Y'].push_back(new SignalFilter(process2));
    processors['Y'].push_back(new Integrator(10));
    processors['Y'].push_back(new Integrator(10));
    
    processors['Z'].push_back(new SignalFilter(process2));
    processors['Z'].push_back(new Integrator(10));
    //processors['Z'].push_back(new BiasDiscriminator(-0.05,0.05));
    //processors['X'].push_back(new SignalFilter(process3));
    processors['Z'].push_back(new Integrator(10));
}

void Drawer::process1(SignalFilter::CD *VEC, int SZ)
{
	for(int i = 0; i < SZ; ++i)
		VEC[i].real(VEC[i].real() * (SZ - i) * (SZ - i) / (SZ*SZ)),
		VEC[i].imag(VEC[i].imag() * (SZ - i) * (SZ - i) / (SZ*SZ));
}
void Drawer::process2(SignalFilter::CD *VEC, int SZ)
{
	for(int i = 18; i < SZ; ++i)
		VEC[i] = 0;
	VEC[0] = 0;
}
void Drawer::process3(SignalFilter::CD *VEC, int SZ)
{
	VEC[0] = 0;
}

void Drawer::collectPoints()
{
    vector<vec3> readingPoints(8);
    for(int i = 0; i < readingPoints.size(); ++i)
    {
        readingPoints[i] = arduino.getCoordinates();
    }
    
    
    for(int j = 0; j < processors['X'].size(); ++j)
    {
        for(int i = 0; i < readingPoints.size(); ++i)
            processors['X'][j]->push(readingPoints[i].x);
        for(int i = 0; i < readingPoints.size(); ++i)
            readingPoints[i].x = processors['X'][j]->pop();
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
        cout << readingPoints[0].z << endl;
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
    drawPoints();
}

void Drawer::drawPlanes()
{
    glColor3f(0,0,0);
    
    glBegin(GL_LINES);
    for(int i=0;i<=PLANE_MAX;i+=10)
    {
        planexy.draw(i);
        planexz.draw(i);
        planeyz.draw(i);
    }
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(1, 10, 10);
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
        
        Line(Point(0,t1,point1.x * 5 + 200) , Point(0,t2,point2.x * 5 + 200), RED).draw();
        Line(Point(0,t1,point1.y * 5 + 120) , Point(0,t2,point2.y * 5 + 120), RED).draw();
        Line(Point(0,point1.y * 5 + 40,point1.z * 5 + 40) , Point(0,point2.y * 5 + 40,point2.z * 5 + 40), RED).draw();
    }
}