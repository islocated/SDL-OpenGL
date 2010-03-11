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
	
	ofstream& debug();
	ofstream& info();
	ofstream& warn();
	ofstream& error();
	
private:
	Logger();
	~Logger();
	ofstream file;
	
	static Logger * c_logger;
};