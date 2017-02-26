#pragma once

#ifndef _WIN32_OPENGL_APP_H_
#define _WIN32_OPENGL_APP_H_

//---------------------------------------------------------------------------------------------------
#include "BaseApp.hpp"

//---------------------------------------------------------------------------------------------------
class BaseWindow;

//---------------------------------------------------------------------------------------------------
class Win32OpenGLApp : public BaseApp
{
public:
	Win32OpenGLApp(void* applicationInstance);
	~Win32OpenGLApp();
	virtual void Initialize();

protected:
	virtual void Unitialize();
	//virtual void MainLoop();

private:
	void InitializeWindow();
	void UninitializeWindow();
};	
#endif // !_WIN32_OPENGL_APP_H_
