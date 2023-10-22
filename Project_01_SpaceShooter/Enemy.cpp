#include "Enemy.h"
#include "Renderer.h"
#include "AssetManager.h"
#include "GameTime.h"
#include "SDL_image.h"

Enemy::Enemy()
{
	std::cout << "Enemy Created" << std::endl;
}

Enemy::~Enemy()
{
	std::cout << "Enemy Deleted" << std::endl;
}

void Enemy::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load enemy tex
	
	//Enemy start positiom at random of top
	int windowWidth = Renderer::Instance().GetWidth();
	dstrect = { moveX, moveY, imageWidth, imageHeight };
	dstrect.x = rand() % (windowWidth - imageWidth);
	
	std::cout << "Enemy Initialized" << std::endl;
}

void Enemy::Update()
{
	dstrect.y += speed;

	
	/*int windowHeight = Renderer::Instance().GetHeight();
	while (dstrect.y <= windowHeight)
	{
		dstrect.y += speed;
	}*/

	/*if (dstrect.y > windowHeight)
	{
		Destroy();
		new Enemy();
	}*/

}

void Enemy::Destroy()
{
	SDL_DestroyTexture(tex);

	std::cout << "Enemy Destroyed" << std::endl;
}

void Enemy::Render()
{
	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect); 
}

