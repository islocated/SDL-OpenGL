/*
 *  Game.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

class State;
class SDL_Surface;
union SDL_Event;

class Game{
public:
	Game(int width, int height, bool fullscreen);
	virtual ~Game();
	
	virtual int initGame();
	void setState(State * state);
	
	virtual void handleEvent();
	
	virtual int run();
	virtual void update();
	virtual void render();
	
protected:
	int quit;
	
	int m_width;
	int m_height;
	bool m_fullscreen;
	
	SDL_Surface * screen;
	SDL_Event event;
	
	State * m_state;
	
	void resetGL();
	void handleAllEvents();
	
};