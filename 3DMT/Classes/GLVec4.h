//
//  GLVec4.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLVec4__
#define __OpenGL__GLVec4__

#include "SpecialKeys.h"

class GLVec4
{
public:
    
    SYNTHESIZE(GLfloat, _x, X);
    SYNTHESIZE(GLfloat, _y, Y);
    SYNTHESIZE(GLfloat, _z, Z);
    SYNTHESIZE(GLfloat, _w, W);
    
    
    GLVec4();
    GLVec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    ~GLVec4();
    
    void traslate(GLVec4 vector);
    void rotate(GLfloat angle, GLVec4 &axis);
    void scale(GLVec4 scale);
    
    GLfloat* getPosVec();
    
};

#endif /* defined(__OpenGL__GLVec4__) */
