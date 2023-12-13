#include "GameCore.h"

EnemyProjectile::EnemyProjectile()
{
	//std::cout << "EnemyProjectile Created" << std::endl;
}

EnemyProjectile::~EnemyProjectile()
{
	//std::cout << "EnemyProjectile Deleted" << std::endl;
}

void EnemyProjectile::Initialize(int posX, int posY)
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	dstrect = { posX, posY, imageWidth, imageHeight };
}

void EnemyProjectile::Update()
{
	dstrect.y += speed;

	collisionCircle = { dstrect.x, dstrect.y, dstrect.h / 2 }; //Update collision circle
}

void EnemyProjectile::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void EnemyProjectile::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void EnemyProjectile::Load(json::JSON& _json)
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
}
