/*
 *  Layer.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Layer.h"
#include "Logger.h"

Layer::Layer()
: children(0)
{

}

Layer::~Layer(){
	Logger::getInstance()->debug() << "layer is destroyed";
	
	if(!children.empty()){
		Sprite *spr = NULL;
		for(int i = 0; i < children.size(); i++){
			spr = children[i];
			if(spr){
				delete spr;
			}
		}
		
		children.erase(children.begin(), children.end());
	}
}

void Layer::addChild(Sprite * sprite){
	children.push_back(sprite);
}

vector<Sprite *> Layer::getChildren(){
	return children;
}

void Layer::update(){
	Sprite *spr = NULL;
	for(int i = 0; i < children.size(); i++){
		spr = children[i];
		if(spr){
			spr->update();
		}
	}
}

void Layer::render(){
	Sprite *spr = NULL;
	for(int i = 0; i < children.size(); i++){
		spr = children[i];
		if(spr){
			spr->render();
		}
	}
}