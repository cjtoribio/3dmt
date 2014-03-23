/*
 * Mouse.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */

struct Mouse
{
	float mouseX , mouseY;
	float prevX , prevY;
	bool buttons[5];
	Mouse(){
		prevX = mouseX = 0;
		prevY = mouseY = 0;
		for(int i = 0; i < 5; ++i)
			buttons[i] = true;
	}
public: 
	static Mouse& getMouse(){
        static Mouse instance;
        return instance;
	}
	static void updateMouse(int button,int state,int x, int y){
		getMouse().buttons[button] = state;
		getMouse().mouseX = x;
		getMouse().mouseY = y;
	}
	static void updateMousePos(int x, int y){
		getMouse().mouseX = x;
		getMouse().mouseY = y;
	}
	static void snapshot(){
		getMouse().prevX = getMouse().mouseX;
		getMouse().prevY = getMouse().mouseY;
	}
	static float getX(){
		return getMouse().mouseX;
	}
	static float getDX(){
		return getMouse().mouseX - getMouse().prevX;
	}
	static float getY(){
		return getMouse().mouseY;
	}
	static float getDY(){
		return getMouse().mouseY - getMouse().prevY;
	}
	static bool isPressed(int id){
		return !getMouse().buttons[id];
	}
	
	Mouse(Mouse const&);
    void operator=(Mouse const&);
};


