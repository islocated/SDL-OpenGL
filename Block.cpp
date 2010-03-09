/*
 *  Block.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Block.h"

#include "Image.h"
#include "BasicPhysicsComponent.h"

Block::Block(int X, int Y)
: Sprite(X, Y, 0, 0, false, false)
{
	img = new Image();
	img->loadFile("block.png");
	
	PhysicsComponent * physicsComponent = new BasicPhysicsComponent(this);
	physicsComponent->acceleration.y = 0;
}

Block::~Block(){
	
}

void Block::update(){
	Sprite::update();
}

