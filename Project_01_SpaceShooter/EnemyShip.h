#pragma once
#ifndef _ENEMY_SHIP_H_
#define _ENEMY_SHIP_H_

#include "Entity.h"
#include "IRenderable.h"

class EnemyProjectile;
class Circle;

class EnemyShip : public Entity, public IRenderable
{
private:
	std::list<EnemyProjectile*> enemyProjectiles;
	json::JSON enemyProjectileData;

public:

	EnemyShip() = default;
	~EnemyShip() override = default;

	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON& _json);
};
#endif // !_ENEMY_SHIP_H_



