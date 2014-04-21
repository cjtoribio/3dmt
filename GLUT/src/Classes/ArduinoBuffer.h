/*
 * ArduinoBuffer.h
 *
 *  Created on: Apr 16, 2014
 *      Author: CarlosJose
 */

#ifndef ARDUINOBUFFER_H_
#define ARDUINOBUFFER_H_

#include <queue>
#include "utils/hardware/arduino-serial/SerialPort.h"

using namespace std;

class ArduinoBuffer
{
#define BATCHSIZE 512
	queue<char> Q;
	char buffer[BATCHSIZE];
	
	SerialPort* SP;
public: 
	void init();
	void getFromArduino();
	void getNextPoint(int&,int&,int&);
	int readCoord(char C);
	bool isEmpty();
};

#endif /* ARDUINOBUFFER_H_ */
