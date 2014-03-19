//
//  main.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Classes/GLFramework.h"
#include <vector>

bool KEYS[256];

GLVec3 CAMERA_POSITION;
GLVec3 CAMERA_ROTATION;

int MOUSE_POSITION[2];
int MOUSE_DELTA_POSITION[2];
int MOUSE_LAST_POSITION[2];

float WALKING_SPEED = 0.01;
float LAST_TIME;
float CURRENT_TIME;
float DELTA_TIME;
float MOUSE_SENSITIVITY = 1.0;

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

void mouseMove(int x, int y)
{
    MOUSE_POSITION[0] = x;
    MOUSE_POSITION[1] = y;
}

void preRenderEvents()
{
    // Update globals
    CURRENT_TIME = glutGet((float)GLUT_ELAPSED_TIME);
    DELTA_TIME = CURRENT_TIME - LAST_TIME;
    LAST_TIME = CURRENT_TIME;
    
    MOUSE_DELTA_POSITION[0] = MOUSE_POSITION[0] - MOUSE_LAST_POSITION[0];
    MOUSE_DELTA_POSITION[1] = MOUSE_POSITION[1] - MOUSE_LAST_POSITION[1];
    
    MOUSE_LAST_POSITION[0] = MOUSE_POSITION[0];
    MOUSE_LAST_POSITION[1] = MOUSE_POSITION[1];
    
    // Process mouse
    CAMERA_ROTATION.setY(CAMERA_ROTATION.getY() - MOUSE_DELTA_POSITION[0] * MOUSE_SENSITIVITY);
    CAMERA_ROTATION.setZ(CAMERA_ROTATION.getZ() - MOUSE_DELTA_POSITION[1] * MOUSE_SENSITIVITY);
    
    // Process keys
    if(KEYS['w'])
    {
        // Move foward
        CAMERA_POSITION.setZ(CAMERA_POSITION.getZ() - (WALKING_SPEED * DELTA_TIME) * dcos(CAMERA_ROTATION.getY()));
        CAMERA_POSITION.setX(CAMERA_POSITION.getX() - (WALKING_SPEED * DELTA_TIME) * dsin(CAMERA_ROTATION.getY()));
        
    } if (KEYS['s'])
    {
        // Move backward
        CAMERA_POSITION.setZ(CAMERA_POSITION.getZ() + (WALKING_SPEED * DELTA_TIME) * dcos(CAMERA_ROTATION.getY()));
        CAMERA_POSITION.setX(CAMERA_POSITION.getX() + (WALKING_SPEED * DELTA_TIME) * dsin(CAMERA_ROTATION.getY()));
        
    } if (KEYS['a'])
    {
        // Move left
        CAMERA_POSITION.setX(CAMERA_POSITION.getX() - WALKING_SPEED * DELTA_TIME);
        
    } if (KEYS['d'])
    {
        // Move right
        CAMERA_POSITION.setX(CAMERA_POSITION.getX() + WALKING_SPEED * DELTA_TIME);
    } if (KEYS[' '])
    {
        // Jump
        CAMERA_POSITION = GLCAMERA_VEC3ZERO;
        CAMERA_ROTATION = GLCAMERA_VEC3ZERO;
    }
}

void display()
{
    preRenderEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Camera transformations
    glTranslatef(-CAMERA_POSITION.getX(), -CAMERA_POSITION.getY(), -CAMERA_POSITION.getZ());
    glRotatef(CAMERA_ROTATION.getX(), 1, 0, 0);
    glRotatef(CAMERA_ROTATION.getY(), 0, 1, 0);
    glRotatef(CAMERA_ROTATION.getZ(), 0, 0, 1);
    
    glBegin( GL_TRIANGLES );
    
    for (int i=0; i<points.size(); i++)
    {
        GLVec3 point = points[i];
        GLColor color = colors[i];
        cout << point.getX() << " " << point.getY() << " " << point.getZ() << endl;
        glColor3f(color.getR(), color.getG(), color.getB());
        glVertex3f(point.getX(), point.getY(), point.getZ());
    }
    glEnd();
    
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
    glutKeyboardFunc(keyBoardDown);
    glutKeyboardUpFunc(keyBoardUp);
    glutMotionFunc(mouseMove);
    glutPassiveMotionFunc(mouseMove);
    
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
