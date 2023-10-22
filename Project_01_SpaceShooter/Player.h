#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "json.hpp"
#include <fstream>
#include "SDL.h"

class Player
{
private:
	int lives = 0;
	int speed = 0;
	int moveX = 0;
	int moveY = 0;
	int windowWidth = 0;
	int windowHeight = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	void Shoot();
	//SDL_Rect GetPosition();
	//char* GetImagePath();
};
#endif // !_PLAYER_H_


