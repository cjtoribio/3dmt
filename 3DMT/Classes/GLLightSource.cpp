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
    setPosition4(GLVEC4_ZERO);
}

GLLightSource::~GLLightSource()
{
    
}

void GLLightSource::draw()
{
    
}

void GLLightSource::indicate()
{
    GLVec4 lightPos(getPosition4());
    
    if(isShown())
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        
        glMaterialfv(GL_FRONT, GL_AMBIENT, getAmbient().getPosVec());
        glMaterialfv(GL_FRONT, GL_DIFFUSE, getDifuse().getPosVec());
        
        glMaterialfv(GL_FRONT, GL_SPECULAR, getSpecular().getPosVec());
        glMaterialfv(GL_FRONT, GL_AMBIENT, getDull());
        
        glPushMatrix();
            glLightfv(GL_LIGHT0, GL_POSITION, lightPos.getPosVec());
        glPopMatrix();
    }
    else
        glDisable(GL_LIGHT0);
}
