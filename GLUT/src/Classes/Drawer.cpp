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
    planexy.setAxis(PLANEXY);
    planexz.setAxis(PLANEXZ);
    planeyz.setAxis(PLANEYZ);
//    arduino.init();
    
    init();
}

Drawer::~Drawer()
{
    
}

void Drawer::init()
{
	
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

void Drawer::draw()
{
//    arduino.fillDataBuffer();
    drawPlanes();
   // drawPoints();
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
    glColor3f(1.0,1.0,1.0);
    // 160
    vector< vector<double> > VVV;
    
    VVV.push_back(XX);
    VVV.push_back(YY);
    VVV.push_back(ZZ);
    
    float sum = 0;
    bool filtered = false;
    
    for(int K = 0; K < 3; ++K)
	{
        SignalFilter SF(Drawer::process2);
        SignalFilter SF2(Drawer::process2);
        
		vector<float> XXX(VVV[K].begin() + 0 , VVV[K].end());
        
		for(int i = 0; i < XXX.size(); i += 1)
		{
			
			float x = XXX[i];
			x *= 10;
			float t = 1.0 * i / XXX.size() * 160;
            
            if(!filtered)
            {
                Point  P(0,t,x + 80 - 50 *K);
                P.radius = 0.05;
                P.setColor(RED);
                P.draw();
                SF.push(x);
            }
			
			float tt = SF.pop();
            //			if(tt > 0)tt = max(0.0f , tt-2);
            //			if(tt < 0)tt = min(0.0f , tt+2);
			sum += tt;
            
            if(filtered)
            {
                SF2.push(sum);
                Point P2(0,t,SF2.pop()/20 + 80 - 50*K); ;
                P2.radius = 0.1;
                P2.setColor(RED);
                P2.draw();
            }
		}
	}
}
