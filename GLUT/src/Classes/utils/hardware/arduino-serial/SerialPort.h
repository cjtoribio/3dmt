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
	#include <windows.h>
	#include <stdio.h>
	#include <stdlib.h>
#endif

#define ARDUINO_WAIT_TIME 2000


class SerialPort
{
    private:
        //Serial comm handler
        HANDLE hSerial;
        //Connection status
        bool connected;
        //Get various information about the connection
        COMSTAT status;
        //Keep track of last error
        DWORD errors;

    public:
        //Initialize Serial communication with the given COM port
        SerialPort(char *portName);
        //Close the connection
        //NOTA: for some reason you can't connect again before exiting
        //the program and running it again
        ~SerialPort();
        //Read data in a buffer, if nbChar is greater than the
        //maximum number of bytes available, it will return only the
        //bytes available. The function return -1 when nothing could
        //be read, the number of bytes actually read.
        int ReadData(char *buffer, unsigned int nbChar);
        //Writes data from a buffer through the Serial connection
        //return true on success.
        bool WriteData(char *buffer, unsigned int nbChar);
        //Check if we are actually connected
        bool IsConnected();


};

#endif /* SERIAL_PORT_H_ */
