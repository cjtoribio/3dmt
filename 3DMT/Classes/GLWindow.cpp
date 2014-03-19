//
//  GLWindow.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLWindow.h"

GLWindow::GLWindow()
{
    
}

GLWindow::GLWindow(string name)
{
    setName(name);
    setWidth(600);
    setHeight(400);
    setX(50);
    setY(50);
    setAlpha(1.0);
    setColor(BLACK);
}

GLWindow::GLWindow(int width, int height, int x, int y, string name)
{
    setName(name);
    setWidth(width);
    setHeight(height);
    setX(x);
    setY(y);
    setAlpha(1.0);
}

GLWindow::~GLWindow()
{
    
}

void GLWindow::setSize(int width, int height)
{
    setWidth(width);
    setHeight(height);
}

void GLWindow::draw()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(getWidth(), getHeight());
    glutInitWindowPosition(getX(), getY());
    
    glutCreateWindow(getName().c_str());
    
    clear();
}

void GLWindow::clear()
{
    glClearColor(getColor().getR(), getColor().getG(), getColor().getB(), getAlpha());
    glColor4f(getColor().getR(), getColor().getG(), getColor().getB(), getAlpha());
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
