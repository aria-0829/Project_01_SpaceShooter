#pragma once
#ifndef _Game_H_
#define _Game_H_

#include "Renderer.h"
#include "AssetManager.h"
#include "json.hpp"
#include <fstream>

class Game
{
private:
	static Game* instance;

	bool isRunning = true;

	inline explicit Game() = default;
	inline ~Game() = default;
	inline explicit Game(Game const&) = delete;
	inline Game& operator=(Game const&) = delete;

public:
	static Game& Instance()
	{
		if (instance == nullptr)
		{
			instance = new Game();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
	void Save();
	bool GameRunning() { return isRunning; }
	void setGameRunning(bool value) { isRunning = value; }
};
#endif // !_Game_H_



