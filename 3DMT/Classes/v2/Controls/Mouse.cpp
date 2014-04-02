/*
 * Mouse2.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */

#ifndef File_Mouse2
#define File_Mouse2


struct Mouse2
{
	float Mouse2X , Mouse2Y;
	float prevX , prevY;
	bool buttons[5];
	Mouse2(){
		prevX = Mouse2X = 0;
		prevY = Mouse2Y = 0;
		for(int i = 0; i < 5; ++i)
			buttons[i] = true;
	}
public: 
	static Mouse2& getMouse2(){
        static Mouse2 instance;
        return instance;
	}
	static void updateMouse2(int button,int state,int x, int y){
		getMouse2().buttons[button] = state;
		getMouse2().Mouse2X = x;
		getMouse2().Mouse2Y = y;
	}
	static void updateMouse2Pos(int x, int y){
		getMouse2().Mouse2X = x;
		getMouse2().Mouse2Y = y;
	}
	static void snapshot(){
		getMouse2().prevX = getMouse2().Mouse2X;
		getMouse2().prevY = getMouse2().Mouse2Y;
	}
	static float getX(){
		return getMouse2().Mouse2X;
	}
	static float getDX(){
		return getMouse2().Mouse2X - getMouse2().prevX;
	}
	static float getY(){
		return getMouse2().Mouse2Y;
	}
	static float getDY(){
		return getMouse2().Mouse2Y - getMouse2().prevY;
	}
	static bool isPressed(int id){
		return !getMouse2().buttons[id];
	}
	
	Mouse2(Mouse2 const&);
    void operator=(Mouse2 const&);
};


#endif
