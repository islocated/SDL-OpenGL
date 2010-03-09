/*
 *  Game.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Game.h"
#include "State.h"
#include "IO.h"
#include "Logger.h"

#include "SDL.h"
#include "SDL_opengl.h"

Game::Game(int width, int height, bool fullscreen=false)
: m_width(width), m_height(height), screen(NULL), quit(false), m_state(NULL), m_fullscreen(fullscreen)
{
	initGame();
	IO::setEvent(&event);
}

Game::~Game(){
	Logger::getInstance()->debug("game is destroyed");
	
	if(m_state){
		delete m_state;
		m_state = NULL;
	}
	
	SDL_Quit();
}

int Game::initGame(){
	int error;
	error = SDL_Init( SDL_INIT_EVERYTHING ); 
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	//Set up screen
	Uint32 flags = SDL_OPENGL;
	if(m_fullscreen){
		flags |= SDL_FULLSCREEN;
	}
	
	screen = SDL_SetVideoMode(m_width, m_height, 32, flags); 
	if(!screen){
		Logger::getInstance()->error("Bad screen");
		return -1;
	}
	
	//NON-MAC related attributes
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	
	return error;
}

void Game::setState(State * state){
	if(m_state){
		delete m_state;
		m_state = NULL;
	}
	
	m_state = state;
}

int Game::run(){
	while(!quit){ 
		
		handleAllEvents();
		
		update();
		
		render();
	}
	
	return true;
}

void Game::handleAllEvents(){
	while(SDL_PollEvent(&event)){
		handleEvent();
		IO::handleEvent();
	}
}

void Game::handleEvent(){
	//If the user has Xed out the window 
	if( event.type == SDL_QUIT ) { 
		quit = true; 
	}
	else if(event.type == SDL_KEYDOWN){
		switch(event.key.keysym.sym){
			case SDLK_ESCAPE:
				quit = true;
				break;
			default:
				break;
		}
	}
}

void Game::update(){
	if(m_state){
		m_state->update();
	}
}

void Game::resetGL(){
	glMatrixMode( GL_PROJECTION ); 
	glLoadIdentity(); 
	glOrtho(0, m_width, m_height, 0, -1, 1 ); 
	
	glEnable(GL_TEXTURE_2D);
	glEnable (GL_BLEND); 
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
		
	glClearColor( 1, 0, 0, 1 ); 
	glClear(GL_COLOR_BUFFER_BIT);
}

void Game::render(){
	resetGL();
	
	if(m_state){
		m_state->render();
	}
	
	SDL_GL_SwapBuffers();
}

