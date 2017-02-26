#include "InputSystem.hpp"


//---------------------------------------------------------------------------------------------------
InputSystem* InputSystem::s_instance = nullptr;


//---------------------------------------------------------------------------------------------------
InputSystem* InputSystem::GetInputSystem()
{
	if (!s_instance)
	{
		s_instance = new InputSystem();
	}
	return s_instance;
}

//---------------------------------------------------------------------------------------------------
InputSystem::InputSystem()
{

}

//---------------------------------------------------------------------------------------------------
InputSystem::~InputSystem()
{

}

void InputSystem::KeyDown(unsigned char downKey)
{
	m_keys[downKey] = true;
}

void InputSystem::KeyUp(unsigned char upKey)
{
	m_keys[upKey] = false;
}

bool InputSystem::IsKeyDown(unsigned char keyToCheck)
{
	return m_keys[keyToCheck];
}

bool InputSystem::IsKeyUp(unsigned char keyToCheck)
{
	return !m_keys[keyToCheck];
}

