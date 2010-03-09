/*
 *  Sprite.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "Vector2d.h"
#include "PhysicsComponent.h"

#include <vector>
using namespace std;

//Forward declarations
class Image;
class Component;

class Sprite
{
public:
	Sprite();
	Sprite(float X, float Y, float width, float height, bool animated, bool reverse);
	virtual ~Sprite();
	
public:
	virtual void addComponent(Component * component);
	virtual void setPhysicsComponent(PhysicsComponent * physicsComponent);
	virtual PhysicsComponent* getPhysicsComponent();

public:
	virtual void setImage(Image * img);
	virtual Image* getImage();
	virtual void update();
	virtual void render();
	
protected:
	Image * img;
	vector<Component *> *components;
	PhysicsComponent * physicsComponent;
	
public:
	Vector2d position;
	float angle;
	
	float m_width;
	float m_height;
	bool m_animated;
	bool m_reverse;
	int m_facing;
	
	//Column our frame is at
	int m_frame;
	
	//Row our is on
	int m_type;
};