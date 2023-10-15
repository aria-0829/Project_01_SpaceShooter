#pragma once
#ifndef _UI_H_
#define _UI_H_
#include "json.hpp"
#include <fstream>

class UI
{
public:
	UI();
	~UI();

	void Initialize();
	void Destroy();
	void Load(json::JSON& _json);
};
#endif // !_UI_H_


