#pragma once
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "SDL.h"
#include "SDL_image.h"
#include "json.hpp"
#include <fstream>
#include <string>

class Background
{
private:
	int scrollSpeed = 0;
	std::string imagePath = "";
	SDL_Texture* tex;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

public:
	Background();
	~Background();

	void Initialize(int posY);
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
};


#endif // !_BACKGROUND_H_


