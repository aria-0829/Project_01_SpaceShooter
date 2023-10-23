#include "Background.h"
#include "Renderer.h"
#include "AssetManager.h"

Background::Background()
{
	std::cout << "Background Created" << std::endl;
}

Background::~Background()
{
	std::cout << "Background Deleted" << std::endl;
}

void Background::Initialize(int posY)
{
	int windowWidth = Renderer::Instance().GetWidth();
	int windowHeight = Renderer::Instance().GetHeight();

	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	
	dstrect = { 0, posY, windowWidth, windowHeight }; //Background starting position

	std::cout << "Background Initialized" << std::endl;
}

void Background::Update()
{
	//Move back again when out of window
	dstrect.y += scrollSpeed;
	if (dstrect.y >= Renderer::Instance().GetHeight())
	{
		dstrect.y = -Renderer::Instance().GetHeight();
	}
}

void Background::Destroy()
{
	std::cout << "Background Destroyed" << std::endl;
}

void Background::Render()
{
	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect);
}

void Background::Load(json::JSON& _json)
{
	if (_json.hasKey("Background"))
	{
		json::JSON backgroundSettings = _json["Background"];

		if (backgroundSettings.hasKey("scrollSpeed"))
		{
			scrollSpeed = backgroundSettings["scrollSpeed"].ToInt(); //Load scroll speed
		}

		if (backgroundSettings.hasKey("imagePath"))
		{
			imagePath = backgroundSettings["imagePath"].ToString(); //Load image path
		}
	}

	std::cout << "Background Loaded" << std::endl;
}
