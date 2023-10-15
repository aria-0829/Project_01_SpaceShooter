#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
	//Load GameSettings.json
	std::ifstream inputStream("GameSettings.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	//Load(documentData);
	//assetManager = new AssetManager();
	//assetManager->LoadJSON(documentData);
	renderer = new Renderer();
	renderer->Load(documentData);
	renderer->Initialize();

	std::cout << "Game Initialized" << std::endl << std::endl;
}

void Game::Destroy()
{
}

void Game::Update()
{
	while (isRunning)
	{
		renderer->Update();
	}
}

void Game::Load(json::JSON& _json)
{
	

	std::cout << "Game Data Load Complete" << std::endl << std::endl;
}

void Game::Save()
{
	std::cout << "Game Saving..." << std::endl << std::endl;


	std::cout << "Game Save Complete" << std::endl << std::endl;
}
