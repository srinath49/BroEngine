#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include "EngineCode/Math/IntVector2.hpp"
#include "EngineCode/Math/IntVector3.hpp"
#include "EngineCode/Math/FloatVector2.hpp"
#include "EngineCode/Math/FloatVector3.hpp"

#ifndef UNUSED
#define UNUSED (void)
#endif // !UNUSED


int main()
{
	IntVector2 vec1 = IntVector2(1 , 1);
	IntVector2 vec2 = IntVector2(2 , 2);
	IntVector2* result;
	IntVector2* obj;
	IntVector3 intVector3A = IntVector3(2 , 3 , 4);
	IntVector3 intVector3B = IntVector3(5 , 6 , 7);
	IntVector3 intVector3C;
	FloatVector3 floatVector3 = FloatVector3(2.5f , 3.5f , 4.5f);
	int scalarResult;
	//FloatVector2 fVec2;
	//FloatVector2* fvec2 = new FloatVector2(1 , 2);
	//printf("%f, %f\n", fvec2->x , fvec2->y);
	//printf("%d, %d\n", vec2.x, vec2.y);
	//fVec2 /= 4;

	//result = &(*vec1 + *vec2);
	vec1 = vec2;

	scalarResult = vec1.DotProduct(vec2);

	intVector3C = intVector3B.CrossProduct(intVector3A);

	printf("%d , %d\n" , vec1.x , vec1.y);
	printf("%d , %d , %d\n", intVector3C.x , intVector3C.y , intVector3C.z);

	//Test all your functions here
	
	getchar();
	return 0;
}