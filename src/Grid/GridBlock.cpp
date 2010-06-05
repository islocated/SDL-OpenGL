/*
 *  GridBlock.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "GridBlock.h"

GridBlock::GridBlock()
: m_numOfItems(0), m_items()
{
	
}

void GridBlock::addItem(Sprite* sprite){
	Sprite* spr;
	for(vector<Sprite*>::iterator it = m_items.begin(); it != m_items.end(); ++it){
		spr = *it;
		if(spr == sprite){
			return;
		}
	}
	m_items.push_back(sprite);
}