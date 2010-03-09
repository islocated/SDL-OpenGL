/*
 *  Audio.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "SDL_Mixer/SDL_Mixer.h"

class Audio
{
public:
	static Audio * getInstance();
	
	void freeMusic();
	void loadMusic(char * file);
	void playMusic(int loops);
	
	virtual void update();
	virtual void destroy();
	
private:
	Audio();
	~Audio();
	
	static Audio * c_audio;
	
	Mix_Music * m_music;
};