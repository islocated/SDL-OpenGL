/*
 *  Animation.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Animation.h"

Animation::Animation()
: m_numFrames(0), m_currentFrame(0), m_frames(), m_frameDuration(0.0f), m_frameDt(0), m_loop(true)
{
	
}

Animation::Animation(int numFrames, int* frames, float duration, bool loop=true)
: m_numFrames(numFrames), m_currentFrame(0), m_frames(), m_frameDuration(duration), m_frameDt(0), m_loop(loop)
{
	for(int i = 0; i < numFrames; i++){
		m_frames.push_back(frames[i]);
	}
}

void Animation::update(Uint32 dt){
	m_frameDt += dt/1000.0f;
	if(m_frameDt > m_frameDuration/m_numFrames){
		//TODO:Should we reset our just decrease by m_frameDuration/m_numFrames
		m_frameDt = 0.0f;
		m_currentFrame++;
		
		if(m_currentFrame >= m_numFrames){
			m_currentFrame = m_loop ? 0 : m_numFrames - 1;
		}
	}
}

int Animation::getCurrentFrame(){
	return m_frames[m_currentFrame];
}

void Animation::reset(){
	m_frameDt = 0.0f;
	m_currentFrame = 0;
}