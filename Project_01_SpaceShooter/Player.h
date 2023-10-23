#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Projectile.h"
#include <string>
#include "json.hpp"
#include <fstream>
#include "SDL.h"
#include "SDL_image.h"
#include <list>
#include "Circle.h"

class Player
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
	Circle collisionCircle = { 0, 0, 0 };;

public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	void Shoot();
	void AddProjectile(Projectile* _projectile);
	Circle GetCollisionCircle() { return collisionCircle; }
	std::list<Projectile*> GetProjectiles() { return projectiles; }
	void Damaged();
};
#endif // !_PLAYER_H_


