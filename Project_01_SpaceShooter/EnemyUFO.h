#pragma once
#ifndef _ENEMY_UFO_H_
#define _ENEMY_UFO_H_

#include <string>
#include "json.hpp"
#include <fstream>
#include "SDL.h"
#include "SDL_image.h"
#include "Circle.h"

class EnemyUFO
{
private:
	int speed = 0;
	int direction = 0;
 	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };
	Circle collisionCircle = { 0, 0, 0 };

public:
	EnemyUFO();
	~EnemyUFO();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	int GetPositionY() { return dstrect.y; }
	Circle GetCollisionCircle() const { return collisionCircle; }
};

#endif // !_ENEMY_UFO_H_


