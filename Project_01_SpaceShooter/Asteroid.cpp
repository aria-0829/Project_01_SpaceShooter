#include "Asteroid.h"
#include "AssetManager.h"
#include "Renderer.h"

Asteroid::Asteroid()
{
	std::cout << "Asteroid Created" << std::endl;
}

Asteroid::~Asteroid()
{
	std::cout << "Asteroid Deleted" << std::endl;
}

void Asteroid::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	int posX = rand() % Renderer::Instance().GetWidth();
	dstrect = { posX, -imageHeight, imageWidth, imageHeight };
}

void Asteroid::Update()
{
	dstrect.y += speed;
}

void Asteroid::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
	//CollisionSystem::Instance().UnregisterAsteroid(this);
	std::cout << "Asteroid Destroyed" << std::endl;
}

void Asteroid::Render()
{
	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Asteroid::Load()
{
	std::ifstream inputStream("Data/Asteroid.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	if (documentData.hasKey("Asteroid"))
	{
		json::JSON asteroidData = documentData["Asteroid"];

		if (asteroidData.hasKey("speed"))
		{
			speed = asteroidData["speed"].ToInt();  //Load speed
		}

		if (asteroidData.hasKey("imagePath"))
		{
			imagePath = asteroidData["imagePath"].ToString();  //Load image path
		}

		if (asteroidData.hasKey("imageWidth"))
		{
			imageWidth = asteroidData["imageWidth"].ToInt();  //Load image width
		}

		if (asteroidData.hasKey("imageHeight"))
		{
			imageHeight = asteroidData["imageHeight"].ToInt();  //Load image height
		}
	}
	
	std::cout << "Asteroid Loaded" << std::endl;
}
