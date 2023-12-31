#pragma once
#ifndef _ENEMY_SHIP_H_
#define _ENEMY_SHIP_H_

#include "EnemyProjectile.h"
#include <string>
#include "json.hpp"
#include <fstream>
#include "SDL.h"
#include "SDL_image.h"
#include <list>
#include "Circle.h"

class EnemyShip
{
private:
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };
	std::list<EnemyProjectile*> enemyProjectiles;
	Circle collisionCircle = { 0, 0, 0 };

public:
	EnemyShip();
	~EnemyShip();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	int GetPositionY() { return dstrect.y; }
	Circle GetCollisionCircle() const { return collisionCircle; }
};
#endif // !_ENEMY_SHIP_H_



