/*
 *  PlayState.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "State.h"

class PlayState : public State
{
public:
	PlayState();
	virtual ~PlayState();
	
	void handleCollisions();
	
	void update();
	void render();
	
private:
};