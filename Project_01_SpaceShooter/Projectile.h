#pragma once
#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

class Projectile
{
private:
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };
	Circle collisionCircle = { 0, 0, 0 };

public:
	Projectile();
	~Projectile();

	void Initialize(int posX, int posY);
	void Update();
	void Destroy();
	void Render();
	void Load(json::JSON& _json);
	int GetPositionY() { return dstrect.y; }
	Circle GetCollisionCircle() { return collisionCircle; }
};

#endif // !_PROJECTILE_H_

