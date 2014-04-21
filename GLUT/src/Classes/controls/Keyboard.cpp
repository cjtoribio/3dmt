//
//  Keyboard.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Keyboard.h"

Keyboard::Keyboard()
{
    for(int i = 0; i < KEYSCNT; ++i)
        KEY_STATE[i] = false;
    
    for(int i = 0; i < SPECIALKEYSCNT; ++i)
        SPECIAL_KEYS[i] = false;
}

Keyboard::~Keyboard()
{

}

Keyboard& Keyboard::getKeyboard()
{
    static Keyboard instance;
    return instance;
}

void Keyboard::setKeyDown(unsigned char key, int x, int y)
{
    getKeyboard().KEY_STATE[key] = true;
}

void Keyboard::setKeyUp(unsigned char key, int x, int y)
{
    getKeyboard().KEY_STATE[key] = false;
}

bool Keyboard::isPressed(unsigned char key)
{
    return getKeyboard().KEY_STATE[key];
}

bool Keyboard::changedState(unsigned char key)
{
    return getKeyboard().KEY_STATE[key] != getKeyboard().SS_KEY_STATE[key];
}

void Keyboard::setSpecialKey(int key, int x, int y)
{
    getKeyboard().SPECIAL_KEYS[key] ^= 1;
}

bool Keyboard::isSpecialPressed(int key)
{
    return getKeyboard().SPECIAL_KEYS[key];
}

void Keyboard::snapshot()
{
    for(int i = 0; i < KEYSCNT; ++i)
    	getKeyboard().SS_KEY_STATE[i] = getKeyboard().KEY_STATE[i];
    
    for(int i = 0; i < SPECIALKEYSCNT; ++i)
    	getKeyboard().SS_SPECIAL_KEYS[i] = getKeyboard().SPECIAL_KEYS[i];
}
