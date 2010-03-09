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
	debug("logger is destroyed");
	
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

void Logger::debug(char * s){
	file << "DEBUG " << s << endl;
}

void Logger::info(char * s){
	file << "INFO  " << s << endl;
}

void Logger::warn(char * s){
	file << "WARN  " << s << endl;
}

void Logger::error(char * s){
	file << "ERROR " << s << endl;
}