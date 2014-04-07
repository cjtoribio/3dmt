//
//  Window.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__Window__
#define __OpenGL__Window__

#include "utils/primitives/GLObject.h"
#include "Drawer.h"
#include "Camera.h"

class Camera;

class Window : public GLObject
{
    PROPERTY_PRIVATE(Camera, camera, Camera);
    
public:
    
    Window();
    ~Window();
    
    PROPERTY_READONLY(Drawer, drawer, Drawer);
    PROPERTY_STATIC(Window*, instance, Window);
    PROPERTY(int, _width, Width);
    PROPERTY(int, _height, Height);
    PROPERTY(int, _x, X);
    PROPERTY(int, _y, Y);
    PROPERTY(float, _alpha, Alpha);
    
    Window(int width, int height, int x, int y, string name);
    
    virtual void draw();
    
    static void drawCallback();
    static void reshapeCallback(int p_width, int p_height);
    
    void handleEvents();
    void init(int argc, char **argv);
    void reshape(int width, int height);
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Window.cpp"
#endif

#endif /* defined(__OpenGL__Window__) */
