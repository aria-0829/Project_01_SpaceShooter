#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "IRenderable.h"

class Entity : public IRenderable
{
protected:
	int speed = 0;
	int imageWidth = 0;
	int imageHeight = 0;
	std::string imagePath = "";
	SDL_Texture* tex = nullptr;
	SDL_Rect dstrect = { 0, 0, 0, 0 };
	Circle collisionCircle = { 0, 0, 0 };

public:
	Entity() = default;
	virtual ~Entity() = default;

	virtual void Initialize(int posX, int posY);
	virtual void Update();
	virtual void Destroy();
	virtual void Render();
	virtual void Load(json::JSON& _json);
	int GetPositionY() { return dstrect.y; }
	Circle GetCollisionCircle() const { return collisionCircle; }
};

#endif // !_ENTITY_H_