/*
 *  Block.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Sprite.h"

class Block : public Sprite
{
public:
	Block(int X, int Y);
	~Block();
	
	virtual void update();
};