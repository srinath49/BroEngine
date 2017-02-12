#include <stdio.h>
#include "EngineCode/Math/IntVector2.hpp"
#include "EngineCode/Math/FloatVector2.hpp"
#include "glfw3.h"

//---------------------------------------------------------------------------------------------------
#ifndef UNUSED
#define UNUSED (void)
#endif // !UNUSED

//---------------------------------------------------------------------------------------------------
GLFWwindow*		g_window;

//---------------------------------------------------------------------------------------------------
void InitializeWindow();
void UninitializeWindow();

//---------------------------------------------------------------------------------------------------
int main()
{
	InitializeWindow();
	getchar();
	UninitializeWindow();
	return 0;
}

//---------------------------------------------------------------------------------------------------
void InitializeWindow()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	g_window = glfwCreateWindow(800, 600, "Bob Window", nullptr, nullptr);
}

//---------------------------------------------------------------------------------------------------
void UninitializeWindow()
{
	glfwDestroyWindow(g_window);

	glfwTerminate();
}