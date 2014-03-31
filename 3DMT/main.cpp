//
//  main.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


#include "Classes/SpecialKeys.h"
#include "Classes/utils/GLFileReader.h"
#include "Classes/utils/rapidjson/document.h"

#include "./Classes/v2/Controls/Timer.cpp"
#include "./Classes/v2/Controls/Constants.cpp"
#include "./Classes/v2/Controls/Mouse.cpp"
#include "./Classes/v2/Controls/Keyboard.cpp"
#include "./Classes/v2/Controls/Camera.cpp"
#include "./Classes/v2/Controls/CameraPencil.cpp"
#include "./Classes/v2/Controls/SignalFilter.cpp"

#include "./Classes/v2/Geometry/Line.cpp"

#include "Classes/utils/src/SerialStream.h"
#include "Classes/utils/libusb/libusb.h"
#include "Classes/utils/arduino-serial/arduino-serial-lib.h"

#include <iostream>
using namespace std;

bool KEYS[256];

int width , height;
Camera camera;
CameraPencil pencil;
vector<double> XX, YY, ZZ;

void keyBoardDown(unsigned char key, int x, int y)
{
    KEYS[key] = true;
}

void keyBoardUp(unsigned char key, int x, int y)
{
    KEYS[key] = false;
}


void preRenderEvents()
{
    // Update globals
	Timer::update();
	
	
    // Process mouse
	/*
	if( abs(width/2 - Mouse::getX()) > 10)
		camera.rotateLeft((width/2 - Mouse::getX()) , Constants::getMouseSense());
	if( abs(height/2 - Mouse::getY()) > 10)
		camera.rotateUp(-(height/2 - Mouse::getY()) , Constants::getMouseSense());
//	*/
	
	if(Keyboard::isPressed('a') || Keyboard::isPressed('d'))
	{
		camera.walkLeft(Keyboard::isPressed('a') ? 1 : -1, Constants::getWalkingSpeed());
	}
	if(Keyboard::isPressed('w') || Keyboard::isPressed('s'))
	{
		camera.walkFront(Keyboard::isPressed('w') ? 1 : -1, Constants::getWalkingSpeed());
	}
	if(Mouse::isPressed(0) || Mouse::isPressed(2))
	{
		camera.fly( (Mouse::isPressed(0) ? 1 : -1) * Constants::getWalkingSpeed());
	}

	Mouse::snapshot();
}
void process1(SignalFilter::CD *VEC, int SZ)
{
	for(int i = 0; i < SZ; ++i)
		VEC[i].real(VEC[i].real() * (SZ - i) * (SZ - i) / (SZ*SZ)),
		VEC[i].imag(VEC[i].imag() * (SZ - i) * (SZ - i) / (SZ*SZ));
}
void process2(SignalFilter::CD *VEC, int SZ)
{
	for(int i = 18; i < SZ; ++i)
		VEC[i] = 0;
	VEC[0] = 0;
}

void drawBackground()
{
    glMatrixMode (GL_MODELVIEW);
	glPushMatrix ();
    {
        glLoadIdentity ();
        glMatrixMode (GL_PROJECTION);
        glPushMatrix ();
        {
            glLoadIdentity ();
            
            glEnable(GL_LIGHTING);
            glEnable(GL_DEPTH_TEST);
    
            glBegin (GL_QUADS);
                glColor3f(1.0,1.0,0.0);
                glVertex3f(-100.0f,-100.0f, -100.0f);
                glVertex3f( 100.0f,-100.0f, -100.0f);
            
                glColor3f(0.0,1.0,1.0);
                glVertex3f( 100.0f, 100.0f, -100.0f);
                glVertex3f(-100.0f, 100.0f, -100.0f);
            glEnd ();
            
            glDisable(GL_LIGHTING);
            glDisable(GL_DEPTH_TEST);
        }
        glPopMatrix ();
        glMatrixMode (GL_MODELVIEW);
    }
	glPopMatrix ();
}

void drawPlanes()
{
    glColor3f(1.0,1.0,1.0);
	glutSolidSphere(1,10,10);
	for(float x = 0; x <= 40; x += 1)
		for(float y=0; y <= 40; y += 1)
		{
			for(float z=0; z <= 40 ; z += 1)
			{
                //				if(x==0)continue;
				if(abs(x) == 0 || abs(y) == 0 || abs(z) == 0)
				{
					if(x == 0 && y==0 && z == 0)continue;
					if(z == 0)glColor3f(1.0,0.0,0.0); // RED
					if(y == 0)glColor3f(0.0,0.0,1.0); // BLUE
					if(x == 0)glColor3f(0.0,1.0,0.0); // GREEN
					if(x==0)continue;
					if(z==0)continue;
					glPushMatrix();
					glTranslated(4*x,4*y,4*z);
					glutSolidSphere(0.4,4,4);
					glPopMatrix();
				}
			}
		}
}

void drawPoints()
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
        SignalFilter SF(process2);
        SignalFilter SF2(process2);
        
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
                P.setColor(1,0,0);
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
                P2.setColor(1,0,0);
                P2.draw();
            }
		}
	}
}

