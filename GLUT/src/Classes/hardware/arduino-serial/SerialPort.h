/*
 * Port.h
 *
 *  Created on: Apr 6, 2014
 *      Author: CarlosJose
 */

#ifndef SERIAL_PORT_H_
#define SERIAL_PORT_H_

#if defined(__APPLE__) && defined(__MACH__)
	#include <cstdio>     // Standard input/output definitions 
	#include <unistd.h>   // UNIX standard function definitions 
	#include <fcntl.h>    // File control definitions 
	#include <errno.h>    // Error number definitions 
	#include <termios.h>  // POSIX terminal control definitions 
	#include <sys/ioctl.h>
	#include <string>   // String function definitions 
#else
	#include "../../utils/SpecialKeys.h"
	#include <windows.h>
#endif

class SerialPort
{

	PROPERTY_PRIVATE(HANDLE , hPort , HPort);
	PROPERTY_PRIVATE(string , portName , PortName);
	PROPERTY_PRIVATE(int , baudRate , BaudRate);
	PROPERTY_READONLY(int, initialized, Initialized);
	
public:
	SerialPort(string,int);
	~SerialPort();
	
	bool init();
	int close();
	string read(int bytes);
	string readUntil(char delimiter);
};


#endif /* SERIAL_PORT_H_ */
