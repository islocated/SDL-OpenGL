/*
 *  Logger.cpp
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Logger.h"

Logger * Logger::c_logger = NULL;

Logger::Logger()
: file("logfile.txt") //, ios::app)
{
	
}

Logger::~Logger(){
	
}

void Logger::destroy(){
	debug() << "logger is destroyed";
	
	file << flush;
	file.close();
}

Logger * Logger::getInstance(){
	if(c_logger){
		return c_logger;
	}
	
	c_logger = new Logger();
	return c_logger;
}

ofstream& Logger::debug(){
	file << endl << "DEBUG ";
	return file;
}

ofstream& Logger::info(){
	file << endl << "INFO  ";
	return file;
}

ofstream& Logger::warn(){
	file << endl << "WARN  ";
	return file;
}

ofstream& Logger::error(){
	file << endl << "ERROR ";
	return file;
}