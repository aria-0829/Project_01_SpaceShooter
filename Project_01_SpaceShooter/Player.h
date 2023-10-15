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
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";

public:
	Player();
	~Player();

	void Destroy();
	void Update(SDL_Event event);
	void Shoot();
	SDL_Rect GetPosition();
	void Load(json::JSON& _json);
};
#endif // !_PLAYER_H_


