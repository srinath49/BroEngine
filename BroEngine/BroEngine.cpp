#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <corecrt_wstdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <corecrt_io.h>
#include "EngineCode/Math/IntVector2.hpp"

//-----------------------------------------------------------------------------------------------
HWND g_hWnd = nullptr;
HDC g_displayDeviceContext = nullptr;
const char* APP_NAME = "Minimum Test App";
bool g_runProgram = true;


#ifndef UNUSED
#define UNUSED (void)
#endif // !UNUSED

//--------Usually called WinProc , windows want to send message to you , it got to send through this function-----
LRESULT CALLBACK WindowsMessageHandlingProcedure(HWND windowHandle, UINT wmMessageCode, WPARAM wParam, LPARAM lParam)
{
	unsigned char asKey = (unsigned char) wParam;
	//DWORD value;
	switch (wmMessageCode)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		break;

	case WM_CHAR:
		break;

	case WM_KEYDOWN:
		if (asKey == VK_ESCAPE)
		{
			g_runProgram = false;
		}
		return 0;
		break;

	case WM_KEYUP:
		break;

	case WM_MOUSEWHEEL:
		break;

	case WM_LBUTTONDOWN:
		break;

	case WM_LBUTTONUP:
		break;

	case WM_RBUTTONDOWN:
		break;

	case WM_QUIT:
		g_runProgram = false;
		break;
	}

	// pass this message to other program.
	return DefWindowProc(windowHandle, wmMessageCode, wParam, lParam);
}


//-----------------------------------------------------------------------------------------------
void CreateWindowHandle(HINSTANCE applicationInstanceHandle)
{
	SetProcessDPIAware();

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

	const int xOffset = 50;
	const int yOffset = 50;
	RECT windowRect = { xOffset + 0, yOffset + 0, xOffset + 1600, yOffset + 900 };		// shifting the windows start position from 0,0(topleft) to 50,50
	AdjustWindowRectEx(&windowRect, windowStyleFlags, FALSE, windowStyleExFlags);

	WCHAR windowTitle[1024];
	MultiByteToWideChar(GetACP(), 0, APP_NAME, -1, windowTitle, sizeof(windowTitle) / sizeof(windowTitle[0]));
	g_hWnd = CreateWindowEx(
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
		applicationInstanceHandle,
		NULL);

	ShowWindow(g_hWnd, SW_SHOW);
	SetForegroundWindow(g_hWnd);
	SetFocus(g_hWnd);

	g_displayDeviceContext = GetDC(g_hWnd);

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

	int pixelFormatCode = ChoosePixelFormat(g_displayDeviceContext, &pixelFormatDescriptor);
	SetPixelFormat(g_displayDeviceContext, pixelFormatCode, &pixelFormatDescriptor);

}

//-----------------------------------------------------------------------------------------------
void RunMessagePump()
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


//---------------------------------------------------------------------------------------------------
void Initialize(HINSTANCE applicationInstanceHandle)
{
	CreateWindowHandle(applicationInstanceHandle);
}


//---------------------------------------------------------------------------------------------------
void StartWindowsConsole()
{
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
	hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
	FILE* hf_in = _fdopen(hCrt, "r");
	setvbuf(hf_in, NULL, _IONBF, 128);
	*stdin = *hf_in;
}


//-----------------------------------------------------------------------------------------------
/* ( Handle in windows application ,  ) */
int WINAPI WinMain(HINSTANCE applicationInstanceHandle, HINSTANCE, LPSTR commandLineString, int)
{
	UNUSED(commandLineString);
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG)|_CRTDBG_LEAK_CHECK_DF);
	StartWindowsConsole();
	Initialize(applicationInstanceHandle);
	IntVector2 vec2;
	printf("%d, &d\n", vec2.x, vec2.y);
	vec2 = vec2 + 4;
	printf("%d, &d\n", vec2.x, vec2.y);
	while (g_runProgram)
	{
		// Game Loop here
	}
	
	return 0;
}

int main()
{
	//UNUSED(commandLineString);
	//_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	//StartWindowsConsole();
	//Initialize(applicationInstanceHandle);
	IntVector2 vec2;
	printf("%d, &d\n", vec2.x, vec2.y);
	vec2 = vec2 + 4;
	printf("%d, &d\n", vec2.x, vec2.y);
	
	getchar();
	return 0;
}