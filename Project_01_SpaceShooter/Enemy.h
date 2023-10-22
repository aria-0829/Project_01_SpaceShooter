#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <string>
#include "json.hpp"
#include <fstream>
#include "SDL.h"

class Enemy
{
private:
	int speed = 0;
	int moveX = 0;
	int moveY = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

public:
	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	int GetPositionY() { return dstrect.y; }

};
#endif // !_ENEMY_H_


