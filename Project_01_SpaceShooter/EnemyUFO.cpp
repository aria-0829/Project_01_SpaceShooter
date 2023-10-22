#include "EnemyUFO.h"
#include "AssetManager.h"
#include "Renderer.h"

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

	//Enemy start positiom at random of left
	dstrect = { 0, 0, imageWidth, imageHeight };
	dstrect.y = rand() % (Renderer::Instance().GetHeight() - imageHeight * 2);

	//Generate a random initial direction (-1, 0, or 1)
	//1 means moving from left to right, -1 means moving from right to left
	int direction = rand() % 3 - 1;
	std::cout << "direction: " << direction << std::endl;
	//Don't move, randomly spawned in the window
	if (direction == 0)
	{
		dstrect.x = rand() % (Renderer::Instance().GetWidth() - imageWidth);
	}

	//Moving from left to right
	else if (direction == 1)
	{
		dstrect.x = -imageWidth;
	}

	//Moving from right to left
	else if (direction == -1)
	{
		dstrect.x = Renderer::Instance().GetWidth();
	}
}

void EnemyUFO::Update()
{
	if (direction == 1)
	{
		dstrect.x += speed;
	}
	else if (direction == -1)
	{
		dstrect.x -= speed;
	}

	/*if (dstrect.x > Renderer::Instance().GetWidth() || dstrect.x < -imageWidth)
	{
		direction *= -1;
	}*/

	collisionCircle = { dstrect.x, dstrect.y, dstrect.w / 2 }; //Update collision circle
}

void EnemyUFO::Destroy()
{
	std::cout << "EnemyUFO Destroyed" << std::endl;
}

void EnemyUFO::Render()
{
	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void EnemyUFO::Load(json::JSON& _json)
{
	if (_json.hasKey("EnemyUFO"))
	{
		json::JSON ufoData = _json["EnemyUFO"];

		if (ufoData.hasKey("speed"))
		{
			speed = ufoData["speed"].ToInt();  //Load speed
		}

		if (ufoData.hasKey("imagePath"))
		{
			imagePath = ufoData["imagePath"].ToString();  //Load image path
		}

		if (ufoData.hasKey("imageWidth"))
		{
			imageWidth = ufoData["imageWidth"].ToInt();  //Load image width
		}

		if (ufoData.hasKey("imageHeight"))
		{
			imageHeight = ufoData["imageHeight"].ToInt();  //Load image height
		}
	}

	std::cout << "EnemyUFO Loaded" << std::endl;
}
