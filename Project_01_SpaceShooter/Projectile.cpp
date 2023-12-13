#include "GameCore.h"

Projectile::Projectile()
{
	//std::cout << "Projectile Created" << std::endl;
}

Projectile::~Projectile()
{
	//std::cout << "Projectile Deleted" << std::endl;
}

void Projectile::Initialize(int posX, int posY)
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	dstrect = { posX, posY, imageWidth, imageHeight };
}

void Projectile::Update()
{
	dstrect.y -= speed;

	collisionCircle = { dstrect.x, dstrect.y, dstrect.h / 2 }; //Update collision circle
}

void Projectile::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void Projectile::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Projectile::Load(json::JSON& _json)
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
