#include "Player.h"

Player::Player()
{
	std::cout << "Player Created" << std::endl;
}

Player::~Player()
{
	std::cout << "Player Deleted" << std::endl;
}

void Player::Destroy()
{
	std::cout << "Player Destroyed" << std::endl;
}

void Player::Update(SDL_Event event)
{
	if (SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)  
		{
		case SDLK_w:
			moveY -= speed;
			std::cout << "w" << std::endl;
			break;
		case SDLK_s:
			moveY += speed;
			std::cout << "S" << std::endl;
			break;
		case SDLK_a:
			moveX -= speed;
			std::cout << "A" << std::endl;
			break;
		case SDLK_d:
			moveX += speed;
			std::cout << "D" << std::endl;
			break;
		case SDLK_SPACE:
			Shoot();
			std::cout << "Space" << std::endl;
			break;
		case SDLK_ESCAPE:
			std::cout << "Would you like to save?" << std::endl;
			break;
		}
	}
}


void Player::Shoot()
{
	std::cout << "Player Shooting" << std::endl;
}

SDL_Rect Player::GetPosition()
{
	return SDL_Rect{ moveX, moveY, imageWidth, imageHeight };
}


void Player::Load(json::JSON& _json)  //Load player data from json file
{
	if (_json.hasKey("Player"))
	{
		json::JSON playerData = _json["Player"];

		if (playerData.hasKey("lives"))
		{
			lives = playerData["lives"].ToInt();  //Load the player lives
			std::cout << "Player Lives: " << lives << std::endl;
		}

		if (playerData.hasKey("speed"))
		{
			speed = playerData["speed"].ToInt();  //Load the player speed
			std::cout << "Player Speed: " << speed << std::endl;
		}

		if (playerData.hasKey("imagePath"))
		{
			imagePath = playerData["imagePath"].ToString();  //Load the player image path
			std::cout << "Player Image Path: " << imagePath << std::endl;
		}

		if (playerData.hasKey("imageWidth"))
		{
			imageWidth = playerData["imageWidth"].ToInt();  //Load the player image width
			std::cout << "Player Image Width: " << imageWidth << std::endl;
		}

		if (playerData.hasKey("imageHeight"))
		{
			imageHeight = playerData["imageHeight"].ToInt();  //Load the player image height
			std::cout << "Player Image Height: " << imageHeight << std::endl;
		}
	}
	std::cout << "Player Loaded" << std::endl;
}
