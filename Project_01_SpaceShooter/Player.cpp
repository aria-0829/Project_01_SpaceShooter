#include "Player.h"
#include "Renderer.h"
#include "AssetManager.h"
#include "GameTime.h"

Player::Player()
{
	std::cout << "Player Created" << std::endl;
}

Player::~Player()
{
	std::cout << "Player Deleted" << std::endl;
}

void Player::Initialize()
{
	windowWidth = Renderer::Instance().GetWidth();
	windowHeight = Renderer::Instance().GetHeight();

	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load player tex
	dstrect = { windowWidth / 2, (windowHeight - imageHeight), imageWidth, imageHeight};  //Player starting position at the bottom middle of the window

	std::cout << "Player Initialized" << std::endl;
}

void Player::Update()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_W]) {
		moveY -= speed;// *GameTime::Instance().DeltaTime();
		std::cout << "w" << std::endl;
	}
	if (currentKeyStates[SDL_SCANCODE_A]) {
		moveX -= speed;// *GameTime::Instance().DeltaTime();
		std::cout << "A" << std::endl;
	}
	if (currentKeyStates[SDL_SCANCODE_S]) {
		moveY += speed;// *GameTime::Instance().DeltaTime();
		std::cout << "S" << std::endl;
	}
	if (currentKeyStates[SDL_SCANCODE_D]) {
		moveX += speed;// *GameTime::Instance().DeltaTime();
		std::cout << "D" << std::endl;
	}
	if (currentKeyStates[SDL_SCANCODE_SPACE]) {
		Shoot();
		std::cout << "Space" << std::endl;
	}
}

void Player::Destroy()
{
	SDL_DestroyTexture(tex);

	std::cout << "Player Destroyed" << std::endl;
}


void Player::Shoot()
{
	std::cout << "Player Shooting" << std::endl;
}

void Player::Render()
{
	//Apply the movement to the playerDstrect
	dstrect.x = windowWidth / 2 + moveX;
	dstrect.y = (windowHeight - imageHeight) + moveY;

	//Keep the player within the window
	if (moveX < -(windowWidth / 2))
	{
		moveX = -(windowWidth / 2);
	}
	if (moveX > (windowWidth - imageWidth) - windowWidth / 2)
	{
		moveX = (windowWidth - imageWidth) - windowWidth / 2;
	}

	if (moveY < -(windowHeight - imageHeight))
	{
		moveY = -(windowHeight - imageHeight);
	}
	if (moveY > 0)
	{
		moveY = 0;
	}

	SDL_RenderCopy(Renderer::Instance().GetRenderer(), tex, NULL, &dstrect);  //Render the player
}

//SDL_Rect Player::GetPosition()
//{
//	return SDL_Rect{ moveX, moveY, imageWidth, imageHeight };
//}

//char* Player::GetImagePath()
//{
//	return (char*)imagePath.c_str();
//}


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
