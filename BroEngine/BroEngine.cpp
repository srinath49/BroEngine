#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <corecrt_wstdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <corecrt_io.h>
#include "EngineCode/Math/IntVector2.hpp"

#ifndef UNUSED
#define UNUSED (void)
#endif // !UNUSED


int main()
{
	IntVector2 vec2;
	printf("%d, &d\n", vec2.x, vec2.y);
	vec2 = vec2 + 4;
	printf("%d, &d\n", vec2.x, vec2.y);
	
	getchar();
	return 0;
}