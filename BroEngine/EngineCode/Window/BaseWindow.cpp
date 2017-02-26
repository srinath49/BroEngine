#include "BaseWindow.hpp"
#include "Main/BaseApp.hpp"

BaseApp* BaseWindow::s_app = nullptr;

//---------------------------------------------------------------------------------------------------
BaseWindow::BaseWindow(void* applicationInstance, BaseApp* app) 
	: m_applicationInstance(applicationInstance)
{
	if (!s_app)
	{
		s_app = app;
	}
}

//---------------------------------------------------------------------------------------------------
BaseWindow::~BaseWindow()
{

}

//---------------------------------------------------------------------------------------------------
void BaseWindow::Initialize()
{

}

//---------------------------------------------------------------------------------------------------
void BaseWindow::Uninitialize()
{

}

//---------------------------------------------------------------------------------------------------
void BaseWindow::Update()
{

}

//---------------------------------------------------------------------------------------------------
void BaseWindow::SwapWindowBuffers()
{

}