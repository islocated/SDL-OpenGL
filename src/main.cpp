#include "Game.h"
#include "State.h"
#include "PlayState.h"
#include "Audio.h"
#include "Logger.h"

#include <iostream>
#include <errno.h>

void setCurrentDirectory(char * argv[]){
#ifdef __mac__
	//This def is defined from Project -> Edit Project Settings -> Preprocessor Macro: __mac__

	//executable path is passed in but we need to get to the Contents path
	string path = argv[0];
	
	string parent = path.substr(0, path.find_last_of('/'));
	
	//This is how we display the current working directory
	//char spath[256];
	//getcwd(spath,sizeof(spath));
	
	//We need to change to the executable path, then back up to the parent directory
	int ret = chdir(parent.c_str());
	if(ret == -1){
		cout << strerror(errno);
	}
	
	//Backup to the parent directory
	chdir("..");
#endif
}

int main(int argc, char* argv[])
{
	setCurrentDirectory(argv);

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
	