/*
 *  BasicPhysicsComponent.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "BasicPhysicsComponent.h"

#include "Sprite.h"
#include "Logger.h"

BasicPhysicsComponent::BasicPhysicsComponent(Sprite * sprite)
: PhysicsComponent(sprite)
{
	
}

BasicPhysicsComponent::~BasicPhysicsComponent(){
	Logger::getInstance()->debug() << "basic physics component is destroyed";
}

void BasicPhysicsComponent::update(Uint32 dt){
	PhysicsComponent::update(dt);
	
	updateAngle(dt);
	updatePosition(dt);
}

void BasicPhysicsComponent::updateAngle(Uint32 dt){
	
}

void BasicPhysicsComponent::updatePosition(Uint32 dt){
	float elapsed = dt/1000.0f;
	
	velocity.x += acceleration.x * elapsed;
	velocity.y += acceleration.y * elapsed;
	
	position.x += velocity.x * elapsed;
	position.y += velocity.y * elapsed;
	
	owner->position.x = position.x;
	owner->position.y = position.y;
}

