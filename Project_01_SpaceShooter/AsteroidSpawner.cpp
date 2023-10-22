#include "AsteroidSpawner.h"
#include "Renderer.h"

AsteroidSpawner::AsteroidSpawner()
{
	std::cout << "Asteroid Spawner Created" << std::endl;
}

AsteroidSpawner::~AsteroidSpawner()
{
	std::cout << "Asteroid Spawner Deleted" << std::endl;
}

void AsteroidSpawner::Update()
{
	SpawnAsteroids();

	asteroids.remove_if([](Asteroid* asteroid) 
	{
		asteroid->Update();
		asteroid->Render();

		//Check if the asteroid is out of the window
		if (asteroid->GetPositionY() > Renderer::Instance().GetHeight()) 
		{
			asteroid->Destroy();
			delete asteroid;
			return true; //Remove the asteroid
		}
		return false; //Keep the asteroid
	});
}

void AsteroidSpawner::Destroy()
{
	//Destroy asteroids
	for (auto asteroid : asteroids)
	{
		asteroid->Destroy();
		delete asteroid;
	}
	asteroids.clear();

	std::cout << "Asteroid Spawner Destroyed" << std::endl;
}

void AsteroidSpawner::SpawnAsteroids()
{
	static int frameCount = 0;
	const int spawnInterval = 60;

	if (frameCount % spawnInterval == 0)
	{
		Asteroid* asteroid = new Asteroid();
		AddAsteroid(asteroid);
		asteroid->Load();
		asteroid->Initialize();
	}

	++frameCount;
}

void AsteroidSpawner::AddAsteroid(Asteroid* _asteroid)
{
	asteroids.push_back(_asteroid);
}

