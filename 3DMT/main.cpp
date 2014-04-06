//
//  main.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Classes/utils/hardware/Arduino.h"
#include "Classes/3DMT.h"
#include "Classes/utils/math/BiasDiscriminator.h"

using namespace std;

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
 
#if defined(__APPLE__) && defined(__MACH__)
#   include ""
#endif
 
 
 */
