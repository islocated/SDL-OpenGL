/*
 *  Image.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "SDL_opengl.h"

//Forward declarations
class SDL_Surface;

class Image
{
public:
	Image();
	virtual ~Image();
	
	int loadFile(char * filename);
	void render();
	void render(int frame, int type, int facing, float width, float height);

private:
	void destroy();
	void createTexture();
	
	Uint8 getBPP();
	int getWidth();
	int getHeight();
	
private:
	SDL_Surface *surface;
	
	GLuint texture;
	GLenum texture_format;
	GLint  nOfColors;
};