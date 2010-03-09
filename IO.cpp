/*
 *  IO.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "IO.h"

#include "SDL.h"

//Initialize your static members here or else you get a linker error
SDL_Event* IO::c_event = NULL;
map<int, bool> IO::c_keys;

IO::IO()
{
	
}

IO::~IO(){
	
}

void IO::setEvent(SDL_Event * event){
	c_event = event;
}

SDL_Event * IO::getEvent(){
	return c_event;
}

void IO::handleEvent(){
	switch (c_event->type) {
		case SDL_KEYDOWN:
			c_keys[c_event->key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			c_keys[c_event->key.keysym.sym] = false;
			break;
		default:
			break;
	}
}

//TODO:Figure this out
bool IO::justPressed(char c){
	return c_event->type == SDL_KEYDOWN && c_event->key.keysym.sym == (int) c;
}

//TODO:Figure this out
bool IO::justReleased(char c){
	return c_event->type == SDL_KEYUP && c_event->key.keysym.sym == (int) c;
}

bool IO::keyDown(char c){
	return c_keys[(int) c];
}

bool IO::keyUp(char c){
	return !c_keys[(int) c];
}