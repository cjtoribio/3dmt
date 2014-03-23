//
//  GLCamera.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLCamera__
#define __OpenGL__GLCamera__

#include "GLObject.h"

class GLCamera : public GLObject
{
public:
    
    SYNTHESIZE(GLVec3, _eye, Eye);
    SYNTHESIZE(GLVec3, _target, Target);
    SYNTHESIZE(GLVec3, _up, Up);
    
    GLCamera();
    GLCamera(GLVec3 eye, GLVec3 target, GLVec3 up);
    ~GLCamera();
    
    virtual void draw();
    
    void view();
    void changePosition(GLVec3 &newEye);
    void changeTarget(GLVec3 &newTarget);
    
    void changeUpDirection(GLVec3 &newUp);
};

#endif /* defined(__OpenGL__GLCamera__) */
