/*
 *  Timer.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Timer.h"

#include "SDL_Timer.h"

Timer::Timer()
: m_startTick(0)
{
	
}

Timer::~Timer(){
	
}

int Timer::getTicks(){
	return SDL_GetTicks();
}

void Timer::start(){
	m_startTick = SDL_GetTicks();
}

float Timer::secondsElapsed(){
	return (SDL_GetTicks() - m_startTick)/1000.0f;
}