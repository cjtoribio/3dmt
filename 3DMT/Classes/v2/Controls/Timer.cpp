/*
 * Timer.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */

#ifndef File_Timer
#define File_Timer


#include "../../SpecialKeys.h"

class Timer
{
	float currentTime, lastTime;
	Timer(){
		currentTime = lastTime = 0;
	}
public:
	static Timer& getTimer(){
        static Timer instance;
        return instance;
	}
	static void update(){
		getTimer().lastTime = getTimer().currentTime;
		getTimer().currentTime = glutGet((float)GLUT_ELAPSED_TIME);
	}
	static float getTime(){
		return getTimer().currentTime;
	}
	static float getDelta(){
		return getTimer().currentTime - getTimer().lastTime;
	}

	Timer(Timer const&);
    void operator=(Timer const&);
};




#endif
