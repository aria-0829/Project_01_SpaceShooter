#include "Renderer.h"
#include "AssetManager.h"
#include "Game.h"

Renderer* Renderer::instance = nullptr;

void Renderer::Initialize()
{
	//Create window and renderer
	window = SDL_CreateWindow("Space Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreen);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	background1->Initialize(0);
	background2->Initialize(-height);
	player->Initialize();
	//asteroidSpawner->Initialize();
	//enemySpawner->Initialize();

	std::cout << "Renderer Initialized" << std::endl;
}

void Renderer::Update()
{
	int FPS = 60;
	int frameDelay = 1000 / FPS;
	Uint32 frameStart = SDL_GetTicks();
	int frameTime = SDL_GetTicks() - frameStart;

	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			Game::Instance().setGameRunning(false);
			Destroy();
		}
		else
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				Game::Instance().setGameRunning(false);

				std::cout << "Would you like to save?" << std::endl;
				std::cout << "Press 'K' to save the game progress or 'L' to load a file: " << std::endl;
				switch (event.key.keysym.sym)
				{
				case SDLK_k:
					std::cout << "Game progress saving" << std::endl;
					break;
				case SDLK_l:
					std::cout << "Game progress loading" << std::endl;
					break;
				}
			}
		}
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	background1->Update();
	background1->Render();
	background2->Update();
	background2->Render();

	asteroidSpawner->Update();

	player->Update();
	player->Render();

	enemySpawner->Update();

	SDL_RenderPresent(renderer);
}

void Renderer::Destroy()
{
	//Destroy enemySpawner
	enemySpawner->Destroy();
	delete enemySpawner;

	//Destroy player
	player->Destroy();
	delete player;

	//Destroy window and renderer
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Renderer Destroyed" << std::endl;
}

void Renderer::Load(json::JSON& _json)
{
	if (_json.hasKey("RenderSettings"))
	{
		json::JSON renderSettings = _json["RenderSettings"];

		if (renderSettings.hasKey("width"))
		{
			width = renderSettings["width"].ToInt();
		}

		if (renderSettings.hasKey("height"))
		{
			height = renderSettings["height"].ToInt();
		}

		if (renderSettings.hasKey("fullscreen"))
		{
			fullscreen = renderSettings["fullscreen"].ToBool();
		}
	}

	background1 = new Background();
	background1->Load(_json);
	background2 = new Background();
	background2->Load(_json);

	player = new Player();
	player->Load(_json);

	asteroidSpawner = new AsteroidSpawner();
	//asteroidSpawner->Load(_json);

	enemySpawner = new EnemySpawner();
	enemySpawner->Load(_json);

	ui = new UI();
	
	std::cout << "Renderer Loaded" << std::endl;
}

