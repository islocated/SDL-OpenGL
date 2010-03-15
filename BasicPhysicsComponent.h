/*
 *  BasicPhysicsComponent.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "PhysicsComponent.h"
#include "Vector2d.h"

class Sprite;

class BasicPhysicsComponent : public PhysicsComponent
{
public:
	BasicPhysicsComponent(Sprite * sprite);
	virtual ~BasicPhysicsComponent();
	
	virtual void update(Uint32 dt);

protected:
	virtual void updateAngle(Uint32 dt);
	virtual void updatePosition(Uint32 dt);
};
