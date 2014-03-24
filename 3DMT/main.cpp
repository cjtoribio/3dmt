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
	if(Mouse::isPressed(0))
	{
		camera.panLeft(-Mouse::getDX(), Constants::getMouseSense());
		camera.panUp(-Mouse::getDY(), Constants::getMouseSense());
	}
	if(Mouse::isPressed(1))
	{
		camera.panOut(-Mouse::getDY(), Constants::getMouseSense());
	}
    
    // Process keys
    if(Keyboard::isPressed('w'))
    {
        // Move foward
        CAMERA_POSITION.setZ(CAMERA_POSITION.getZ() - (Constants::getWalkingSpeed() * Timer::getDelta()) * dcos(CAMERA_ROTATION.getY()));
        CAMERA_POSITION.setX(CAMERA_POSITION.getX() - (Constants::getWalkingSpeed() * Timer::getDelta()) * dsin(CAMERA_ROTATION.getY()));
        
    } 
    if(Keyboard::isPressed('s'))
    {
        // Move backward
        CAMERA_POSITION.setZ(CAMERA_POSITION.getZ() + (Constants::getWalkingSpeed() * Timer::getDelta()) * dcos(CAMERA_ROTATION.getY()));
        CAMERA_POSITION.setX(CAMERA_POSITION.getX() + (Constants::getWalkingSpeed() * Timer::getDelta()) * dsin(CAMERA_ROTATION.getY()));
        
    } 
    if(Keyboard::isPressed('a'))
    {
        // Move left
        CAMERA_POSITION.setX(CAMERA_POSITION.getX() - Constants::getWalkingSpeed() * Timer::getDelta());
        
    } 
    if(Keyboard::isPressed('d'))
    {
        // Move right
        CAMERA_POSITION.setX(CAMERA_POSITION.getX() + Constants::getWalkingSpeed() * Timer::getDelta());
    } 
    if(Keyboard::isPressed(' '))
    {
        // Jump
        CAMERA_POSITION = GLCAMERA_VEC3ZERO;
        CAMERA_ROTATION = GLCAMERA_VEC3ZERO;
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

//    glRotatef(45, 0, 0, 1);
//    glRotatef(45.0, 1.0, 0.0, 0.0);
//    glRotatef(45, 0, 1, 0);
    
    int N = 10;
    
    for(int x=0;x<N;x++)
    {
        for(int y=0;y<N;y++)
        {
            for(int z=0;z<N;z++)
            {
                if(x == 0 && y == 0)
                    glColor3f(1, 0, 0);
                if(x == 0)
                    glColor3f(0, 1, 0);
                glPushMatrix();
                glutSolidSphere(0.4 * x, 1, 1);
                glPopMatrix();
            }
        }
    }

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
