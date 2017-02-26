#include "Win32OpenGLApp.hpp"
#include <stdio.h>
#include "EngineCode/Window/Win32Window.hpp"
#include "EngineCode/Input/InputSystem.hpp"

//---------------------------------------------------------------------------------------------------
Win32OpenGLApp::Win32OpenGLApp(void* applicationInstance)
	: BaseApp(applicationInstance)
{

}

//---------------------------------------------------------------------------------------------------
Win32OpenGLApp::~Win32OpenGLApp()
{
	Unitialize();
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::Initialize()
{
	m_inputSystem = InputSystem::GetInputSystem();
	InitializeWindow();
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::Unitialize()
{
	UninitializeWindow();
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::InitializeWindow()
{
	m_window = new Win32Window(m_applicationInstance, this);
	m_window->Initialize();
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::UninitializeWindow()
{
	
}

////---------------------------------------------------------------------------------------------------
//void Win32OpenGLApp::MainLoop()
//{
//	
//}