#include "EnemyShip.h".
#include "Renderer.h"
#include "AssetManager.h"

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
	dstrect = { 0, -imageHeight, imageWidth, imageHeight };
	dstrect.x = rand() % (windowWidth - imageWidth);
}

void EnemyShip::Update()
{
	dstrect.y += speed;

	static int frameCount = 0;
	const int spawnInterval = 10;

	if (frameCount % spawnInterval == 0)
	{
		EnemyProjectile* projectile = new EnemyProjectile();
		enemyProjectiles.push_back(projectile);
		projectile->Load();
		projectile->Initialize((dstrect.x + imageWidth / 2), dstrect.y + imageHeight);
	}

	++frameCount;

	enemyProjectiles.remove_if([](EnemyProjectile* projectile)
		{
			projectile->Update();
			projectile->Render();

			//Check if the projectile is out of the window
			if (projectile->GetPositionY() < 0)
			{
				projectile->Destroy();
				delete projectile;
				return true; //Remove the projectile
			}
			return false; //Keep the projectile
		});
}

void EnemyShip::Destroy()
{
	for (auto projectile : enemyProjectiles)
	{
		projectile->Destroy();
		delete projectile;
		projectile = nullptr; //?
	}
	enemyProjectiles.clear();

	std::cout << "EnemyShip Destroyed" << std::endl;
}

void EnemyShip::Render()
{
	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void EnemyShip::Load(json::JSON& _json)
{
	if (_json.hasKey("EnemyShip"))
	{
		json::JSON shipData = _json["EnemyShip"];

		if (shipData.hasKey("speed"))
		{
			speed = shipData["speed"].ToInt();  //Load speed
		}

		if (shipData.hasKey("imagePath"))
		{
			imagePath = shipData["imagePath"].ToString();  //Load image path
		}

		if (shipData.hasKey("imageWidth"))
		{
			imageWidth = shipData["imageWidth"].ToInt();  //Load image width
		}

		if (shipData.hasKey("imageHeight"))
		{
			imageHeight = shipData["imageHeight"].ToInt();  //Load image height
		}
	}

	std::cout << "EnemyShip Loaded" << std::endl;
}
