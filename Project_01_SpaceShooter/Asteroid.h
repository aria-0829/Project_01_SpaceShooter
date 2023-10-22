#pragma once
#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include <string>
#include "json.hpp"
#include <fstream>
#include "SDL.h"

class Asteroid
{
private:
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

public:
	Asteroid();
	~Asteroid();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load();
	int GetPositionY() { return dstrect.y; }
};
#endif // !_ASTEROID_H_


