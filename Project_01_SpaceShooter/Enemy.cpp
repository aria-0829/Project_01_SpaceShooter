#include "Enemy.h"
#include "Renderer.h"
#include "AssetManager.h"
#include "GameTime.h"
#include "SDL_image.h"

Enemy::Enemy()
{
	std::cout << "Enemy Created" << std::endl;
}

void Enemy::Initialize()
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load enemy tex
}

void Enemy::Update()
{
	dstrect.y += speed;

}

void Enemy::Destroy()
{
	SDL_DestroyTexture(tex);
}

void Enemy::Render()
{
	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect); 
}

