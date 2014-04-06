//
//  Mouse.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Mouse.h"

Mouse::Mouse()
{
    prevX = x = 0;
    prevY = y = 0;
    
    for(int i = 0; i < 5; ++i)
        buttons[i] = true;
}

Mouse::~Mouse()
{
    
}

Mouse& Mouse::getMouse()
{
    static Mouse instance;
    return instance;
}

void Mouse::updateMouse(int button,int state,int x, int y)
{
    getMouse().buttons[button] = state;
    getMouse().x = x;
    getMouse().y = y;
}

void Mouse::updateMousePos(int x, int y)
{
    getMouse().x = x;
    getMouse().y = y;
}

void Mouse::snapshot()
{
    getMouse().prevX = getMouse().x;
    getMouse().prevY = getMouse().y;
}

float Mouse::getX()
{
    return getMouse().x;
}

float Mouse::getDX()
{
    return getMouse().x - getMouse().prevX;
}

float Mouse::getY()
{
    return getMouse().y;
}

float Mouse::getDY()
{
    return getMouse().y - getMouse().prevY;
}

bool Mouse::isPressed(int id)
{
    return !getMouse().buttons[id];
}