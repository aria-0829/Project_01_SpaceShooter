#pragma once
#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

class UI;
class Background;
class Player;
class EnemySpawner;
class AsteroidSpawner;

class RenderSystem
{
private:
	static RenderSystem* instance;

	int width = 0;
	int height = 0;
	bool fullscreen = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	UI* ui = nullptr;
	Background* background1 = nullptr;
	Background* background2 = nullptr;
	Player* player = nullptr;
	EnemySpawner* enemySpawner = nullptr;
	AsteroidSpawner* asteroidSpawner = nullptr;

	inline explicit RenderSystem() = default;
	inline ~RenderSystem() = default;
	inline explicit RenderSystem(RenderSystem const&) = delete;
	inline RenderSystem& operator=(RenderSystem const&) = delete;

public:
	static RenderSystem& Instance()
	{
		if (instance == nullptr)
		{
			instance = new RenderSystem();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	Player* GetPlayer() { return player; }
	void Destroy();
	void Load(json::JSON& _json);
	void CheckCollisions();
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	SDL_Renderer* GetRenderer() { return renderer; }
};

#endif // !_RENDERER_H_



