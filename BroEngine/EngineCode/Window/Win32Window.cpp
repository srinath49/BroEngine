#include "Win32Window.hpp"
#include <gl\GL.h>
#include "Main\BaseApp.hpp"
#include "EngineCode\Input\InputSystem.hpp"
#include "EngineCode\Math\FloatVector3.hpp"

//-----------------------------------------------------------------------------------------------
LRESULT CALLBACK WindowsMessageHandlingProcedure(HWND windowHandle, UINT wmMessageCode, WPARAM wParam, LPARAM lParam)
{
	unsigned char asKey = (unsigned char)wParam;
	switch (wmMessageCode)
	{
		case WM_CLOSE:
		case WM_DESTROY:
		case WM_QUIT:
			if (Win32Window::s_app)
			{
				Win32Window::s_app->m_isRunning = false;
			}
			break;
		case WM_KEYDOWN:
			if (InputSystem::s_instance)
			{
				InputSystem::s_instance->KeyDown(asKey);
			}
			break;
		case WM_KEYUP:
			if (InputSystem::s_instance)
			{
				InputSystem::s_instance->KeyUp(asKey);
			}
			break;
	}

	return DefWindowProc(windowHandle, wmMessageCode, wParam, lParam);
}

//---------------------------------------------------------------------------------------------------
Win32Window::Win32Window(void* applicationHandle, BaseApp* app)
	: BaseWindow(applicationHandle, app)
	, m_hWnd(nullptr)
	, m_displayDeviceContext(nullptr)
	, m_openGLRenderingContext(nullptr)
{

}

//---------------------------------------------------------------------------------------------------
Win32Window::~Win32Window()
{
	
}

//---------------------------------------------------------------------------------------------------
void Win32Window::Initialize()
{
	// Define a window class
	WNDCLASSEX windowClassDescription;
	memset(&windowClassDescription, 0, sizeof(windowClassDescription));
	windowClassDescription.cbSize = sizeof(windowClassDescription);
	windowClassDescription.style = CS_OWNDC; // Redraw on move, request own Display Context
	windowClassDescription.lpfnWndProc = static_cast<WNDPROC>(WindowsMessageHandlingProcedure); // Assign a win32 message-handling function
	windowClassDescription.hInstance = GetModuleHandle(NULL);
	windowClassDescription.hIcon = NULL;
	windowClassDescription.hCursor = NULL;
	windowClassDescription.lpszClassName = TEXT("Simple Window Class");
	RegisterClassEx(&windowClassDescription);

	const DWORD windowStyleFlags = WS_CAPTION | WS_BORDER | WS_THICKFRAME | WS_SYSMENU | WS_OVERLAPPED;
	const DWORD windowStyleExFlags = WS_EX_APPWINDOW;

	RECT desktopRect;
	HWND desktopWindowHandle = GetDesktopWindow();
	GetClientRect(desktopWindowHandle, &desktopRect);
	float offset = 25.0f;
	float width  = 1080;
	float height = 800;
	RECT windowRect = { offset, offset, width - offset, height - offset };
	AdjustWindowRectEx(&windowRect, windowStyleFlags, FALSE, windowStyleExFlags);

	WCHAR windowTitle[1024];
	MultiByteToWideChar(GetACP(), 0, "OPEN GL Window", -1, windowTitle, sizeof(windowTitle) / sizeof(windowTitle[0]));
	m_hWnd = CreateWindowEx(
		windowStyleExFlags,
		windowClassDescription.lpszClassName,
		windowTitle,
		windowStyleFlags,
		windowRect.left,
		windowRect.top,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		NULL,
		NULL,
		(HINSTANCE)m_applicationInstance,
		NULL);

	ShowWindow(m_hWnd, SW_SHOW);
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);

	m_displayDeviceContext = GetDC(m_hWnd);

	HCURSOR cursor = LoadCursor(NULL, IDC_ARROW);
	SetCursor(cursor);

	PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
	memset(&pixelFormatDescriptor, 0, sizeof(pixelFormatDescriptor));
	pixelFormatDescriptor.nSize = sizeof(pixelFormatDescriptor);
	pixelFormatDescriptor.nVersion = 1;
	pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDescriptor.cColorBits = 24;
	pixelFormatDescriptor.cDepthBits = 24;
	pixelFormatDescriptor.cAccumBits = 0;
	pixelFormatDescriptor.cStencilBits = 8;

	int pixelFormatCode = ChoosePixelFormat(m_displayDeviceContext, &pixelFormatDescriptor);
	SetPixelFormat(m_displayDeviceContext, pixelFormatCode, &pixelFormatDescriptor);
	m_openGLRenderingContext = wglCreateContext(m_displayDeviceContext);
	wglMakeCurrent(m_displayDeviceContext, m_openGLRenderingContext);
	glOrtho(0.f, width, 0.f, height, 0.f, 1.f);

	m_isRunning = true;
}

//---------------------------------------------------------------------------------------------------
void Win32Window::Uninitialize()
{

}

//---------------------------------------------------------------------------------------------------
void Win32Window::Update(float deltaTime)
{
	RunMessagePump();
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
// 	glPushMatrix();
// 		glBegin(GL_LINES);
// 			glVertex2d(50.0, 150.0);
// 			glColor3f(1.f, 0.f, 0.f);
// 		
// 			glVertex2d(250.0, 250);
// 			glColor3f(0.f, 1.f, 0.f);
// 
// 			glVertex2d(50.0, 250);
// 			glColor3f(0.f, 0.f, 1.f);
// 
// 			glVertex2d(50.0, 50);
// 			glColor3f(0.f, 1.f, 0.f);
// 		glEnd();
// 		
// 		glPushMatrix();
// 		glTranslatef(100, 200, 0);
// 		glBegin(GL_TRIANGLES);
// 			glColor3f(1.f, 0.f, 0.f);
// 			glVertex2d(0, 0);
// 			glColor3f(0.f, 1.f, 0.f);
// 			glVertex2d(100, 0);
// 			glColor3f(0.f, 0.f, 1.f);
// 			glVertex2d(50, 100);
// 		glEnd();
// 		glPopMatrix();
// 	glPopMatrix();
}

//---------------------------------------------------------------------------------------------------
void Win32Window::SwapWindowBuffers()
{
	SwapBuffers(m_displayDeviceContext);
}

//---------------------------------------------------------------------------------------------------
void Win32Window::RunMessagePump()
{
	MSG queuedMessage;
	for (;; )
	{
		const BOOL wasMessagePresent = PeekMessage(&queuedMessage, NULL, 0, 0, PM_REMOVE);
		if (!wasMessagePresent)
		{
			break;
		}

		TranslateMessage(&queuedMessage);
		DispatchMessage(&queuedMessage);
	}
}