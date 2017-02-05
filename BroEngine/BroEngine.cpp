#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "EngineCode/Math/IntVector2.hpp"
#include "EngineCode/Math/FloatVector2.hpp"

#ifndef UNUSED
#define UNUSED (void)
#endif // !UNUSED


int main()
{
	IntVector2 vec1 = IntVector2(1 , 1);
	IntVector2 vec2 = IntVector2(2 , 2);
	IntVector2* result;
	//FloatVector2 fVec2;
	//FloatVector2* fvec2 = new FloatVector2(1 , 2);
	//printf("%f, %f\n", fvec2->x , fvec2->y);
	//printf("%d, %d\n", vec2.x, vec2.y);
	//fVec2 /= 4;

	//result = &(*vec1 + *vec2);
	vec1 = vec2;

	printf("%d , %d\n" , vec1.x , vec1.y);

	//Test all your functions here
	
	getchar();
	return 0;
}