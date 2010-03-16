/*
 *  Sprite.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Sprite.h"
#include "Image.h"
#include "Component.h"
#include "Logger.h"
#include "Animation.h"

Sprite::Sprite()
: img(NULL), position(0,0), angle(0.0f), components(0), physicsComponent(NULL)
, m_width(0), m_height(0), m_animated(false), m_reverse(false), m_facing(0), m_frame(0)
, m_type(0), m_scale(1,1), animations(), m_key(NULL)
{
}

Sprite::Sprite(float X, float Y, float width, float height, bool animated, bool reverse)
: img(NULL), position(X, Y), angle(0.0f), components(0), physicsComponent(NULL)
, m_width(width), m_height(height), m_animated(animated), m_reverse(reverse), m_facing(0) 
, m_frame(0), m_type(0), m_scale(1,1), animations(), m_key(NULL)
{
}

Sprite::~Sprite(){
	Logger::getInstance()->debug() << "sprite is destroyed";
	if(img){
		delete img;
		img = NULL;
	}
	
	if(!components.empty()){
		Component* component = NULL;
		for(int i = 0; i < components.size(); i++){
			component = components[i];
			if(component){
				delete component;
			}
		}
		components.erase(components.begin(), components.end());
	}
	
	if(physicsComponent){
		delete physicsComponent;
		physicsComponent = NULL;
	}
	
	//Map automatically becomes not empty if we used it once to check if an element is there or not
	if(!animations.empty()){
		Animation* animation = NULL;
		for(map<char*, Animation*>::iterator it = animations.begin(); it != animations.end(); ++it){
			Logger::getInstance()->debug() << "destroying " << it->first;
			animation = it->second;
			delete animation;
		}
		
		animations.clear();
	}
}

void Sprite::addAnimation(char* key, Animation* animation){
	animations[key] = animation;
}

void Sprite::playAnimation(char* key, bool reset){
	m_key = key;
	
	if(reset){
		animations[m_key]->reset();
	}
}

void Sprite::addComponent(Component* component){
	components.push_back(component);
}

void Sprite::setPhysicsComponent(PhysicsComponent* physicsComponent){
	this->physicsComponent = physicsComponent;
}

PhysicsComponent* Sprite::getPhysicsComponent(){
	return physicsComponent;
}

void Sprite::setImage(Image* image){
	this->img = image;
}

Image* Sprite::getImage(){
	return this->img;
}

void Sprite::update(Uint32 dt){
	Component* component = NULL;
	for(int i = 0; i < components.size(); i++){
		component = components[i];
		if(component){
			component->update(dt);
		}
	}
	
	if(physicsComponent){
		physicsComponent->update(dt);
	}
	
	if(m_key && animations[m_key]){
		animations[m_key]->update(dt);
	}
}

void Sprite::render(){
	if(!img){
		return;
	}
	
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	
	glTranslatef(position.x, position.y, 0.0f);
	glScalef(m_scale.x, m_scale.y, 1.0f);
	
	glRotatef(angle, 0.0f, 0.0f, 1.0f);	//Rotate the image on the Z axis
	
	if(m_animated){
		if(m_key && animations[m_key]){
			m_frame = animations[m_key]->getCurrentFrame();
			m_type = animations[m_key]->getRow();
		}
		
		img->render(m_frame, m_type, m_facing, m_width, m_height);
	}
	else{
		img->render();
	}
}