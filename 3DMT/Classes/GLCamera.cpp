//
//  GLCamera.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLCamera.h"

GLCamera::GLCamera(): _eye(GLPOINT_ZERO), _target(GLCAMERA_POINTZERO), _up(GLCAMERA_POINTUP)
{
    
}

GLCamera::GLCamera(GLPoint eye, GLPoint target, GLPoint up)
{
    _eye = eye;
    _target = target;
    _up = up;
}

GLCamera::~GLCamera()
{
    
}

void GLCamera::changePosition(GLPoint &newEye)
{
    _eye = newEye;
}

void GLCamera::changeTarget(GLPoint &newTarget)
{
    _target = newTarget;
}

void GLCamera::changeUpDirection(GLPoint &newUp)
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