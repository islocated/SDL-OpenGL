/*
 *  Logger.h
 *  SDL OpenGL
 *
 *  Created by Minh Nguyen on 3/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#include <fstream>
using namespace std;

class Logger
{
public:
	static Logger * getInstance();
	
	void destroy();
	void debug(const char * s);
	void info(const char * s);
	void warn(const char * s);
	void error(const char * s);
	
private:
	Logger();
	~Logger();
	ofstream file;
	
	static Logger * c_logger;
};