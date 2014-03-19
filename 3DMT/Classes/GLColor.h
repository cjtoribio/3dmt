//
//  GLColor.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLColor__
#define __OpenGL__GLColor__

#include "SpecialKeys.h"

class GLColor
{
public:
    
    SYNTHESIZE(GLfloat, _r, R);
    SYNTHESIZE(GLfloat, _g, G);
    SYNTHESIZE(GLfloat, _b, B);
    
    GLColor();
    ~GLColor();
    
    GLColor(GLfloat R, GLfloat G, GLfloat B);
    
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "GLColor.cpp"
#endif

#endif /* defined(__OpenGL__GLColor__) */
