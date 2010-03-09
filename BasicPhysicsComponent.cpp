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
	Logger::getInstance()->debug("basic physics component is destroyed");
}

void BasicPhysicsComponent::update(){
	PhysicsComponent::update();
	
	updateAngle();
	updatePosition();
}

void BasicPhysicsComponent::updateAngle(){
	
}

void BasicPhysicsComponent::updatePosition(){
	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
	
	position.x += velocity.x;
	position.y += velocity.y;
	
	owner->position.x = position.x;
	owner->position.y = position.y;
}

