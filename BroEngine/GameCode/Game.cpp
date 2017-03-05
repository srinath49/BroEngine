#include "Game.hpp"


//---------------------------------------------------------------------------------------------------
Game::Game()
{

}

//---------------------------------------------------------------------------------------------------
Game::~Game()
{

}

//---------------------------------------------------------------------------------------------------
void Game::Initialize()
{
	InitializeWorld();
}

//---------------------------------------------------------------------------------------------------
void Game::Update(float deltaTime)
{
	if (player)
	{
		//player->Update(deltaTime);
	}
	for (std::vector<GameObject*>::iterator asteroidsIterator = asteroids.begin(); asteroidsIterator != asteroids.end(); ++asteroidsIterator)
	{
		//asteroidsIterator->Update(deltaTime);
	}
}

//---------------------------------------------------------------------------------------------------
void Game::Render()
{
	if (player)
	{
		//player->Render();
	}
	for (std::vector<GameObject*>::iterator asteroidsIterator = asteroids.begin(); asteroidsIterator != asteroids.end(); ++asteroidsIterator)
	{
		//asteroidsIterator->Render();
	}
}

//---------------------------------------------------------------------------------------------------
void Game::InitializeWorld()
{
	
}
