#include "Game.hpp"
#include "EngineCode\Window\Win32Window.hpp"
#include <gl\GL.h>

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
	/*if (player)
	{
		player->Update(deltaTime);
	}*/
	//for (std::vector<GameObject*>::iterator asteroidsIterator = asteroids.begin(); asteroidsIterator != asteroids.end(); ++asteroidsIterator)
	//{
	//	//asteroidsIterator->Update(deltaTime);
	//}
}

//---------------------------------------------------------------------------------------------------
void Game::Render()
{
	/*if (player)
	{*/
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		 	glPushMatrix();
		 		glBegin(GL_LINES);
		 			glVertex2d(50.0, 150.0);
		 			glColor3f(1.f, 0.f, 0.f);
		 		
		 			glVertex2d(250.0, 250);
		 			glColor3f(0.f, 1.f, 0.f);
		 
		 			glVertex2d(50.0, 250);
		 			glColor3f(0.f, 0.f, 1.f);
		 
		 			glVertex2d(50.0, 50);
		 			glColor3f(0.f, 1.f, 0.f);
		 		glEnd();
		 		
		 		glPushMatrix();
		 		glTranslatef(100, 200, 0);
		 		glBegin(GL_TRIANGLES);
		 			glColor3f(1.f, 0.f, 0.f);
		 			glVertex2d(0, 0);
		 			glColor3f(0.f, 1.f, 0.f);
		 			glVertex2d(100, 0);
		 			glColor3f(0.f, 0.f, 1.f);
		 			glVertex2d(50, 100);
		 		glEnd();
		 		glPopMatrix();
		 	glPopMatrix();
	/*}*/
	//for (std::vector<GameObject*>::iterator asteroidsIterator = asteroids.begin(); asteroidsIterator != asteroids.end(); ++asteroidsIterator)
	//{
	//	//asteroidsIterator->Render();
	//}
}

//---------------------------------------------------------------------------------------------------
void Game::InitializeWorld()
{
	
}
