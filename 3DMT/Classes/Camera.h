//
//  Camera.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__Camera__
#define __OpenGL__Camera__

#include "utils/primitives/GLObject.h"

class Camera : public GLObject
{
public:
    
    PROPERTY_WRITEONLY(vec3, _position, Position);
    PROPERTY_READONLY(float, _PHI, PHI);
    PROPERTY_READONLY(float, _THETA, THETA);
    
    
    Camera();
    ~Camera();
    
    virtual void draw();
    
    void position();
    void fly(float dz);
    void walkLeft(float dx, float speed);
    void walkFront(float dx, float speed);
    void rotateLeft(float dx, float speed);
    void rotateUp(float dx, float speed);
    
    vec3 getPointingVector();
    vec3 getPointingVectorXY();
    
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Camera.cpp"
#endif

#endif /* defined(__OpenGL__Camera__) */
