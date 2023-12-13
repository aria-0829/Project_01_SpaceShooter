#include "EngineCore.h"

void SceneManager::Initialize()
{
}

void SceneManager::Update()
{
}

void SceneManager::Destroy()
{
}

void SceneManager::Load(json::JSON& _json)
{
	if (_json.hasKey("SceneManager"))
	{
		json::JSON renderSettings = _json["SceneManager"];

		/*if (renderSettings.hasKey("width"))
		{
			width = renderSettings["width"].ToInt();
		}*/

	}
}
