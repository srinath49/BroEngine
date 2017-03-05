#pragma once

#ifndef _GAME_H_
#define _GAME_H_

//---------------------------------------------------------------------------------------------------
#include <vector>

//---------------------------------------------------------------------------------------------------
class GameObject;

//---------------------------------------------------------------------------------------------------
class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Update(float deltaTime);
	void Render();

private:
	void InitializeWorld();
	
private:
	GameObject*					player;
	std::vector<GameObject*>	asteroids;
};
#endif // !_GAME_H_
