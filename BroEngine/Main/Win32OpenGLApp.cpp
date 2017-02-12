#include "Win32OpenGLApp.hpp"
#include "glfw3.h"

//---------------------------------------------------------------------------------------------------
Win32OpenGLApp::Win32OpenGLApp()
	: BaseApp()
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
	glfwInit();
	InitializeWindow();
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::Unitialize()
{
	UninitializeWindow();
	glfwTerminate();
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::InitializeWindow()
{
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	m_window = glfwCreateWindow(800, 600, "Bob Window", nullptr, nullptr);
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::UninitializeWindow()
{
	glfwDestroyWindow(m_window);
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::MainLoop()
{
	while (!glfwWindowShouldClose(m_window))
	{
		glfwPollEvents();
	}
}