#include "Renderer.h"

Renderer::Renderer()
{
	std::cout << "Renderer Created" << std::endl;
}

Renderer::~Renderer()
{
	std::cout << "Renderer Deleted" << std::endl;
}

void Renderer::Initialize()
{
	//Create window and renderer
	window = SDL_CreateWindow("Space Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreen);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	playerTex = LoadTexture(player->GetImagePath());

	//player = new Player(renderer, texture);
	
	playerDstrect = { width / 2, (height - 50), 0, 0 };  //Player starting position at the bottom middle of the screen

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
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)//SDL_WINDOWEVENT:
		{
			Destroy();
		}
		else //if(event.type = SDL_KEYDOWN)
		{
			player->Update(event);
		}
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_Rect playerMovement = player->GetPosition();  //Get the player movement from the player class
	playerDstrect = { (width / 2 + playerMovement.x), (height - 50 + playerMovement.y), playerMovement.w, playerMovement.h };  //Apply the player movement and the image size to the playerDstrect
	SDL_RenderCopy(renderer, playerTex, NULL, &playerDstrect);  //Render the player

	SDL_RenderPresent(renderer);
}

void Renderer::Destroy()
{
	SDL_DestroyTexture(playerTex);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	player->Destroy();
	delete player;
	std::cout << "Renderer Destroyed" << std::endl;
}

void Renderer::Load(json::JSON& _json)
{
	player = new Player();
	player->Load(_json);

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

SDL_Texture* Renderer::LoadTexture(const char* texturePath)  //Load a texture from a file path
{
	std::cout << "Loading TexturePath: " << texturePath << std::endl;
	SDL_Surface* tempSurface = IMG_Load(texturePath);
	if (!tempSurface) {
		std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return texture;
}



