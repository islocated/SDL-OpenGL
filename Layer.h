/*
 *  Layer.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Sprite.h"

#include <vector>
using namespace std;

class Layer
{
public:
	Layer();
	~Layer();
	
	void addChild(Sprite * sprite);
	void render();
	void update();

protected:
	vector<Sprite *> *children;
};