#include "BaseApp.hpp"
#include "EngineCode/Window/BaseWindow.hpp"
#include "EngineCode/Input/InputSystem.hpp"
#include "EngineCode/Time/Time.hpp"
#include "GameCode/Game.hpp"

//---------------------------------------------------------------------------------------------------
BaseApp::BaseApp(void* applicationHandle)
	: m_applicationInstance(applicationHandle)
	, m_window(nullptr)
	, m_inputSystem(nullptr)
	, m_deltaTime()
	, m_timePreviousFrame()
	, m_timeThisFrame()
	, m_frameTime(1.0f/60.0f)
	, m_game()
{
	
}

//---------------------------------------------------------------------------------------------------
BaseApp::~BaseApp()
{
	delete m_window;
}

void BaseApp::Run()
{
	Initialize();
	MainLoop();
}

//---------------------------------------------------------------------------------------------------
void BaseApp::Initialize()
{
	
}

//---------------------------------------------------------------------------------------------------
void BaseApp::Unitialize()
{

}

//---------------------------------------------------------------------------------------------------
void BaseApp::MainLoop()
{
	while (m_isRunning && m_window)
	{
		m_timeThisFrame = (float)GetCurrentTimeSeconds();
		m_deltaTime = m_timeThisFrame - m_timePreviousFrame;

		m_window->Update(m_deltaTime);
		m_game->Update(m_deltaTime);
		m_game->Render();

		if (m_inputSystem)
		{
			if (m_inputSystem->IsKeyDown('L'))
			{
				int test = 0;
			}
		}
		// Update InputSystem
		// Update EventSystem
		// Update Game
		m_window->SwapWindowBuffers();

		while (m_deltaTime < m_frameTime)
		{
			m_timeThisFrame = (float)GetCurrentTimeSeconds();
			m_deltaTime = m_timeThisFrame - m_timePreviousFrame;
		}
		m_timePreviousFrame = m_timeThisFrame;
	}
}
