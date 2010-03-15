/*
 *  AnimationComponent.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/14/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Component.h"

class Sprite;

class AnimationComponent : Component
{
public:
	AnimationComponent(Sprite * owner);
	~AnimationComponent();
	
	virtual void update(Uint32 dt);
};