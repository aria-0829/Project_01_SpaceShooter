#pragma once
#ifndef _ENEMY_SHIP_H_
#define _ENEMY_SHIP_H_

#include "Enemy.h"

class EnemyShip : public Enemy
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
	EnemyShip();
	~EnemyShip();

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
};
#endif // !_ENEMY_SHIP_H_



