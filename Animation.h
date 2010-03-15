/*
 *  Animation.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
using namespace std;

class Animation
{
public:
	Animation();
	Animation(int numFrames, int* frames, float duration, bool loop);
	
	void update(Uint32 dt);
	int getCurrentFrame();
	void reset();
	
	vector<int> m_frames;
	int m_numFrames;
	int m_currentFrame;
	float m_frameDuration;
	float m_frameDt;
	
	bool m_loop;
};