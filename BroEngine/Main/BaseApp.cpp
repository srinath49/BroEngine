#include "BaseApp.hpp"
#include "EngineCode/Window/BaseWindow.hpp"

//---------------------------------------------------------------------------------------------------
BaseApp::BaseApp(void* applicationHandle)
	: m_applicationInstance(applicationHandle)
	, m_window(nullptr)
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
		// Update InputSystem
		// Update EventSystem
		// Update Game
		m_window->SwapWindowBuffers();
	}
}
