/*
 *  Player.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Player.h"

#include "Image.h"
#include "BasicPhysicsComponent.h"
#include "IO.h"
#include "Logger.h"

Player::Player(){
	m_frame = 2;
	m_animated = true;
	m_width = 16.0f;
	m_height = 32.0f;
	
	img = new Image();
	img->loadFile("g_walk_old.png");
	
	PhysicsComponent * physicsComponent = new BasicPhysicsComponent(this);
	physicsComponent->acceleration.y = 0;
	
	//Components handle deletion of the components later
	setPhysicsComponent(physicsComponent);
}

Player::~Player(){
	Logger::getInstance()->debug("player is destroyed");
}

void Player::update(){
	Sprite::update();
	
	getPhysicsComponent()->velocity.x = 0;
	getPhysicsComponent()->velocity.y = 0;
	
	if(IO::keyDown('a')){
		m_facing = 1;
		getPhysicsComponent()->velocity.x = -.1;
	}
	
	if(IO::keyDown('d')){
		m_facing = 0;
		getPhysicsComponent()->velocity.x = .1;
	}
	
	if(IO::keyDown('w')){
		getPhysicsComponent()->velocity.y = -.1;
	}
	if(IO::keyDown('s')){
		getPhysicsComponent()->velocity.y = .1;
	}
	
	if(IO::keyDown('r'))
		angle += 20 * 3.14/180;
	if(IO::keyDown('f'))
		angle -= 20 * 3.14/180;
	
	if(IO::keyDown('1'))
		m_frame = 1;
	if(IO::keyDown('2'))
		m_frame = 2;
	if(IO::keyDown('3'))
		m_frame = 3;
	if(IO::keyDown('4'))
		m_frame = 4;
}