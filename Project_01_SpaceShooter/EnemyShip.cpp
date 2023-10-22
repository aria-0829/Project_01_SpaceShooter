#include "EnemyShip.h".
#include "Renderer.h"
#include "AssetManager.h"
#include "SDL_image.h"

EnemyShip::EnemyShip()
{
	std::cout << "EnemyShip Created" << std::endl;
}

EnemyShip::~EnemyShip()
{
	std::cout << "EnemyShip Deleted" << std::endl;
}

void EnemyShip::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load enemy tex

	//Enemy start positiom at random of top
	int windowWidth = Renderer::Instance().GetWidth();
	dstrect = { moveX, moveY, imageWidth, imageHeight };
	dstrect.x = rand() % (windowWidth - imageWidth);
}

void EnemyShip::Update()
{
}

void EnemyShip::Destroy()
{
}

void EnemyShip::Load(json::JSON& _json)
{
	if (_json.hasKey("EnemyShip"))
	{
		json::JSON shipData = _json["EnemyShip"];

		if (shipData.hasKey("speed"))
		{
			speed = shipData["speed"].ToInt();  //Load speed
			std::cout << "Enemy Speed: " << speed << std::endl;
		}

		if (shipData.hasKey("imagePath"))
		{
			imagePath = shipData["imagePath"].ToString();  //Load image path
			std::cout << "Enemy Image Path: " << imagePath << std::endl;
		}

		if (shipData.hasKey("imageWidth"))
		{
			imageWidth = shipData["imageWidth"].ToInt();  //Load image width
			std::cout << "Enemy Image Width: " << imageWidth << std::endl;
		}

		if (shipData.hasKey("imageHeight"))
		{
			imageHeight = shipData["imageHeight"].ToInt();  //Load image height
			std::cout << "Enemy Image Height: " << imageHeight << std::endl;
		}
	}

	std::cout << "EnemyShip Load Complete." << std::endl << std::endl;
}
