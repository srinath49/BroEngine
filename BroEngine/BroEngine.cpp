#define WIN32_LEAN_AND_MEAN
#include "Windows.h"
#include <stdio.h>
#include "Main/Win32OpenGLApp.hpp"
#include <io.h>
#include <fcntl.h>
#include <cassert>
#include <crtdbg.h>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

//---------------------------------------------------------------------------------------------------
#ifndef UNUSED
#define UNUSED (void)
#endif // !UNUSED

//---------------------------------------------------------------------------------------------------
void StartWindowsConsole()
{
	//_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	// This code was take from the internet. 
	AllocConsole();
	HANDLE stdHandle;
	int hConsole;
	FILE* fp;
	stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hConsole = _open_osfhandle((long)stdHandle, _O_TEXT);
	fp = _fdopen(hConsole, "w");

	freopen_s(&fp, "CONOUT$", "w", stdout);
}

//---------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE applicationInstanceHandle, HINSTANCE, LPSTR, int )
{
	int returnValue = EXIT_SUCCESS;
	StartWindowsConsole();

	BaseApp* app = new Win32OpenGLApp(applicationInstanceHandle);
	
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
