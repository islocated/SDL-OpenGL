/*
 *  PlayState.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "PlayState.h"
#include "Player.h"

#include "Logger.h"

PlayState::PlayState(){
	Sprite *spr = new Player();
	
	//AddChild will handle deletion of the object
	addChild(spr);
}

PlayState::~PlayState(){
	Logger::getInstance()->debug("playstate is destroyed");
}

void PlayState::render(){
	State::render();
}
