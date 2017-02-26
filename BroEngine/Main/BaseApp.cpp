#include "BaseApp.hpp"
#include "EngineCode/Window/BaseWindow.hpp"
#include "EngineCode/Input/InputSystem.hpp"

//---------------------------------------------------------------------------------------------------
BaseApp::BaseApp(void* applicationHandle)
	: m_applicationInstance(applicationHandle)
	, m_window(nullptr)
	, m_inputSystem(nullptr)
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
		m_window->Update();
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
	}
}
