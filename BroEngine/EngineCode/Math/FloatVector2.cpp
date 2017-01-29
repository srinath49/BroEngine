#include "FloatVector2.hpp"
#include "IntVector2.hpp"
#include <math.h>

FloatVector2::FloatVector2()
	: x(0.0f)
	, y(0.0f)
{

}

FloatVector2::FloatVector2(float xVal , float yVal) 
	: x(xVal)
	, y(yVal)
{
	
}

FloatVector2::FloatVector2(int xVal, int yVal)
	: x((float)xVal)
	, y((float)yVal)
{

}

FloatVector2::FloatVector2(const FloatVector2& floatVectorToCopy)
{
	x = floatVectorToCopy.x;
	y = floatVectorToCopy.y;
}

FloatVector2::FloatVector2(const IntVector2& intVectorToCopy)
{
	x = (float)intVectorToCopy.x;
	y = (float)intVectorToCopy.y;
}


FloatVector2::~FloatVector2()
{

}

FloatVector2 FloatVector2::operator +(const FloatVector2& floatVectorToAdd) const
{
	FloatVector2 returnVector;

	returnVector.x = x + floatVectorToAdd.x;
	returnVector.y = y + floatVectorToAdd.y;

	return returnVector;
}

FloatVector2 FloatVector2::operator -(const FloatVector2& floatVectorToSubtract) const
{
	FloatVector2 returnVector;

	returnVector.x = x - floatVectorToSubtract.x;
	returnVector.y = y - floatVectorToSubtract.y;

	return returnVector;
}

FloatVector2 FloatVector2::operator +(float floatScalarToAdd) const
{
	FloatVector2 returnVector;

	returnVector.x = x + floatScalarToAdd;
	returnVector.y = y + floatScalarToAdd;

	return returnVector;
}

FloatVector2 FloatVector2::operator -(float floatScalarToSubtract) const
{
	FloatVector2 returnVector;

	returnVector.x = x - floatScalarToSubtract;
	returnVector.y = y - floatScalarToSubtract;

	return returnVector;
}

FloatVector2 FloatVector2::operator *(float floatScalarToMultiply) const
{
	FloatVector2 returnVector;

	returnVector.x = x * floatScalarToMultiply;
	returnVector.y = y * floatScalarToMultiply;

	return returnVector;
}

FloatVector2 FloatVector2::operator /(float floatScalarToDivide) const
{
	FloatVector2 returnVector;

	returnVector.x = x / floatScalarToDivide;
	returnVector.y = y / floatScalarToDivide;

	return returnVector;
}

void FloatVector2::operator +=(float floatScalarToAdd)
{
	x = x + floatScalarToAdd;
	y = y + floatScalarToAdd;
}

void FloatVector2::operator -=(float floatScalarToSubtract)
{
	x = x - floatScalarToSubtract;
	y = y - floatScalarToSubtract;
}

void FloatVector2::operator *=(float floatScalarToMultiply)
{
	x = x * floatScalarToMultiply;
	y = y * floatScalarToMultiply;
}

void FloatVector2::operator /=(float floatScalarToDivide)
{
	x = x / floatScalarToDivide;
	y = y / floatScalarToDivide;
}