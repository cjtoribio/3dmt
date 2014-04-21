/*
 * ArduinoBuffer.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: CarlosJose
 */

#include "ArduinoBuffer.h"
#include <iostream>

void ArduinoBuffer::init()
{
	SP = new SerialPort("\\\\.\\COM4");
}
void ArduinoBuffer::getFromArduino()
{
	int size = SP->ReadData(buffer, BATCHSIZE - 1);
	if(size == -1)return;
	for(int i = 0; i < size; ++i)
		Q.push(buffer[i]);
}
void ArduinoBuffer::getNextPoint(int &x,int &y,int &z)
{
	x = readCoord('X');
	y = readCoord('Y');
	z = readCoord('Z');
}
int ArduinoBuffer::readCoord(char C)
{
	while(Q.front() != C) Q.pop(); Q.pop();
	int HIGH_BYTE = byte(Q.front()); Q.pop();
	int LOW_BYTE = byte(Q.front()); Q.pop();
	return (HIGH_BYTE << 8) + (LOW_BYTE);
}
bool ArduinoBuffer::isEmpty()
{
	return Q.size() < 50;
}

#undef BATCHSIZE
