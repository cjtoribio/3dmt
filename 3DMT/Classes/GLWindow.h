//
//  GLWindow.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLWindow__
#define __OpenGL__GLWindow__

#include "GLObject.h"

class GLWindow : public GLObject
{
public:
    
    GLWindow();
    ~GLWindow();
    
    SYNTHESIZE(int, _width, Width);
    SYNTHESIZE(int, _height, Height);
    SYNTHESIZE(int, _x, X);
    SYNTHESIZE(int, _y, Y);
    SYNTHESIZE(GLfloat, _alpha, Alpha);
    
    GLWindow(int width, int height, int x, int y, string name);
    GLWindow(string name);
    
    virtual void draw();
    
    void clear();
    void setSize(int width, int height);
};

#endif /* defined(__OpenGL__GLWindow__) */
