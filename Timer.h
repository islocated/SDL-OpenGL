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
	int getTicks();
	float secondsElapsed();
	
private:
	int m_startTick;
};