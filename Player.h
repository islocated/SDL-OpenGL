/*
 *  Player.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "Sprite.h"

union SDL_Event;

class Player : public Sprite
{
public:
	Player();
	virtual ~Player();
	
	virtual void update();
};