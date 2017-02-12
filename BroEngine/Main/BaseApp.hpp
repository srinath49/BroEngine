#pragma once

#ifndef _BASE_APP_H_
#define _BASE_APP_H_

//---------------------------------------------------------------------------------------------------
class BaseApp
{
public:
	BaseApp();
	virtual ~BaseApp();

	void Run();

protected:
	virtual void Initialize();
	virtual void Unitialize();

	virtual void MainLoop();
};
#endif // !_BASE_APP_H_
