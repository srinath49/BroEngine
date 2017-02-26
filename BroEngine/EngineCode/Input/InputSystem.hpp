#pragma once

#ifndef _INPUT_SYSTEM_H
#define _INPUT_SYSTEM_H

//---------------------------------------------------------------------------------------------------
#include <map>

//---------------------------------------------------------------------------------------------------
class InputSystem
{
private:
	InputSystem();
public:
	static InputSystem* GetInputSystem();
	~InputSystem();

	void KeyDown(unsigned char downKey);
	void KeyUp(unsigned char upKey);

	bool IsKeyDown(unsigned char keyToCheck);
	bool IsKeyUp(unsigned char keyToCheck);

public:
	static InputSystem*	s_instance;

private:
	std::map<unsigned char, bool>	m_keys;
};
#endif // !_INPUT_SYSTEM_H
