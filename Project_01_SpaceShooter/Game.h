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
	AssetManager* assetManager = nullptr;
	Renderer* renderer = nullptr;
	bool isRunning = true;

public:
	Game();
	~Game();

	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON& _json);
	void Save();
};
#endif // !_Game_H_



