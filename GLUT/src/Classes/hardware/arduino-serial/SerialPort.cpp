//
// arduino-serial-lib -- simple library for reading/writing serial ports
//
// 2006-2013, Tod E. Kurt, http://todbot.com/blog/
//

//#include "arduino-serial-lib.h"

#ifndef ___DMT__ArduinoSerialLib_h_
#define ___DMT__ArduinoSerialLib_h_


#include "SerialPort.h"


// uncomment this to debug reads
//#define SERIALPORTDEBUG 

SerialPort::SerialPort(string portName , int baudRate)
{
	this->portName = portName;
	this->baudRate = baudRate;
	this->initialized = false;
}

SerialPort::~SerialPort()
{
	if(initialized)
		close();
}

// takes the string name of the serial port (e.g. "/dev/tty.usbserial","COM1")
// and a baud rate (bps) and connects to that port at that speed and 8N1.
// opens the port in fully raw mode so you can send binary data.
// returns valid fd, or -1 on error
bool SerialPort::init()
{
	if(initialized)return true;
	// Open serial port
	HANDLE serialHandle;

	serialHandle = CreateFile(
			portName.c_str(), 					//ie. "\\\\.\\COM1"
			GENERIC_READ | GENERIC_WRITE, 
			0, 
			0, 
			OPEN_EXISTING, 
			FILE_ATTRIBUTE_NORMAL, 
			0
	);

	// Do some basic settings
	DCB serialParams = { 0 };
	serialParams.DCBlength = sizeof(serialParams);
	
	if (!GetCommState(serialHandle,&serialParams)) {
		cerr << "Serial Port not initialized INITIALIZING 1" << endl;
		close();
		return false; 
	}
	
	serialParams.BaudRate = baudRate;
	serialParams.ByteSize = 8;
	serialParams.StopBits = ONESTOPBIT;
	serialParams.Parity = NOPARITY;

	if (!SetCommState(serialHandle,&serialParams))  {
		cerr << "Serial Port Terminated INITIALIZING 2" << endl;
		close();
		return false; 
	}

	// Set timeouts
	COMMTIMEOUTS timeout = { 0 };
	timeout.ReadIntervalTimeout = 1;
	timeout.ReadTotalTimeoutConstant = 1;
	timeout.ReadTotalTimeoutMultiplier = 1;
	timeout.WriteTotalTimeoutConstant = 1;
	timeout.WriteTotalTimeoutMultiplier = 1;

	if(!SetCommTimeouts(serialHandle, &timeout))  {
		cerr << "Serial Port Terminated INITIALIZING 3" << endl;
		close();
		return false;
	}
	
	cerr << "Serial Port Initialized Succesfully!" << endl;
	return (initialized = true);
}

//
int SerialPort::close()
{
	cerr << "Serial Port Closed" << endl;
	initialized = false;
	return CloseHandle(hPort);
//    return close( fd );
}

string SerialPort::read(int bytes = 1)
{
	char buffer[bytes]; buffer[0] = '\0';
	if(initialized)
	{
		DWORD dwCommModemStatus; 
		DWORD dwBytesTransferred;
		SetCommMask (hPort, EV_RXCHAR | EV_ERR); //receive character event 
		WaitCommEvent (hPort, &dwCommModemStatus, 0); //wait for character 
		if (dwCommModemStatus & EV_RXCHAR) 
			ReadFile (hPort, &buffer, 1, &dwBytesTransferred, 0); //read 1 
		else if (dwCommModemStatus & EV_ERR) {
			cerr << "Serial Port Terminated READING" << endl;
			close();
		}
	}
    return string(buffer);
}

string SerialPort::readUntil(char delimiter)
{
	string buf = "";
	if(initialized)
	{
		while(true)
		{
			string letter = read(1);
			if(letter[0] == delimiter)
				break;
			else
				buf += letter;
		}
	}
	return buf;
}


#endif
