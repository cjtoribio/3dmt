//
//  GLLightSource.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLLightSource__
#define __OpenGL__GLLightSource__

#include "../utils/primitives/GLObject.h"

class GLLightSource: public GLObject
{
public:
    
    PROPERTY(vec4, _ambient, Ambient);
    PROPERTY(vec4, _difuse, Difuse);
    PROPERTY(vec4, _specular, Specular);
    PROPERTY(vec4, _position4, Position4);
    PROPERTY(GLfloat*, _dull, Dull);
    SYNTHESIZE_BOOLEAN(bool, _show, Shown);
    
    GLLightSource();
    ~GLLightSource();
    
    virtual void draw();
    
    void indicate();
};

#endif /* defined(__OpenGL__GLLightSource__) */
