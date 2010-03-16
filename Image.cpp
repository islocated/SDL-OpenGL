/*
 *  Image.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/8/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Image.h"
#include "Logger.h"

#include "SDL.h"
#include "SDL_image/SDL_Image.h"

Image::Image()
: surface(NULL), texture(NULL)
{
}

Image::~Image(){
	Logger::getInstance()->debug() << "image is destroyed";
	
	destroy();
}

void Image::destroy(){
	if(surface){
		SDL_FreeSurface(surface);
		surface = NULL;
	}
	
	if(texture){
		glDeleteTextures(1, &texture);
		texture = NULL;
	}
}

int Image::loadFile(char* filename){
	destroy();
	
	surface = IMG_Load(filename);
	
	if(surface){
		createTexture();
	}
	
	return surface != NULL;
}

inline Uint8 Image::getBPP(){
	if(surface){
		return surface->format->BytesPerPixel;
	}
	
	return 0;
}

inline int Image::getWidth(){
	if(surface){
		return surface->w;
	}
	
	return 0;
} 

inline int Image::getHeight(){
	if(surface){
		return surface->h;
	}
	
	return 0;
}

void Image::createTexture(){
	nOfColors = surface->format->BytesPerPixel;
	if (nOfColors == 4)     // contains an alpha channel
	{
		if (surface->format->Rmask == 0x000000ff)
			texture_format = GL_RGBA;
		else
			texture_format = GL_BGRA;
	} else if (nOfColors == 3)     // no alpha channel
	{
		if (surface->format->Rmask == 0x000000ff)
			texture_format = GL_RGB;
		else
			texture_format = GL_BGR;
	} else {
		Logger::getInstance()->warn() << "warning: the image is not truecolor..  this will probably break";
	}
	
	// Have OpenGL generate a texture object handle for us
	glGenTextures(1, &texture);
	
	// Bind the texture object
	glBindTexture(GL_TEXTURE_2D, texture);
	
	// Set the texture's stretching properties
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	// Edit the texture object's image data using the information SDL_Surface gives us
	glTexImage2D(GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
				 texture_format, GL_UNSIGNED_BYTE, surface->pixels);
}

void Image::render(){
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glBegin(GL_QUADS);
	
	glTexCoord2i(0, 0); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2i(1, 0); glVertex3f(surface->w, 0.0f, 0.f);
	glTexCoord2i(1, 1); glVertex3f(surface->w, surface->h, 0.f);
	glTexCoord2i(0, 1); glVertex3f(0.0f, surface->h, 0.f);

	glEnd();
}

//TODO: We need to figure out a way to render the same textures together
//The idea is to have all the sprites render, which only marks that it should
//And then the textures will render based on texture types
void Image::render(int frame, int type, int facing, float width, float height){
	if(!surface){
		return;
	}
	
	int maxFrameNo = surface->w/width;
	if(frame >= maxFrameNo || frame < 0){
		return;
	}
	
	int maxTypeNo = surface->h/height;
	if(type >= maxTypeNo || type < 0){
		return;
	}
	
	float frameDivision = width/surface->w;
	float typeDivision = height/surface->h;
	
	float x = frameDivision * frame;
	float y = typeDivision * type;
	float x2 = x + frameDivision;
	float y2 = y + typeDivision;
	
	//Flips the horizontal thus reversing the image
	if(facing){
		x = x2;
		x2 = frameDivision * frame;
	}
	
	//TODO: This is expensive, need to draw all objects of same texture first
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glBegin(GL_QUADS);

	//Texture maps based on frame, vertex maps based on dimension of sprite
	glTexCoord2f(x, y); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(x2, y); glVertex3f(width, 0.0f, 0.f);
	glTexCoord2f(x2, y2); glVertex3f(width, height, 0.f);
	glTexCoord2f(x, y2); glVertex3f(0.0f, height, 0.f);
	
	glEnd();
}