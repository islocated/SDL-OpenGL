/*
 *  Component.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

//Forward declaration
class Sprite;

class Component
{
public:
	Component(Sprite * owner);
	virtual ~Component();
	
	virtual void update(Uint32 dt);

protected:
	Sprite * owner;
};