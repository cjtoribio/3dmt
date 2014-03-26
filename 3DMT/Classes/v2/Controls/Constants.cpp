/*
 * Constants.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */
#ifndef File_Constants
#define File_Constants


class Constants
{
	float MOUSE_SENSITIVITY;
	float WALKING_SPEED;
	float FRAMES_PER_SEC;
	Constants(){
		MOUSE_SENSITIVITY = 0.003;
		WALKING_SPEED = 1;
		FRAMES_PER_SEC = 1000;
	}
	static Constants& getConstants(){
        static Constants instance;
        return instance;
	}
public: 
	static float getMouseSense(){
		return getConstants().MOUSE_SENSITIVITY;
	}
	static float getWalkingSpeed(){
		return getConstants().WALKING_SPEED;
	}
	static float getFramesPerSec(){
		return getConstants().FRAMES_PER_SEC;
	}

	Constants(Constants const&);
    void operator=(Constants const&);
};


#endif
