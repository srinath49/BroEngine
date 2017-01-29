#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <corecrt_wstdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <corecrt_io.h>
#include "EngineCode/Math/IntVector2.hpp"
#include "EngineCode/Math/FloatVector2.hpp"

#ifndef UNUSED
#define UNUSED (void)
#endif // !UNUSED


int main()
{
	IntVector2 vec2;
	FloatVector2* fvec2 = new FloatVector2(1 , 2);
	printf("%f, %f\n", fvec2->x , fvec2->y);
	printf("%d, %d\n", vec2.x, vec2.y);
	vec2 = vec2 + 4;
	printf("%d, %d\n", vec2.x, vec2.y);

	//Test all your functions here
	
	getchar();
	return 0;
}