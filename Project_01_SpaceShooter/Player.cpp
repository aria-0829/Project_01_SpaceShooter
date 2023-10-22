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

	tex = AssetManager::Instance().LoadTexture((char*)imagePath.c_str()); //Load tex
	dstrect = { windowWidth / 2, (windowHeight - imageHeight), imageWidth, imageHeight};  //Player starting position at the bottom middle of the window

	std::cout << "Player Initialized" << std::endl;
}

void Player::Update()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	//GameTime& gameTime = GameTime::Instance();
	//float deltaTime = gameTime.DeltaTime();

	if (currentKeyStates[SDL_SCANCODE_W]) {
		moveY -= speed;// *GameTime::Instance().DeltaTime();
	}
	if (currentKeyStates[SDL_SCANCODE_A]) {
		moveX -= speed;// *GameTime::Instance().DeltaTime();
	}
	if (currentKeyStates[SDL_SCANCODE_S]) {
		moveY += speed;// *GameTime::Instance().DeltaTime();
	}
	if (currentKeyStates[SDL_SCANCODE_D]) {
		moveX += speed;// *GameTime::Instance().DeltaTime();
	}
	if (currentKeyStates[SDL_SCANCODE_SPACE]) {
		Shoot();
	}

	projectiles.remove_if([](Projectile* projectile)
	{
		projectile->Update();
		projectile->Render();

		//Check if the projectile is out of the window
		if (projectile->GetPositionY() < 0)
		{
			projectile->Destroy();
			delete projectile;
			return true; //Remove the projectile
		}
		return false; //Keep the projectile
	});
}

void Player::Destroy()
{
	for (auto projectile : projectiles)
	{
		projectile->Destroy();
		delete projectile;
		projectile = nullptr; //?
	}
	projectiles.clear();

	std::cout << "Player Destroyed" << std::endl;
}


void Player::Shoot()
{
	std::cout << "Player Shooting" << std::endl;
	static int frameCount = 0;
	const int spawnInterval = 5;

	if (frameCount % spawnInterval == 0)
	{
		Projectile* projectile = new Projectile();
		AddProjectile(projectile);
		projectile->Load();
		projectile->Initialize((dstrect.x + imageWidth /2), dstrect.y);
	}

	++frameCount;
}

void Player::AddProjectile(Projectile* _projectile)
{
	projectiles.push_back(_projectile);
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

void Player::Load(json::JSON& _json)  //Load player data from json file
{
	if (_json.hasKey("Player"))
	{
		json::JSON playerData = _json["Player"];

		if (playerData.hasKey("lives"))
		{
			lives = playerData["lives"].ToInt();  //Load the player lives
		}

		if (playerData.hasKey("speed"))
		{
			speed = playerData["speed"].ToInt();  //Load the player speed
		}

		if (playerData.hasKey("imagePath"))
		{
			imagePath = playerData["imagePath"].ToString();  //Load the player image path
		}

		if (playerData.hasKey("imageWidth"))
		{
			imageWidth = playerData["imageWidth"].ToInt();  //Load the player image width
		}

		if (playerData.hasKey("imageHeight"))
		{
			imageHeight = playerData["imageHeight"].ToInt();  //Load the player image height
		}
	}

	std::cout << "Player Load Complete." << std::endl << std::endl;
}
