//
//  main.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include <iostream>

#include <OpenGL/gl.h>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <GLUT/glut.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 980

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1, -1, -3);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, 1, -3);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1, -1, -3);
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
    glutCreateWindow("3D Modeling Tool");
    
    // Setup GLUT callbacks functions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    // Enter main loop
    glutMainLoop();
}

int main(int argc, char** argv)
{
    init(argc, argv);
    
    return 0;
}
