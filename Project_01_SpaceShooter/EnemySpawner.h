#pragma once
#ifndef _ENEMY_SPAWNER_H_
#define _ENEMY_SPAWNER_H_

class EnemyUFO;
class EnemyShip;

class EnemySpawner
{
private:
	std::list<EnemyUFO*> ufos;
	std::list<EnemyShip*> ships;
	json::JSON enemiesData;

public:
	EnemySpawner();
	~EnemySpawner();

	void Update();
	void Destroy();
	void SpawnEnemies();
	void Load(json::JSON& _json);
	void AddShip(EnemyShip* _enemy) { ships.push_back(_enemy); }
	void RemoveShip(EnemyShip* _enemy) { ships.remove(_enemy); }
	void AddUFO(EnemyUFO* _enemy) { ufos.push_back(_enemy); }
	void RemoveUFO(EnemyUFO* _enemy) { ufos.remove(_enemy); }
	std::list<EnemyUFO*> GetUFOs() { return ufos; }
	std::list<EnemyShip*> GetShips() { return ships; }
};

#endif // !_ENEMY_SPAWNER_H_


