#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

#include "UI.h"
#include "SDL.h"
#include "SDL_image.h"
#include "json.hpp"
#include <fstream>
#include <list>

class Renderer
{
private:
	static Renderer* instance;

	int width = 0;
	int height = 0;
	bool fullscreen = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	UI* ui = nullptr;
	Player* player = nullptr;
	std::list<Enemy*> enemies;
	std::list<Projectile*> projectiles;

	inline explicit Renderer() = default;
	inline ~Renderer() = default;
	inline explicit Renderer(Renderer const&) = delete;
	inline Renderer& operator=(Renderer const&) = delete;

public:
	static Renderer& Instance()
	{
		if (instance == nullptr)
		{
			instance = new Renderer();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	SDL_Renderer* GetRenderer() { return renderer; }
};

#endif // !_RENDERER_H_



