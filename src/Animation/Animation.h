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
	Animation(int numFrames, int* frames, int row, float duration, bool loop=true);
	
	void update(Uint32 dt);
	int getCurrentFrame();
	int getRow();
	void reset();

private:
	vector<int> m_frames;
	int m_numFrames;
	int m_currentFrame;
	float m_frameDuration;
	float m_frameDt;
	
	int m_row;
	
	bool m_loop;
};