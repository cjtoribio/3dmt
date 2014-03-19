//
//  GLKeyboard.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLKeyboard__
#define __OpenGL__GLKeyboard__

#include "KeyListenner.h"

class GLKeyboard: public KeyListenner
{
public:
    
    GLKeyboard();
    ~GLKeyboard();
    
    virtual void explain();
    virtual void setFunctionsKeys(unsigned char key);
    virtual void setMouseButton(int Button, int state);
    
    void setViewPoint();
    void setKeys(unsigned int key);
    
};

#endif /* defined(__OpenGL__GLKeyboard__) */
