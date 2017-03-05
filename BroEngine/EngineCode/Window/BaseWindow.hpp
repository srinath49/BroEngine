#pragma once


#ifndef _BASE_WINDOW_H_
#define _BASE_WINDOW_H_

//---------------------------------------------------------------------------------------------------
class BaseApp;

//---------------------------------------------------------------------------------------------------
class BaseWindow
{
public:
	BaseWindow(void* applicationInstance, BaseApp* app);
	virtual ~BaseWindow();

	virtual void Initialize();
	virtual void Uninitialize();
	virtual void Update(float deltaTime);
	virtual void SwapWindowBuffers();
public:
	bool				m_isRunning;

	static BaseApp*		s_app;

protected:
	void*				m_applicationInstance;
};
#endif // !_BASE_WINDOW_H_
