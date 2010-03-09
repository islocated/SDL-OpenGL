/*
 *  State.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "State.h"
#include "Logger.h"

State::State(){
	layer = new Layer();
}

State::~State(){
	Logger::getInstance()->debug("state is destroyed");
	
	if(layer){
		delete layer;
		layer = NULL;
	}
}

void State::addChild(Sprite * sprite){
	layer->addChild(sprite);
}

void State::update(){
	layer->update();
}

void State::render(){
	layer->render();
}