void display()
{
    preRenderEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Camera transformations
    camera.position();
    
    drawBackground();
	
    drawPoints();
    
	drawPlanes();


//    glRotatef(45, 0, 0, 1);
//    glRotatef(45.0, 1.0, 0.0, 0.0);
//    glRotatef(45, 0, 1, 0);
    
    pencil.draw();
    glutSwapBuffers();
}

void reshape(int p_width, int p_height)
{
	width = p_width;
	height = p_height;
    if(height == 0)
        height = 1;
    
    float ratio = width/height;
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    glViewport(0, 0, width, height);
    
    gluPerspective(45, ratio, 0.01, 1000);
    
    glMatrixMode(GL_MODELVIEW);
}

void init(int argc, char **argv)
{
	
    // Initializing opengl with system parameters
    glutInit(&argc, argv);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    
    // Create window
    glutCreateWindow(WINDOW_TITLE);
    
    // Setup GLUT callbacks functions
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    
    // Setup GLUT input callback function
    glutKeyboardFunc(Keyboard::setKeyDown);
    glutKeyboardUpFunc(Keyboard::setKeyUp);
    glutSpecialFunc(Keyboard::setSpecialKey);
    glutMouseFunc(Mouse::updateMouse);
    glutMotionFunc(Mouse::updateMousePos);
    glutPassiveMotionFunc(Mouse::updateMousePos);
//    glClearColor(0.51, 0.49, 0.49, 1.0f);
    // Enter main loop
    glutMainLoop();
}
// 108.59.85.25

vector<string> print_devs()
{
    vector<string> devices;
    
	libusb_device *dev;
    
    libusb_device **devs;
	int r;
	ssize_t cnt;
    
	r = libusb_init(NULL);
    
	cnt = libusb_get_device_list(NULL, &devs);
    
	int i = 0;
    
	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
		}
        char *s;
        
        sscanf(s,"%d/%d", libusb_get_bus_number(dev), libusb_get_device_address(dev));
        
        string device = s;
        
        cout << device << endl;
        devices.push_back(device);
	}
    return devices;
}

void init_port()
{
    char serialBuffer[BUFFMAX];
    
    int portConf = -1;
    
    vector<string> devs = print_devs();
    
    for (int i=0; i<devs.size(); i++)
    {
        if(portConf != -1)
            break;
        portConf = serialport_init(devs[i].c_str(), B57600);
        cout << "Connecting to arduino" << endl;
    }
    
    memset(serialBuffer, 0, BUFFMAX);
    
    while (true)
    {
        serialport_read_until(portConf, serialBuffer, ENDOFLN, BUFFMAX, TIMEOUT);
        printf("%s\n", serialBuffer);
    }
}

int main(int argc, char** argv)
{
    rapidjson::Document doc;
    
    GLFileReader::getDocumentFromFile(&doc, PYRAMID_FILE_VIC);
    
    // for (Value::ConstMemberIterator it=doc.MemberBegin(); it != doc.MemberEnd(); it++)
    
    freopen(G_FILE_VIC,"r",stdin);
    
    string line;
    
    for(int i = 0; i < 9; ++i)
    	getline(cin , line);
    
    for(int i = 0;  ; ++i)
    {
    	string d;
    	double xx, yy,zz;
    	if(cin >> d >> zz >> d >> xx >> d >> yy)
    	{
    		XX.push_back(xx);
    		YY.push_back(yy);
    		ZZ.push_back(zz);
    	}
    	else
    		break;
    }
    
    init_port();
    
    //init(argc, argv);

    return 0;
}


/*
 vector<double> VEC;
 srand(3958769);
 VEC.push_back(60);
 for(int i = 1; i < 128; ++i)
 {
 VEC.push_back( max(min(VEC.back() + rand() % 20 - 10 , 120.0),0.0) );
 Point(0,i,VEC.back()).draw();
 }
 SignalFilter SF;
 //    for(int i = 0; i < 64; ++i)
 //    	SF.push(50);
 for(int i = 0; i < 128; ++i)
 SF.push(VEC[i]);
 //    for(int i = 0; i < 64; ++i)
 //    	SF.push(VEC.back() );
 VEC = SF.getProcessedSignal(process1);
 for(int i = 0; i < 128; ++i)
 {
 Point p(0,i,VEC[i]);
 p.setColor(1,1,0);
 //    	p.draw();
 }
 VEC = SF.getProcessedSignal(process2);
 vector<double> INT(VEC.size());
 for(int i = 0; i < 128; ++i)
 {
 Point p(0,i,VEC[i]);
 p.setColor(1,0,1);
 //p.draw();
 INT[i] = (VEC[i] + ((i == 0) ? 0 : INT[i-1]));
 }
 for(int i = 0; i < 128; ++i)
 {
 Point p(0,i,INT[i] * 0.1);
 p.setColor(0,0,1);
 //p.draw();
 }
 
 ----------
 
 
 
 */
