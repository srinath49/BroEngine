#pragma once

#ifndef _WIN32_OPENGL_APP_H_
#define _WIN32_OPENGL_APP_H_

//---------------------------------------------------------------------------------------------------
#include "BaseApp.hpp"

//---------------------------------------------------------------------------------------------------
class GLFWwindow;

//---------------------------------------------------------------------------------------------------
class Win32OpenGLApp : public BaseApp
{
public:
	Win32OpenGLApp();
	~Win32OpenGLApp();
	static void key_callback(GLFWwindow* window , int key , int scancode , int action , int mods);

protected:
	virtual void Initialize();
	virtual void Unitialize();
	virtual void MainLoop();

private:
	void InitializeWindow();
	void UninitializeWindow();

private:
	GLFWwindow*		m_window;
};
#endif // !_WIN32_OPENGL_APP_H_
