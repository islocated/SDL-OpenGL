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
#include "Block.h"
#include "Sprite.h"
#include "Image.h"
#include "Layer.h"
#include "Logger.h"

#include <vector>
using namespace std;

PlayState::PlayState(){
	Sprite* spr = new Player();
	
	//AddChild will handle deletion of the object
	addChild(spr);
	
	
	spr = new Sprite(100,100,16,32,true,true);
	spr->m_scale.x = 5.0f;
	spr->m_scale.y = 5.0f;
	spr->setImage(new Image());
	spr->getImage()->loadFile("Resources/g_walk_old.png");
	addChild(spr);
	
	spr = new Block(100,200);
	addChild(spr);
	
}

PlayState::~PlayState(){
	Logger::getInstance()->debug() << "playstate is destroyed";
}

void PlayState::update(Uint32 dt){
	State::update(dt);
	
	handleCollisions();
}

void PlayState::render(){
	State::render();
}

void PlayState::handleCollisions(){
	vector<Sprite *> children = layer->getChildren();
	
	Sprite* spriteA = NULL;
	Sprite* spriteB = NULL;
	
	for(int i = 0; i < children.size(); i++){
		spriteA = children[i];
		for(int j = i + 1; j < children.size(); j++){
			spriteB = children[j];
			
			//spriteA->physicsComponent->collide(spriteB);
		}
	}
}
