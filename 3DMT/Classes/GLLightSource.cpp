//
//  GLLightSource.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLLightSource.h"

GLLightSource::GLLightSource()
{
    setShown(false);
    setPosition4(GLPOINT4_ZERO);
}

GLLightSource::~GLLightSource()
{
    
}

void GLLightSource::draw()
{
    
}

void GLLightSource::indicate()
{
    GLPoint4 lightPos(getPosition4());
    
    if(isShown())
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        
        glMaterialfv(GL_FRONT, GL_AMBIENT, getAmbient().getPosPoint());
        glMaterialfv(GL_FRONT, GL_DIFFUSE, getDifuse().getPosPoint());
        
        glMaterialfv(GL_FRONT, GL_SPECULAR, getSpecular().getPosPoint());
        glMaterialfv(GL_FRONT, GL_AMBIENT, getDull());
        
        glPushMatrix();
            glLightfv(GL_LIGHT0, GL_POSITION, lightPos.getPosPoint());
        glPopMatrix();
    }
    else
        glDisable(GL_LIGHT0);
}
