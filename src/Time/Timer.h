/*
 *  Timer.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

class Timer
{
public:
	Timer();
	~Timer();
	
	void start();
	Uint32 getTicks();
	float secondsElapsed();
	
private:
	Uint32 m_startTick;
};