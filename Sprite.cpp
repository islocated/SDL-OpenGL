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

Sprite::Sprite()
: img(NULL), position(0,0), angle(0.0f), components(0), physicsComponent(NULL)
, m_width(0), m_height(0), m_animated(false), m_reverse(false), m_facing(0), m_frame(0), m_type(0), m_scale(1,1)
{
	
}

Sprite::Sprite(float X, float Y, float width, float height, bool animated, bool reverse)
: img(NULL), position(X, Y), angle(0.0f), components(0), physicsComponent(NULL)
, m_width(width), m_height(height), m_animated(animated), m_reverse(reverse), m_facing(0), m_frame(0), m_type(0), m_scale(1,1)
{
	
}

Sprite::~Sprite(){
	Logger::getInstance()->debug("sprite is destroyed");
	if(img){
		delete img;
		img = NULL;
	}
	
	if(!components.empty()){
		Component * component = NULL;
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
}

void Sprite::addComponent(Component * component){
	components.push_back(component);
}

void Sprite::setPhysicsComponent(PhysicsComponent * physicsComponent){
	this->physicsComponent = physicsComponent;
}

PhysicsComponent* Sprite::getPhysicsComponent(){
	return physicsComponent;
}

void Sprite::setImage(Image * image){
	this->img = image;
}

Image* Sprite::getImage(){
	return this->img;
}

void Sprite::update(){
	Component * component = NULL;
	for(int i = 0; i < components.size(); i++){
		component = components[i];
		if(component){
			component->update();
		}
	}
	
	if(physicsComponent){
		physicsComponent->update();
	}
}

void Sprite::render(){
	if(!img){
		return;
	}
	
	glMatrixMode( GL_MODELVIEW ); 
	glLoadIdentity();
	
	glTranslatef(position.x, position.y, 0);
	glScalef(m_scale.x, m_scale.y, 1.0f);
	
	glRotatef(angle, 0.0f,0.0f,1.0f);	//Rotate the image on the Z axis
	
	
	if(m_animated){
		img->render(m_frame, m_type, m_facing, m_width, m_height);
	}
	else{
		img->render();
	}
}