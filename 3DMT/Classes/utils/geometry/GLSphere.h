//
//  GLSphere.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLSphere__
#define __OpenGL__GLSphere__

#include "../primitives/GLObject.h"
#include "../SpecialKeys.h"

class GLSphere: public GLObject
{
public:
    
    GLSphere();
    ~GLSphere();
    
    PROPERTY(double, _radius, Radius);
    PROPERTY(int, _slices, Slices);
    PROPERTY(int, _stacks, Stacks);
    
    virtual void draw();
};

#endif /* defined(__OpenGL__GLSphere__) */
