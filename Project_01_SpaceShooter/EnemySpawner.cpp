#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
{
	std::cout << "Enemy Spawner Created" << std::endl;
}

EnemySpawner::~EnemySpawner()
{
	std::cout << "Enemy Spawner Deleted" << std::endl;
}

void EnemySpawner::Initialize()
{
	

	enemyShip->Initialize();
	enemyUFO->Initialize();

	std::cout << "Renderer Initialized" << std::endl;
}

void EnemySpawner::Update()
{
	SpawnEnemies();

	for (auto& enemy : enemies)
	{
		enemy->Update();
		enemy->Render();

		// Check if the enemy is out of the window, if so, destroy it
		if (enemy->GetPositionY() > windowHeight)
		{
			enemy->Destroy();
			delete enemy;
			enemies.remove(enemy);
		}
	}
}

void EnemySpawner::SpawnEnemies()
{
	static int frameCount = 0;
	const int spawnInterval = 100;

	if (frameCount % spawnInterval == 0) 
	{
		// Spawn enemyShip
		Enemy* enemyShip = new EnemyShip();
		AddEnemy(enemyShip);

		// Spawn enemyUFO
		Enemy* enemyUFO = new EnemyUFO();
		AddEnemy(enemyUFO);
	}

	++frameCount;
}

void EnemySpawner::Destroy()
{
	for (auto& enemy : enemies)
	{
		enemy->Destroy();
		delete enemy;
	}
	enemies.clear();

	enemyUFO->Destroy();
	delete enemyUFO;
	enemyShip->Destroy();
	delete enemyShip;
}

void EnemySpawner::AddEnemy(Enemy* _enemy)
{
	enemies.push_back(_enemy);
}

void EnemySpawner::Load(json::JSON& _json)
{
	if (_json.hasKey("Enemies"))
	{
		json::JSON enemiesData = _json["Enemies"];

		EnemyShip* enemyShip = new EnemyShip();
		enemyShip->Load(enemiesData);
		EnemyUFO* enemyUFO = new EnemyUFO();
		enemyUFO->Load(enemiesData);
	}
	std::cout << "Enemy Spawner Loaded" << std::endl;

}
