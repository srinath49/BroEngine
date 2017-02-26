#pragma once

#ifndef _BASE_APP_H_
#define _BASE_APP_H_

//---------------------------------------------------------------------------------------------------
class BaseWindow;

//---------------------------------------------------------------------------------------------------
class BaseApp
{
public:
	BaseApp(void* applicationHandle);
	virtual ~BaseApp();
	virtual void Initialize();
	void Run();

protected:
	virtual void Unitialize();
	virtual void MainLoop();

public:
	bool			m_isRunning;

protected:
	void*			m_applicationInstance;
	BaseWindow*		m_window;
};
#endif // !_BASE_APP_H_
