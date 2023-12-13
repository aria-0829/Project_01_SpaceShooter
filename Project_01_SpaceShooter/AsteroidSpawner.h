#pragma once
#ifndef _ASTEROID_SPAWNER_H_
#define _ASTEROID_SPAWNER_H_

class Star;
class Asteroid;

class AsteroidSpawner
{
private:
	std::list<Asteroid*> asteroids;
	json::JSON asteroidData;
	std::list<Star*> stars;
	json::JSON starData;

public:
	AsteroidSpawner();
	~AsteroidSpawner();

	void Update();
	void Destroy();
	void SpawnAsteroids();
	void AddAsteroid(Asteroid* _asteroid);
	void SpawnStars();
	void Load(json::JSON& _json);
};

#endif // !_ASTEROID_SPAWNER_H_


