/*
 *  Layer.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "Sprite.h"

#include <vector>
using namespace std;

class Layer
{
public:
	Layer();
	~Layer();
	
	void addChild(Sprite* sprite);
	vector<Sprite*> getChildren();
	
	void render();
	void update(Uint32 dt);

protected:
	vector<Sprite*> children;
};