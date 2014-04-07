//
//  Arduino.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/2/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__Arduino__
#define ___DMT__Arduino__

#include "../utils/SpecialKeys.h"
#include "../utils/primitives/vec3.h"
//#include "arduino-serial/arduino-serial-lib.h"
#include "libusb/libusb.h"
#include "../utils/SpecialKeys.h"

class Arduino
{
public:
    
    PROPERTY(int, portConfig, PortConfig);
    PROPERTY(int, baudRate, BaudRate);
    PROPERTY(vector<vec3>, data, Data);
    PROPERTY(string, port, Port);
    PROPERTY(string, buffer, Buffer);
    
    Arduino();
    ~Arduino();
    
    void init();
    void fillDataBuffer();
    
    vector<double> getData();

};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Arduino.cpp"
#endif

#endif /* defined(___DMT__Arduino__) */
