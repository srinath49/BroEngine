#include "Win32OpenGLApp.hpp"
#include "glfw3.h"
#include <stdio.h>

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

void Win32OpenGLApp::key_callback(GLFWwindow * window , int key , int scancode , int action , int mods)
{
	printf("%d" , key);
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
	glfwSetKeyCallback(m_window , key_callback);
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::UninitializeWindow()
{
	glfwDestroyWindow(m_window);
}

//---------------------------------------------------------------------------------------------------
void Win32OpenGLApp::MainLoop()
{
	while(!glfwWindowShouldClose(m_window))
	{
		glfwPollEvents();
	}
}