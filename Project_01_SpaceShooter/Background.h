#pragma once
#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "Entity.h"
#include "IRenderable.h"

class Background : public Entity, public IRenderable
{

public:
	Background() = default;
	~Background() override = default;

	void Initialize(int posY);
	void Update();
	void Load(json::JSON& _json);
};

#endif // !_BACKGROUND_H_
