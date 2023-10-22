#include "Projectile.h"
#include "AssetManager.h"
#include "Renderer.h"

Projectile::Projectile()
{
	std::cout << "Projectile Created" << std::endl;
}

Projectile::~Projectile()
{
	std::cout << "Projectile Deleted" << std::endl;
}

void Projectile::Initialize(int posX, int posY)
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	dstrect = { posX, posY, imageWidth, imageHeight };
}

void Projectile::Update()
{
	dstrect.y -= speed;
}

void Projectile::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
	std::cout << "Projectile Destroyed" << std::endl;
}

void Projectile::Render()
{
	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Projectile::Load()
{
	std::ifstream inputStream("Projectile.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	if (documentData.hasKey("Projectile"))
	{
		json::JSON projectileData = documentData["Projectile"];

		if (projectileData.hasKey("speed"))
		{
			speed = projectileData["speed"].ToInt();  //Load speed
		}

		if (projectileData.hasKey("imagePath"))
		{
			imagePath = projectileData["imagePath"].ToString();  //Load image path
		}

		if (projectileData.hasKey("imageWidth"))
		{
			imageWidth = projectileData["imageWidth"].ToInt();  //Load image width
		}

		if (projectileData.hasKey("imageHeight"))
		{
			imageHeight = projectileData["imageHeight"].ToInt();  //Load image height
		}
	}
}
