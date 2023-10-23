#pragma once
#ifndef _STAR_H_
#define _STAR_H_

#include <string>
#include "json.hpp"
#include <fstream>
#include "SDL.h"

class Star
{
private:
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

public:
	Star();
	~Star();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	int GetPositionY() { return dstrect.y; }
};


#endif // !_STAR_H_


