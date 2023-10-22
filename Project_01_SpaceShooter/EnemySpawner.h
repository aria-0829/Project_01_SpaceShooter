#pragma once
#ifndef _ENEMY_SPAWNER_H_
#define _ENEMY_SPAWNER_H_

#include "Enemy.h"
#include "EnemyUFO.h"
#include "EnemyShip.h"
#include "SDL.h"
#include "SDL_image.h"
#include "json.hpp"
#include <fstream>
#include <list>

class EnemySpawner
{
private:
	std::list<Enemy*> enemies;
	//std::list<EnemyUFO*> ufos;
	//std::list<EnemyShip*> ships;
	EnemyUFO* enemyUFO = nullptr;
	EnemyShip* enemyShip = nullptr;

	int spawnRate = 0;
	int spawnTimer = 0;
	int spawnX = 0;
	int spawnY = 0;
	int windowWidth = 0;
	int windowHeight = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

public:
	EnemySpawner();
	~EnemySpawner();

	void Initialize();
	void Update();
	void Destroy();
	void SpawnEnemies();
	void AddEnemy(Enemy* _enemy);
	void Load(json::JSON& _json);
};

#endif // !_ENEMY_SPAWNER_H_


