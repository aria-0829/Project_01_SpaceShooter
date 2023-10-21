#include "Game.h"

int main(int argc, char* argv[])
{
	Game::Instance().Initialize();
	Game::Instance().Update();
	Game::Instance().Destroy();
	
	return 0;
}