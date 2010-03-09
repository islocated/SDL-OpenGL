#include "Game.h"
#include "State.h"
#include "PlayState.h"

void drawFrame();

int main(int argc, char *argv[])
{
	Game g(1024, 640, false);
	
	State * state = new PlayState();
	
	//Game will delete the state
	g.setState(state);
	
	g.run();
	
	return 0;
}
	