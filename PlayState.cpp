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
#include "Sprite.h"
#include "Image.h"

#include "Logger.h"

PlayState::PlayState(){
	Sprite *spr = new Player();
	
	//AddChild will handle deletion of the object
	addChild(spr);
	
	spr = new Sprite(100,100,16,32,true,true);
	spr->setImage(new Image());
	spr->getImage()->loadFile("g_walk_old.png");
	addChild(spr);
}

PlayState::~PlayState(){
	Logger::getInstance()->debug("playstate is destroyed");
}

void PlayState::render(){
	State::render();
}
