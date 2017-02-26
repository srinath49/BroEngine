#pragma once

#ifndef _WIN32_WINDOW_H_
#define _WIN32_WINDOW_H_

//---------------------------------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "BaseWindow.hpp"

//---------------------------------------------------------------------------------------------------
class BaseApp;

//---------------------------------------------------------------------------------------------------
class Win32Window : public BaseWindow
{
public:
	Win32Window(void* applicationHandle, BaseApp* app);
	virtual ~Win32Window();

	virtual void Initialize();
	virtual void Uninitialize();
	virtual void Update();
	virtual void SwapWindowBuffers();

private:
	void RunMessagePump();

protected:
	HWND					m_hWnd;
	HDC						m_displayDeviceContext;
	HGLRC					m_openGLRenderingContext;

};
#endif // !_WIN32_WINDOW_H_
