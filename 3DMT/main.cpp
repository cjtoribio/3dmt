//
//  main.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Classes/GLFramework.h"
#include "Classes/v2/Constants.cpp"
#include "Classes/v2/Timer.cpp"
#include "Classes/v2/Mouse.cpp"
#include "Classes/v2/Keyboard.cpp"
#include "Classes/v2/Point.cpp"
#include "Classes/v2/SignalFilter.cpp"
//#include "Classes/v2/Camera.cpp"
#include "Classes/v2/CameraPencil.cpp"
#include <vector>


bool KEYS[256];

Camera camera;
CameraPencil pencil;

vector<GLVec3> points;
vector<GLColor> colors;

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
	if(Mouse::isPressed(0) && !Keyboard::isPressed('p'))
	{
		camera.rotateLeft(Mouse::getDX(), Constants::getMouseSense());
		camera.rotateUp(-Mouse::getDY(), Constants::getMouseSense());
	}
	else if(Mouse::isPressed(0))
	{
		pencil.moveLeft(camera , -Mouse::getDX() * Constants::getMouseSense());
		pencil.moveUp(camera , Mouse::getDY() * Constants::getMouseSense());
	}
	if(Keyboard::isPressed('a') || Keyboard::isPressed('d'))
	{
		camera.walkLeft(Keyboard::isPressed('a') ? 1 : -1, Constants::getWalkingSpeed());
	}
	if(Keyboard::isPressed('w') || Keyboard::isPressed('s'))
	{
		camera.walkFront(Keyboard::isPressed('w') ? 1 : -1, Constants::getWalkingSpeed());
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
	for(int i = SZ/10; i < SZ; ++i)
		VEC[i] = 0;
//	VEC[0] = 0;
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
					if(x == 0)glColor3f(0.0, 0.0, 0.0); // RED
					if(y == 0)glColor3f(0.0, 1.0, 0.0); // GREEN
                    if(z == 0)glColor3f(0.0, 0.0, 1.0); // BLUE
					
					glPushMatrix();
					glTranslated(4*x,4*y,4*z);
					glutSolidSphere(0.4,4,4);
					glPopMatrix();
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
		p.draw();
		INT[i] = (VEC[i] + ((i == 0) ? 0 : INT[i-1]));
	}
	for(int i = 0; i < 128; ++i)
	{
		Point p(0,i,INT[i] * 0.1);
		p.setColor(0,0,1);
		p.draw();
	}
	
	drawPlanes();
	
    

//    glRotatef(45, 0, 0, 1);
//    glRotatef(45.0, 1.0, 0.0, 0.0);
//    glRotatef(45, 0, 1, 0);
    
    pencil.draw();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
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
    glutMouseFunc(Mouse::updateMouse);
    glutMotionFunc(Mouse::updateMousePos);
    glutPassiveMotionFunc(Mouse::updateMousePos);
//    glClearColor(0.51, 0.49, 0.49, 1.0f);
    // Enter main loop
    glutMainLoop();
}
// 108.59.85.251
int main(int argc, char** argv)
{
    rapidjson::Document doc;
    
    GLFileReader::getDocumentFromFile(&doc, PYRAMID_FILE_VIC);
    
    for (Value::ConstMemberIterator it=doc.MemberBegin(); it != doc.MemberEnd(); it++)
    {
        string s = it->name.GetString();
        rapidjson::Value &val = doc[s.c_str()];
        
        float x = val["x"].GetDouble();
        float y = val["y"].GetDouble();
        float z = val["z"].GetDouble();
        
        points.push_back(glv3(x, y, z));
    }
    
    for (int i=0; i<4; i++)
    {
        colors.push_back(RED);
        colors.push_back(GREEN);
        colors.push_back(BLUE);
    }
    
    init(argc, argv);
    
    return 0;
}
