#include "EngineCore.h"

void Entity::Initialize(int posX, int posY)
{
	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex

	dstrect = { posX, posY, imageWidth, imageHeight }; //Set position and size
}

void Entity::Update()
{
	collisionCircle = { dstrect.x, dstrect.y, dstrect.h / 2 }; //Update collision circle
}

void Entity::Destroy()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void Entity::Render()
{
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Entity::Load(json::JSON& _json)
{
}
