//
//  KeyListenner.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__KeyListenner__
#define __OpenGL__KeyListenner__

#include <iostream>

class KeyListenner
{
public:
    
    virtual void explain() = 0;
    
    virtual void setKeys(unsigned char key) = 0;
    virtual void setFunctionKeys(unsigned char key)  = 0;
    virtual void setMouseButton(unsigned char key)  = 0;
    
};

#endif /* defined(__OpenGL__KeyListenner__) */
