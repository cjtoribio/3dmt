//
//  Camera.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Camera.h"

Camera::Camera()
{
    _PHI = 180;
    _THETA = 85;
    _position = vec3(150, 60, 70);
}

Camera::~Camera()
{
    
}

void Camera::fly(float dz)
{
    _position.z += dz;
}

void Camera::walkLeft(float dx, float speed)
{
    vec3 tV;
    tV.x = -sin(_PHI * M_PI / 180);
    tV.y = cos(_PHI * M_PI / 180);
    tV = tV * (dx * speed / tV.mag());
    _position.x += tV.x;
    _position.y += tV.y;
}

void Camera::walkFront(float dx, float speed)
{
    vec3 tV;
    tV.x = cos(_PHI * M_PI / 180);
    tV.y = sin(_PHI * M_PI / 180);
    tV = tV * (dx * speed / tV.mag());
    _position.x += tV.x;
    _position.y += tV.y;
}

void Camera::rotateLeft(float dx, float speed)
{
    _PHI += dx * speed;
}

void Camera::rotateUp(float dx, float speed)
{
    _THETA += dx * speed;
}

vec3 Camera::getPosition()
{
    _position.x = cos(M_PI / 180 * _PHI) * sin(M_PI / 180 * _THETA);
    _position.y = sin(M_PI / 180 * _PHI) * sin(M_PI / 180 * _THETA);
    _position.z = cos(M_PI / 180 * _THETA);
    
    return _position;
}

vec3 Camera::getPositionXY()
{
    double x = cos(M_PI / 180 * _PHI);
    double y = sin(M_PI / 180 * _PHI);
    
    return vec3(x,y,0);
}

void Camera::position()
{
    glRotatef(_THETA + 180, 1.0, 0.0, 0.0);
    glRotatef(-_PHI + 90, 0, 0, 1);
    glTranslatef(-_position.x , -_position.y , -_position.z);
}

void Camera::draw()
{
    
}