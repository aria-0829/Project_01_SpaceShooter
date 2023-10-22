#include "Asteroid.h"
#include "AssetManager.h"
#include "Renderer.h"
#include "CollisionDetection.h"
#include <random>

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
	dstrect.y += speed; //Move down

	collisionCircle = { dstrect.x, dstrect.y, dstrect.w / 2 }; //Update collision circle
}

void Asteroid::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
	std::cout << "Asteroid Destroyed" << std::endl;
}

void Asteroid::Render()
{
	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Asteroid::Load(json::JSON& _json)
{
	if (_json.hasKey("speed"))
	{
		speed = _json["speed"].ToInt();  //Load speed
	}

	if (_json.hasKey("imagePath"))
	{
		imagePath = _json["imagePath"].ToString();  //Load image path
	}

	if (_json.hasKey("imageWidth"))
	{
		imageWidth = _json["imageWidth"].ToInt();  //Load image width
	}

	if (_json.hasKey("imageHeight"))
	{
		imageHeight = _json["imageHeight"].ToInt();  //Load image height
	}
	
	std::cout << "Asteroid Loaded" << std::endl;
}
