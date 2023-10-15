#include "AssetManager.h"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::LoadJSON(json::JSON& _json)
{
	//if (_json.hasKey("Player"))
	//{
	//	json::JSON playerData = _json["Player"];
	//	if (playerData.hasKey("imagePath"))
	//	{
	//		imagePath = playerData["imagePath"].ToString();  //Load the player image path
	//	}

	//	if (playerData.hasKey("imageWidth"))
	//	{
	//		width = playerData["imageWidth"].ToInt();  //Load the player image width
	//	}

	//	if (playerData.hasKey("imageHeight"))
	//	{
	//		height = playerData["imageHeight"].ToInt();  //Load the player image height
	//	}
	//}
}

SDL_Texture* AssetManager::LoadTexture(SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load("texturePath");
	std::cout << "texturePath:" << std::endl;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return texture;
}
