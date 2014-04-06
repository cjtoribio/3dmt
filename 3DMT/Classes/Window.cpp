//
//  Window.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Window.h"
#include "controls/Keyboard.h"
#include "controls/Mouse.h"

Window::Window()
{
    setName(WINDOW_TITLE);
    setWidth(WINDOW_WIDTH);
    setHeight(WINDOW_HEIGHT);
    setX(50);
    setY(50);
    setAlpha(1.0);
    setColor(BLACK);
}


Window::Window(int width, int height, int x, int y, string name)
{
    setName(name);
    setWidth(width);
    setHeight(height);
    setX(x);
    setY(y);
    setAlpha(1.0);
}

Window::~Window()
{
    
}

void Window::init(int argc, char **argv)
{
	instance = this;
    
    // Initializing opengl with system parameters
    
    glutInit(&argc, argv);
    
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(_width, _height);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    
    // Create window
    
    glutCreateWindow(getName().c_str());
    
    // Setup GLUT callbacks functions
    
    glutDisplayFunc(drawCallback);
    glutIdleFunc(drawCallback);
    glutReshapeFunc(reshapeCallback);
    
    // Setup GLUT input callback function
    
    glutKeyboardFunc(Keyboard::setKeyDown);
    glutKeyboardUpFunc(Keyboard::setKeyUp);
    glutSpecialFunc(Keyboard::setSpecialKey);
    glutMouseFunc(Mouse::updateMouse);
    glutMotionFunc(Mouse::updateMousePos);
    glutPassiveMotionFunc(Mouse::updateMousePos);
    
    // Enter main loop
    
    glutMainLoop();
}

void Window::handleEvents()
{
    // Update globals
    // Process mouse
    if( abs(getWidth()/2 - Mouse::getX()) > 10)
		camera.rotateLeft((getWidth()/2 - Mouse::getX()) , MOUSE_SENSITIVITY);
	if( abs(getHeight()/2 - Mouse::getY()) > 10)
		camera.rotateUp(-(getHeight()/2 - Mouse::getY()) , MOUSE_SENSITIVITY);
	
	if(Keyboard::isPressed('a') || Keyboard::isPressed('d'))
	{
		camera.walkLeft(Keyboard::isPressed('a') ? 1 : -1, WALKING_SPEED);
	}
    
	if(Keyboard::isPressed('w') || Keyboard::isPressed('s'))
	{
		camera.walkFront(Keyboard::isPressed('w') ? 1 : -1, WALKING_SPEED);
	}
    
	if(Mouse::isPressed(0) || Mouse::isPressed(2))
	{
		camera.fly((Mouse::isPressed(0) ? 1 : -1) * WALKING_SPEED);
	}
    
	Mouse::snapshot();
}

void Window::drawCallback()
{
    instance->draw();
}

void Window::draw()
{
    handleEvents();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Camera transformations
    
    camera.position();
    
    drawer.draw();
    
    glutSwapBuffers();
}

void Window::reshapeCallback(int width, int height)
{
    instance->reshape(width, height);
}

void Window::reshape(int p_width, int p_height)
{
	_width = p_width;
	_height = p_height;
    
    if(p_height == 0)
        _height = 1;
    
    float ratio = _width/_height;
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    glViewport(0, 0, _width, _height);
    
    gluPerspective(45, ratio, 0.01, 1000);
    
    glMatrixMode(GL_MODELVIEW);
}

Window* Window::instance;