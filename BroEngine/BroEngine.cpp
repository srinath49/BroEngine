#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "Main/Win32OpenGLApp.hpp"

//---------------------------------------------------------------------------------------------------
#ifndef UNUSED
#define UNUSED (void)
#endif // !UNUSED


//---------------------------------------------------------------------------------------------------
int main()
{
	int returnValue = EXIT_SUCCESS;
	BaseApp* app = new Win32OpenGLApp();
	try
	{
		app->Run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		returnValue =  EXIT_FAILURE;
	}
	delete app;
	return returnValue;
}
