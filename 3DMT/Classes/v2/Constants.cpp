/*
 * Constants.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */

class Constants
{
	float MOUSE_SENSITIVITY;
	float WALKING_SPEED;
	Constants(){
		MOUSE_SENSITIVITY = 0.1;
		WALKING_SPEED = 0.01;
	}
public: 
	static float getMouseSense(){
		static Constants instance;
		return instance.MOUSE_SENSITIVITY;
	}
	static float getWalkingSpeed(){
		static Constants instance;
		return instance.WALKING_SPEED;
	}
};
