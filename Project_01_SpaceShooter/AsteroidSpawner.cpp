#include "AsteroidSpawner.h"
#include "Renderer.h"
#include "CollisionDetection.h"
#include "Circle.h"

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

	//Update and render asteroids, destroy when necessary
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

		//Get the collision circles
		Circle asteroidCollider = asteroid->GetCollisionCircle();
		Circle playerCollider = Renderer::Instance().GetPlayer()->GetCollisionCircle();

		//Check if the asteroid collides with the player
		if (CollisionDetection::Instance().CheckCollision(playerCollider, asteroidCollider))
		{
			Renderer::Instance().GetPlayer()->Damaged();
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
	const int spawnInterval = 80;

	if (frameCount % spawnInterval == 0)
	{
		Asteroid* asteroid = new Asteroid();
		AddAsteroid(asteroid);
		asteroid->Load(asteroidData);
		asteroid->Initialize();
	}

	++frameCount;
}

void AsteroidSpawner::AddAsteroid(Asteroid* _asteroid)
{
	asteroids.push_back(_asteroid);
}

void AsteroidSpawner::Load()
{
	std::ifstream inputStream("Data/Asteroid.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	if (documentData.hasKey("Asteroid"))
	{
		asteroidData = documentData["Asteroid"];
	}
}

