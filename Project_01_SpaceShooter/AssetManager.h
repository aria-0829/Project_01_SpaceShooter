#pragma once
#ifndef _ASSET_MANAGER_H_
#define _ASSET_MANAGER_H_

#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "SDL.h"
#include "SDL_image.h"
#include "json.hpp"
#include <fstream>
#include <list>

class AssetManager
{
private:
	Player* player = nullptr;
	std::list<Enemy*> enemies;
	std::list<Projectile*> projectiles;

public:
	AssetManager();
	~AssetManager();

	void LoadJSON(json::JSON& _json);
	SDL_Texture* LoadTexture(const char* texturePath, SDL_Renderer* renderer);
	//void LoadFont(std::string name, std::string fileName);
};

#endif // !_ASSETMANAGER_H_


