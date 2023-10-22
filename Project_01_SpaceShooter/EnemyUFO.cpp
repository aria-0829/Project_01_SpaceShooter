#include "EnemyUFO.h"
#include "AssetManager.h"
#include "SDL_image.h"

EnemyUFO::EnemyUFO()
{
	std::cout << "EnemyUFO Created" << std::endl;
}

EnemyUFO::~EnemyUFO()
{
	std::cout << "EnemyUFO Deleted" << std::endl;
}

void EnemyUFO::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load enemy tex
}

void EnemyUFO::Update()
{
}

void EnemyUFO::Destroy()
{
}

void EnemyUFO::Load(json::JSON& _json)
{
	if (_json.hasKey("EnemyUFO"))
	{
		json::JSON ufoData = _json["EnemyUFO"];

		if (ufoData.hasKey("speed"))
		{
			speed = ufoData["speed"].ToInt();  //Load speed
			std::cout << "Enemy Speed: " << speed << std::endl;
		}

		if (ufoData.hasKey("imagePath"))
		{
			imagePath = ufoData["imagePath"].ToString();  //Load image path
			std::cout << "Enemy Image Path: " << imagePath << std::endl;
		}

		if (ufoData.hasKey("imageWidth"))
		{
			imageWidth = ufoData["imageWidth"].ToInt();  //Load image width
			std::cout << "Enemy Image Width: " << imageWidth << std::endl;
		}

		if (ufoData.hasKey("imageHeight"))
		{
			imageHeight = ufoData["imageHeight"].ToInt();  //Load image height
			std::cout << "Enemy Image Height: " << imageHeight << std::endl;
		}
	}

	std::cout << "EnemyUFO Load Complete." << std::endl << std::endl;
}
