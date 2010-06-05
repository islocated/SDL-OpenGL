#include "Game.h"
#include "State.h"
#include "PlayState.h"
#include "Audio.h"
#include "Logger.h"

#include <iostream>
#include <errno.h>

int main(int argc, char* argv[])
{

//This def is defined from Project -> Edit Project Settings -> Preprocessor Macro: __mac__
#ifdef __mac__
	// make sure working directory is the same as the directory
	// that the app resides in
	// this is especially important on the mac platform, which
	// doesn't set a proper working directory for double-clicked
	// app bundles
	
	// arg 0 is the path to the app executable
	string path = argv[0];
	char spath[256];
	
	string parent = path.substr(0, path.find_last_of('/'));
	
	getcwd(spath,sizeof(spath));
	
	const char * dpath = path.c_str();
	
	int ret = chdir(parent.c_str());
	cout << strerror(errno);
	getcwd(spath,sizeof(spath));
	//string parent = path.substr(0, path.find_last_of('/', path.find_last_of('/')));
	
	
	chdir("..");
	getcwd(spath,sizeof(spath));
	
	//
	
	//char * parentPath = strrchr(executeablePath, '/');
	
	//if( parentPath != NULL ) {
		// terminate full app path to get parent directory
	//	parentPath[0] = '\0';
		
	//	chdir( parentPath );
	//}
	 
	 //delete [] path;
#endif
	
	
	
	Game g(1024, 640, false);
	
	State* state = new PlayState();
	
	//Game will delete the state
	g.setState(state);
	
	Logger::getInstance()->error() << "Current directory is: ";
	
	Audio::getInstance()->loadMusic("Resources/Epoq-Lepidoptera.ogg");
	Audio::getInstance()->playMusic(0);
	
	Audio::getInstance()->playSound("Resources/chicken.wav", 1);
	
	g.run();
	
	return 0;
}
	