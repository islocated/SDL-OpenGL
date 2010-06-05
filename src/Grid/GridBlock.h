/*
 *  GridBlock.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
using namespace std;

class Sprite;

class GridBlock
{
public:
	GridBlock();
	
	void addItem(Sprite* sprite);
	
	int m_numOfItems;
	vector<Sprite*> m_items;
};