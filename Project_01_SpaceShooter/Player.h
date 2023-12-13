#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

class Projectile;

class Player: public Entity
{
private:
	int lives = 0;
	int speed = 0;
	int moveX = 0;
	int moveY = 0;
	int windowWidth = 0;
	int windowHeight = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };

	std::list<Projectile*> projectiles;
	json::JSON projectileData;

	Circle collisionCircle = { 0, 0, 0 };;

public:
	Player() = default;
	~Player() override = default;

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	void Shoot();
	void Damaged();
	void AddProjectile(Projectile* _projectile) { projectiles.push_back(_projectile); }
	void RemoveProjectile(Projectile* projectile) { projectiles.remove(projectile); }
	Circle GetCollisionCircle() { return collisionCircle; }
	std::list<Projectile*> GetProjectiles() { return projectiles; }

};
#endif // !_PLAYER_H_


