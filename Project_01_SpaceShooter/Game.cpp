#include "Game.h"
#include "GameTime.h"
#include "AssetManager.h"
#include <thread>

Game* Game::instance = nullptr;

void Game::Initialize()
{
	//Load GameSettings.json
	std::ifstream inputStream("GameSettings.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	//GameTime::Instance().Initialize();
	AssetManager::Instance().Initialize();
	Renderer::Instance().Load(documentData);
	Renderer::Instance().Initialize(); // This is the line that causes the error

	std::cout << "Game Initialized" << std::endl << std::endl;
}

void Game::Update()
{
	while (isRunning)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));

		GameTime::Instance().Update();
		Renderer::Instance().Update();

	}
}

void Game::Destroy()
{
	GameTime::Instance().Destroy();
	Renderer::Instance().Destroy();
	AssetManager::Instance().Destroy();
	if (instance != nullptr)
	{
		delete instance;
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
