/*
 *  Audio.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Audio.h"
#include "Logger.h"

#include "SDL_Mixer/SDL_Mixer.h"

Audio * Audio::c_audio = NULL;

Audio * Audio::getInstance(){
	if(c_audio){
		return c_audio;
	}
	
	c_audio = new Audio();
	return c_audio;
}

Audio::Audio()
: m_music(NULL)
{
	int frequency = 22050;
	Uint16 format = AUDIO_S16; /* 16-bit stereo */
	int channels = 2;	//1 = mono, 2 = stereo
	int chunkSize = 4096;
	
	int error;
	if(error = Mix_OpenAudio(frequency, format, channels, chunkSize)){
		Logger::getInstance()->error("Unable to open Audio");
	}
	
	//Mix_QuerySpec(&frequency, &format, &channels);
}

Audio::~Audio()
{

}

void Audio::destroy(){
	Logger::getInstance()->debug("audio is destroyed");
	
	Mix_CloseAudio();
}

void Audio::update(){
	
}

void Audio::freeMusic(){
	if(m_music){
		Mix_FreeMusic(m_music);
		m_music = NULL;
	}
}

void Audio::loadMusic(char * file){
	freeMusic();
	m_music = Mix_LoadMUS(file);
}

void Audio::playMusic(int loops){
	Mix_PlayMusic(m_music, loops);
	Mix_HookMusicFinished(onMusicFinish);
}

void Audio::onMusicFinish(){
	Mix_HaltMusic();
	Mix_FreeMusic(getInstance()->m_music);
	getInstance()->m_music = NULL;
}

