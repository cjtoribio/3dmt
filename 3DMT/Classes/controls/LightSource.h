//
//  GLLightSource.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLLightSource__
#define __OpenGL__GLLightSource__

#include "GLObject.h"

class GLLightSource: public GLObject
{
public:
    
    SYNTHESIZE(GLVec4, _ambient, Ambient);
    SYNTHESIZE(GLVec4, _difuse, Difuse);
    SYNTHESIZE(GLVec4, _specular, Specular);
    SYNTHESIZE(GLVec4, _position4, Position4);
    SYNTHESIZE(GLfloat*, _dull, Dull);
    SYNTHESIZE_BOOLEAN(bool, _show, Shown);
    
    GLLightSource();
    ~GLLightSource();
    
    virtual void draw();
    
    void indicate();
};

#endif /* defined(__OpenGL__GLLightSource__) */
