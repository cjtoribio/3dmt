//
//  GLSphere.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLSphere__
#define __OpenGL__GLSphere__

#include "GLObject.h"

class GLSphere: public GLObject
{
public:
    
    GLSphere();
    ~GLSphere();
    
    SYNTHESIZE(double, _radius, Radius);
    SYNTHESIZE(int, _slices, Slices);
    SYNTHESIZE(int, _stacks, Stacks);
    
    virtual void draw();
};

#endif /* defined(__OpenGL__GLSphere__) */
