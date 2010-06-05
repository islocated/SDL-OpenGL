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
#include "Animation.h"
#include <math.h>

Player::Player(){
	m_frame = 2;
	m_animated = true;
	m_width = 16.0f;
	m_height = 32.0f;
	
	img = new Image();
	img->loadFile("Resources/g_walk_old.png");
	
	PhysicsComponent* physicsComponent = new BasicPhysicsComponent(this);
	physicsComponent->acceleration.y = 100;
	
	//Components handle deletion of the components later
	setPhysicsComponent(physicsComponent);
	
	int idle[] = {0};
	addAnimation("idle", new Animation(1, idle, 0, 1.0f, true));
	
	int walk[] = {1,2,3,4,5};
	addAnimation("walk", new Animation(5, walk, 0, .5f, true));
	
	int jump[] = {1};
	addAnimation("jump", new Animation(1, jump, 0, 1.0f, true));
	
	playAnimation("jump");
}

Player::~Player(){
	Logger::getInstance()->debug() << "player is destroyed";
}

void Player::update(Uint32 dt){
	Sprite::update(dt);
	
	//getPhysicsComponent()->velocity.x = 0;
	//getPhysicsComponent()->velocity.y = 0;
	
	if(IO::keyDown('a')){
		m_facing = 1;
		getPhysicsComponent()->velocity.x = -80;
		playAnimation("walk");
	}
	else if(IO::keyDown('d')){
		m_facing = 0;
		getPhysicsComponent()->velocity.x = 80;
		playAnimation("walk");
	}
	else if(IO::keyDown('w')){
		getPhysicsComponent()->velocity.y = -150;
		playAnimation("jump");
	}
	else if(IO::keyDown('s')){
		getPhysicsComponent()->velocity.y = 80;
		playAnimation("jump");
	}
	else{
		playAnimation("idle");
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