/*
 * Mouse.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */

#ifndef File_Keyboard2
#define File_Keyboard2


struct Keyboard2
{
	bool KEY_STATE[256];
	bool SPECIAL_KEYS[110];
	int count;
	Keyboard2(){
		for(int i = 0; i < 256; ++i)
			KEY_STATE[i] = false;
		for(int i = 0; i < 110; ++i)
			SPECIAL_KEYS[i] = false;
		count = 0;
	}
public: 
	const static int SHIFT = 1;
	const static int CTRL = 2;
	const static int ALT = 4;
	static Keyboard2& getKeyboard2(){
        static Keyboard2 instance;
        return instance;
	}
	static void setKeyDown(unsigned char key, int x, int y){
		getKeyboard2().KEY_STATE[key] = true;
	}
	static void setKeyUp(unsigned char key, int x, int y){
		getKeyboard2().KEY_STATE[key] = false;
	}
	static void setSpecialKey(int key, int x, int y){
		getKeyboard2().SPECIAL_KEYS[key] ^= 1;
	}
	static bool isPressed(unsigned char key){
		return getKeyboard2().KEY_STATE[key];
	}
	static bool isSpecialPressed(int key){
		return getKeyboard2().SPECIAL_KEYS[key];
	}
	
	
	Keyboard2(Keyboard2 const&);
    void operator=(Keyboard2 const&);
};

#endif
