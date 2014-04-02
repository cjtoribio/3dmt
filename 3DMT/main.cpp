//
//  main.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Classes/utils/data/DataBuffer.h"
#include "Classes/utils/hardware/Arduino.h"
#include "Classes/3DMT.h"

using namespace std;

// 108.59.85.25

vector<string> print_devs()
{
    vector<string> devices;
    
	libusb_device *dev;
    
    libusb_device **devs;
	int r;
	ssize_t cnt;
    
	r = libusb_init(NULL);
    
	cnt = libusb_get_device_list(NULL, &devs);
    
	int i = 0;
    
	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
		}
        char *s;
        
        sscanf(s,"%d/%d", libusb_get_bus_number(dev), libusb_get_device_address(dev));
        
        string device = s;
        
        cout << device << endl;
        devices.push_back(device);
	}
    return devices;
}

int main(int argc, char** argv)
{
    Window window;
    
    window.init(argc, argv);

    return 0;
}


/*
 vector<double> VEC;
 srand(3958769);
 VEC.push_back(60);
 for(int i = 1; i < 128; ++i)
 {
 VEC.push_back( max(min(VEC.back() + rand() % 20 - 10 , 120.0),0.0) );
 Point(0,i,VEC.back()).draw();
 }
 SignalFilter SF;
 //    for(int i = 0; i < 64; ++i)
 //    	SF.push(50);
 for(int i = 0; i < 128; ++i)
 SF.push(VEC[i]);
 //    for(int i = 0; i < 64; ++i)
 //    	SF.push(VEC.back() );
 VEC = SF.getProcessedSignal(process1);
 for(int i = 0; i < 128; ++i)
 {
 Point p(0,i,VEC[i]);
 p.setColor(1,1,0);
 //    	p.draw();
 }
 VEC = SF.getProcessedSignal(process2);
 vector<double> INT(VEC.size());
 for(int i = 0; i < 128; ++i)
 {
 Point p(0,i,VEC[i]);
 p.setColor(1,0,1);
 //p.draw();
 INT[i] = (VEC[i] + ((i == 0) ? 0 : INT[i-1]));
 }
 for(int i = 0; i < 128; ++i)
 {
 Point p(0,i,INT[i] * 0.1);
 p.setColor(0,0,1);
 //p.draw();
 }
 
 ----------
 
 
 
 */
