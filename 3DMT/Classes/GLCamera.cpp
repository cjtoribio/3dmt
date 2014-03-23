//
//  GLCamera.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLCamera.h"

GLCamera::GLCamera(): _eye(GLVEC3_ZERO), _target(GLCAMERA_VEC3ZERO), _up(GLCAMERA_VEC3UP)
{
    
}

GLCamera::GLCamera(GLVec3 eye, GLVec3 target, GLVec3 up)
{
    _eye = eye;
    _target = target;
    _up = up;
}

GLCamera::~GLCamera()
{
    
}

void GLCamera::changePosition(GLVec3 &newEye)
{
    _eye = newEye;
}

void GLCamera::changeTarget(GLVec3 &newTarget)
{
    _target = newTarget;
}

void GLCamera::changeUpDirection(GLVec3 &newUp)
{
    _up = newUp;
}

void GLCamera::view()
{
    gluLookAt(_eye.getX(), _eye.getY(), _eye.getZ(), _target.getX(), _target.getY(), _target.getZ(), _up.getX(), _up.getY(), _up.getZ());
}

void GLCamera::draw()
{
    
}
