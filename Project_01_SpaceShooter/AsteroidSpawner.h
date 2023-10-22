#pragma once
#ifndef _ASTEROID_SPAWNER_H_
#define _ASTEROID_SPAWNER_H_

#include "Asteroid.h"
#include "SDL.h"
#include "SDL_image.h"
#include "json.hpp"
#include <fstream>
#include <list>

class AsteroidSpawner
{
private:
	std::list<Asteroid*> asteroids;
	json::JSON asteroidData;
	//int spawnRate = 0;
	//int spawnTimer = 0;

public:
	AsteroidSpawner();
	~AsteroidSpawner();

	//void Initialize();
	void Update();
	void Destroy();
	void SpawnAsteroids();
	void AddAsteroid(Asteroid* _asteroid);
	void Load();
};

#endif // !_ASTEROID_SPAWNER_H_


