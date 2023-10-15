#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

#include "SDL.h"
#include "json.hpp"
#include <fstream>
#include <list>

class Renderer
{
private:
	int width = 0;
	int height = 0;
	bool fullscreen = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Player* player = nullptr;
	std::list<Enemy*> enemies;
	std::list<Projectile*> projectiles;
	SDL_Texture* playerTex = nullptr;
	SDL_Rect playerDstrect = { 0, 0, 0, 0 };

public:
	Renderer();
	~Renderer();

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
	SDL_Texture* LoadTexture(const char* texturePath);
};

#endif // !_RENDERER_H_



