//
//  GLMouse.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLMouse__
#define __OpenGL__GLMouse__

#include "KeyListenner.h"

class GLMouse: public KeyListenner
{
public:
    
    GLMouse();
    ~GLMouse();
    
    virtual void explain();
    
    virtual void setMouseButton(int Button, int state);
    void move(int x, int y);
    
};

#endif /* defined(__OpenGL__GLMouse__) */
