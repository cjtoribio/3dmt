//
//  Mouse.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__Mouse__
#define __OpenGL__Mouse__

#include "../utils/SpecialKeys.h"

class Mouse
{
    PROPERTY_PUBLIC(float, x, X);
    PROPERTY_PUBLIC(float, y, Y);
    PROPERTY_PUBLIC(float, prevX, prevX);
    PROPERTY_PUBLIC(float, prevY, prevY);
    PROPERTY_PUBLIC(bool, buttons[5], Buttons);
    
public:
    
    Mouse();
    ~Mouse();
    
    static Mouse& getMouse();
    
    static void snapshot();
    static void updateMousePos(int x, int y);
    static void updateMouse(int button,int state,int x, int y);
    
    static float getX();
    static float getY();
    static float getDX();
    static float getDY();
    
    static bool isPressed(int id);
    
    void operator=(Mouse const&);
    
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Mouse.cpp"
#endif

#endif /* defined(__OpenGL__Mouse__) */
