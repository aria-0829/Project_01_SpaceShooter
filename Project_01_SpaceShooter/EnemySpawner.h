#pragma once
#ifndef _ENEMY_SPAWNER_H_
#define _ENEMY_SPAWNER_H_

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
	std::list<EnemyUFO*> ufos;
	std::list<EnemyShip*> ships;
	json::JSON enemiesData;

	/*int spawnRate = 0;
	int spawnTimer = 0;
	int windowWidth = 0;
	int windowHeight = 0;*/

public:
	EnemySpawner();
	~EnemySpawner();

	void Update();
	void Destroy();
	void SpawnEnemies();
	void AddShip(EnemyShip* _enemy);
	void AddUFO(EnemyUFO* _enemy);
	void Load();
};

#endif // !_ENEMY_SPAWNER_H_


