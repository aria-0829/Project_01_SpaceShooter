#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->Initialize();
	game->Update();
	
	return 0;
}