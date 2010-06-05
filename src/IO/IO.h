/*
 *  IO.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <map>
using namespace std;

union SDL_Event;

class IO
{
public:
	IO();
	~IO();
	
	static void handleEvent();
	static bool justPressed(char c);
	static bool justReleased(char c);
	
	static bool keyDown(char c);
	static bool keyUp(char c);
	
	static void setEvent(SDL_Event* event);
	static SDL_Event* getEvent();
	
public:
	static SDL_Event* c_event;
	
	static map<int, bool> c_keys;
};