#include "Renderer.h"
#include "AssetManager.h"
#include "Game.h"

Renderer* Renderer::instance = nullptr;

void Renderer::Initialize()
{
	//Create window and renderer
	window = SDL_CreateWindow("Space Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreen);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	player->Initialize();

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
				std::cout << "Would you like to save?" << std::endl;
				std::cout << "Press 'S' to save the game progress or 'L' to load a file: " << std::endl;
				if (event.key.keysym.sym == SDLK_s)
				{
					std::cout << "Game progress saving" << std::endl;
				}
				else if (event.key.keysym.sym == SDLK_l)
				{
					std::cout << "Game progress loading" << std::endl;
				}
			}
		}
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	player->Update();

	player->Render();

	SDL_RenderPresent(renderer);
}

void Renderer::Destroy()
{
	player->Destroy();
	delete player;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Renderer Destroyed" << std::endl;
}

void Renderer::Load(json::JSON& _json)
{
	player = new Player();
	player->Load(_json);

	ui = new UI();

	if (_json.hasKey("RenderSettings"))
	{
		json::JSON renderSettings = _json["RenderSettings"];

		if (renderSettings.hasKey("width"))
		{
			width = renderSettings["width"].ToInt();
			std::cout << "width: " << width << std::endl;
		}

		if (renderSettings.hasKey("height"))
		{
			height = renderSettings["height"].ToInt();
			std::cout << "height: " << height << std::endl;
		}

		if (renderSettings.hasKey("fullscreen"))
		{
			fullscreen = renderSettings["fullscreen"].ToBool();
			std::cout << "fullscreen: " << fullscreen << std::endl;
		}
	}
	std::cout << "Renderer Loaded" << std::endl;
}





