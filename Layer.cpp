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
: children(new vector<Sprite *>(0))
{

}

Layer::~Layer(){
	Logger::getInstance()->debug("layer is destroyed");

	if(children){
		Sprite *spr = NULL;
		for(int i = 0; i < children->size(); i++){
			spr = children->at(i);
			if(spr){
				delete spr;
			}
		}
		delete children;
		children = NULL;
	}
}

void Layer::addChild(Sprite * sprite){
	children->push_back(sprite);
}

void Layer::update(){
	Sprite *spr = NULL;
	for(int i = 0; i < children->size(); i++){
		spr = children->at(i);
		if(spr){
			spr->update();
		}
	}
}

void Layer::render(){
	Sprite *spr = NULL;
	for(int i = 0; i < children->size(); i++){
		spr = children->at(i);
		if(spr){
			spr->render();
		}
	}
}