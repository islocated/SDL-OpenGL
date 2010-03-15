/*
 *  Audio.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include <map>
using namespace std;

//Forward declaration
typedef struct _Mix_Music Mix_Music;
struct Mix_Chunk;

class Audio
{
public:
	static Audio* getInstance();
	static void onMusicFinish();
	
	void freeMusic();
	void loadMusic(char * file);
	void playMusic(int loops);
	void playSound(char * file, int loops);
	
	virtual void update(Uint32 dt);
	virtual void destroy();
	
private:
	Audio();
	~Audio();
	
	static Audio* c_audio;
	
	Mix_Music* m_music;
	
	map<char *, Mix_Chunk*> m_sounds;
};