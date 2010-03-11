/*
 *  Component.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Component.h"
#include "Sprite.h"
#include "Logger.h"

Component::Component(Sprite * sprite)
: owner(sprite)
{
	
}

Component::~Component(){
	Logger::getInstance()->debug() << "component is destroyed";
	
	//Do not delete owner, they are responsible for this themselves
	if(owner){
		owner = NULL;
	}
}

void Component::update(){
	
}