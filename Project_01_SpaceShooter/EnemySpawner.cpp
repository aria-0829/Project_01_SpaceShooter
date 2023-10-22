#include "EnemySpawner.h"
#include "Renderer.h"

EnemySpawner::EnemySpawner()
{
	std::cout << "Enemy Spawner Created" << std::endl;
}

EnemySpawner::~EnemySpawner()
{
	std::cout << "Enemy Spawner Deleted" << std::endl;
}

void EnemySpawner::Update()
{
	SpawnEnemies();

	ships.remove_if([](EnemyShip* ship)
		{
			ship->Update();
			ship->Render();

			//Check if the ship is out of the window
			if (ship->GetPositionY() > Renderer::Instance().GetHeight())
			{
				ship->Destroy();
				delete ship;
				return true; //Remove the ship
			}
			return false; //Keep the ship
		});
	for (auto& ufo : ufos)
	{
		ufo->Update();
		ufo->Render();
	}
	

	//ufos.remove_if([](EnemyUFO* ufo)
	//	{
	//		ufo->Update();
	//		ufo->Render();

	//		//Check if the ufo is out of the window
	//		if (ufo->GetPositionY() > Renderer::Instance().GetHeight())
	//		{
	//			ufo->Destroy();
	//			delete ufo;
	//			return true; //Remove the ufo
	//		}
	//		return false; //Keep the ufo
	//	});
}

void EnemySpawner::SpawnEnemies()
{
	static int frameCount = 0;
	const int spawnInterval = 50;

	if (frameCount % spawnInterval == 0) 
	{
		// Spawn enemyShip
		EnemyShip* ship = new EnemyShip();
		AddShip(ship);
		ship->Load(enemiesData);
		ship->Initialize();

		// Spawn enemyUFO
		EnemyUFO* ufo = new EnemyUFO();
		AddUFO(ufo);
		ufo->Load(enemiesData);
		ufo->Initialize();
	}

	++frameCount;
}


void EnemySpawner::Destroy()
{
	for (auto& ship : ships)
	{
		ship->Destroy();
		delete ship;
	}
	ships.clear();

	for (auto& ufo : ufos)
	{
		ufo->Destroy();
		delete ufo;
	}
	ufos.clear();

}

void EnemySpawner::AddShip(EnemyShip* _enemy)
{
	ships.push_back(_enemy);
}

void EnemySpawner::AddUFO(EnemyUFO* _enemy)
{
	ufos.push_back(_enemy);
}

void EnemySpawner::Load()
{
	std::ifstream inputStream("Data/Enemies.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	if (documentData.hasKey("Enemies"))
	{
		enemiesData = documentData["Enemies"];
	}
}

