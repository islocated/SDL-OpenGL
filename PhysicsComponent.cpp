/*
 *  PhysicsComponent.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "PhysicsComponent.h"
#include "Logger.h"

#include "Sprite.h"

PhysicsComponent::PhysicsComponent(Sprite * sprite)
: Component(sprite), position(0,0), velocity(0,0), acceleration(0,0)
{
	position.x = owner->position.x;
	position.y = owner->position.y;
}


PhysicsComponent::~PhysicsComponent(){
	Logger::getInstance()->debug() << "physics component is destroyed";
}

void PhysicsComponent::update(){
	
}