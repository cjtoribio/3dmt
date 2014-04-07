//
//  main.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Classes/3DMT.h"
#include "Classes/hardware/arduino-serial/SerialPort.h"

using namespace std;



int main(int argc, char** argv)
{
	SerialPort SP("\\\\.\\COM1" , 9600);
	
	SP.init();
	  
	string line = SP.readUntil('\n');
	cout << line << endl;
//    Window window;

//    window.init(argc, argv);
    
    return 0;
}
