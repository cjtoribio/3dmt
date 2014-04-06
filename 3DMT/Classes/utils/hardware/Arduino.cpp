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
    port = PORT2;
    baudRate = B28800;
    buffer = "";
}

Arduino::~Arduino()
{
    
}

void Arduino::init()
{
    portConfig = serialport_init(port.c_str(), baudRate);
}

vec3 Arduino::getCoordinates()
{
    
    string line;
    do
    {
        line = serialport_read_until(portConfig, ENDOFLN, TIMEOUT);
    }while(line[0]!='X');
    string XX = serialport_read_until(portConfig, ENDOFLN, TIMEOUT);
    do
    {
        line = serialport_read_until(portConfig, ENDOFLN, TIMEOUT);
    }while(line[0]!='Y');
    string YY = serialport_read_until(portConfig, ENDOFLN, TIMEOUT);
    do
    {
        line = serialport_read_until(portConfig, ENDOFLN, TIMEOUT);
    }while(line[0]!='Z');
    string ZZ = serialport_read_until(portConfig, ENDOFLN, TIMEOUT);
    
    vec3 v;
//    if(XX == "" || XX[0] == 'X' || XX[0] == 'Z' || XX[0] == 'Y')XX = "0.0";
//    if(YY == "" || YY[0] == 'X' || YY[0] == 'Z' || YY[0] == 'Y')YY = "0.0";
//    if(ZZ == "" || ZZ[0] == 'X' || ZZ[0] == 'Z' || ZZ[0] == 'Y')ZZ = "0.0";
    sscanf((XX+ " " + YY + " " + ZZ).c_str(), "%f%f%f" , &v.x , &v.y , &v.z);
    
    cout << "READ: " << XX << " " << YY << " " << ZZ << endl;
    
    return v;
}