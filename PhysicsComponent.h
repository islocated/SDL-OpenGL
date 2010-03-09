/*
 *  PhysicsComponent.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "Component.h"
#include "Vector2d.h"

class Sprite;

class PhysicsComponent : public Component
{
public:
	PhysicsComponent(Sprite * owner);
	virtual ~PhysicsComponent();
	
	virtual void update();
	
public:
	Vector2d position;
	Vector2d velocity;
	Vector2d acceleration;
};