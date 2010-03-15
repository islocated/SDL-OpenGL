/*
 *  State.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "Layer.h"

//Forward declarations
class Sprite;

class State
{
public:
	State();
	virtual ~State();
	
	void addChild(Sprite * sprite);

	virtual void update(Uint32 dt);
	virtual void render();
	
protected:
	Layer * layer;
};