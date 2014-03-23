/*
 * Mouse.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */
#include <GL/glut.h>
struct Keyboard
{
	bool KEY_STATE[256];
	Keyboard(){
		for(int i = 0; i < 256; ++i)
			KEY_STATE[i] = false;
	}
public: 
	const static int SHIFT = 1;
	const static int CTRL = 2;
	const static int ALT = 4;
	static Keyboard& getKeyboard(){
        static Keyboard instance;
        return instance;
	}
	static void setKeyDown(unsigned char key, int x, int y){
		getKeyboard().KEY_STATE[key] = true;
	}
	static void setKeyUp(unsigned char key, int x, int y){
		getKeyboard().KEY_STATE[key] = false;
	}
	static bool isPressed(unsigned char key){
		return getKeyboard().KEY_STATE[key];
	}
	
	
	Keyboard(Keyboard const&);
    void operator=(Keyboard const&);
};


