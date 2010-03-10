#include "Game.h"
#include "State.h"
#include "PlayState.h"
#include "Audio.h"

int main(int argc, char *argv[])
{
	Game g(1024, 640, false);
	
	State * state = new PlayState();
	
	//Game will delete the state
	g.setState(state);
	
	Audio::getInstance()->loadMusic("Epoq-Lepidoptera.ogg");
	Audio::getInstance()->playMusic(0);
	
	Audio::getInstance()->playSound("chicken.wav", 1);
	
	g.run();
	
	return 0;
}
	