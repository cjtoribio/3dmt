//
//  Keyboard.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__Keyboard__
#define __OpenGL__Keyboard__

#include "../utils/SpecialKeys.h"

class Keyboard
{
public:
    
    PROPERTY_PUBLIC(bool, KEY_STATE[KEYSCNT], KEY_STATE);
    PROPERTY_PUBLIC(bool, SPECIAL_KEYS[SPECIALKEYSCNT], SPECIAL_KEYS);
    
    Keyboard();
    ~Keyboard();
    
    static Keyboard& getKeyboard();
    
    static void setSpecialKey(int key, int x, int y);
    static void setKeyUp(unsigned char key, int x, int y);
    static void setKeyDown(unsigned char key, int x, int y);
    
    static bool isSpecialPressed(int key);
    static bool isPressed(unsigned char key);
    
    void operator=(Keyboard const&);
    
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Keyboard.cpp"
#endif

#endif /* defined(__OpenGL__Keyboard__) */
