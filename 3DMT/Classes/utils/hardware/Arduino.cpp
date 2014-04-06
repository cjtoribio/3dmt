//
//  Arduino.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/2/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Arduino.h"

Arduino::Arduino()
{
    port = PORT;
    baudRate = B57600;
    buffer = "";
}

Arduino::~Arduino()
{
    
}

void Arduino::init()
{
    portConfig = serialport_init(port.c_str(), baudRate);
}

void Arduino::fillDataBuffer()
{
    string tempbuff = "";
    
    serialport_read_until(portConfig, buffer, ENDOFLN, BUFFMAX, TIMEOUT);
    serialport_read_until(portConfig, buffer, ENDOFLN, BUFFMAX, TIMEOUT);
    serialport_read_until(portConfig, buffer, ENDOFLN, BUFFMAX, TIMEOUT);
    
    tempbuff = buffer;
    
    //printf("%s", tempbuff.c_str());
}
