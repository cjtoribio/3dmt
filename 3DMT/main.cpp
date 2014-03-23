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
#include "Classes/v2/Camera.cpp"
#include <vector>

bool KEYS[256];

Camera camera;

GLVec3 CAMERA_POSITION;
GLVec3 CAMERA_ROTATION;

int MOUSE_POSITION[2];
int MOUSE_DELTA_POSITION[2];
int MOUSE_LAST_POSITION[2];

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
	if(Mouse::isPressed(0) && Keyboard::isPressed(' '))
	{
		camera.panLeft(-Mouse::getDX(), Constants::getMouseSense());
		camera.panUp(-Mouse::getDY(), Constants::getMouseSense());
	}
	if(Mouse::isPressed(0) && Keyboard::isPressed('r'))
	{
		camera.rotateLeft(-Mouse::getDX(), Constants::getMouseSense());
		camera.rotateUp(-Mouse::getDY(), Constants::getMouseSense());
	}
	if(Mouse::isPressed(0) && Keyboard::isPressed('z'))
	{
		camera.zoomIn(-Mouse::getDY(), Constants::getMouseSense());
	}

	Mouse::snapshot();
}

void display()
{
    preRenderEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Camera transformations
    glTranslatef(-camera.X , -camera.Y , -camera.Z);

    glRotatef(camera.THETA, 1.0, 0.0, 0.0);
    glRotatef(camera.PHI, 0, 0, 1);
//    glRotatef(45, 0, 1, 0);
    
    glBegin( GL_POLYGON );
    	glColor3f(0.0,0.0,1.0);
    	glVertex3f(-10 , -10, 0);
    	glVertex3f(-10 , 10, 0);
    	glVertex3f(10 , 10, 0);
    	glVertex3f(10 , -10, 0);
	glEnd();
    
//    for (int i=0; i<points.size(); i++)
//    {
//        GLVec3 point = points[i];
//        GLColor color = colors[i];
////        cout << point.getX() << " " << point.getY() << " " << point.getZ() << endl;
//        glColor3f(color.getR(), color.getG(), color.getB());
//        glVertex3f(point.getX(), point.getY(), point.getZ());
//    }

	glColor3f(0.0,1.0,0.0);
    glutSolidSphere(0.3,20,20);

    glTranslatef(0.0,10.0,0.0);
    
	glColor3f(0.0,1.0,0.0);
    glutSolidSphere(0.3,20,20);
    
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
    
    // Enter main loop
    glutMainLoop();
}

int main(int argc, char** argv)
{
    rapidjson::Document doc;
    
    GLFileReader::getDocumentFromFile(&doc, PYRAMID_FILE);
    
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
