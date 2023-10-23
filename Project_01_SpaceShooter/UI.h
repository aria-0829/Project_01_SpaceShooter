#pragma once
#ifndef _UI_H_
#define _UI_H_

#include "json.hpp"
#include <fstream>
#include "SDL.h"

class UI
{
public:
	UI();
	~UI();

	void Initialize();
	void Destroy();
};
#endif // !_UI_H_