#include "IntVector3.hpp";
#include "FloatVector3.hpp";
#include <Math.h>

FloatVector3::FloatVector3()
	: x(0)
	, y(0)
	, z(0)
{

};

FloatVector3::FloatVector3(int xVal, int yVal, int zVal)
	: x(xVal)
	, y(yVal)
	, z(zVal)
{

};

FloatVector3::FloatVector3(float xVal, float yVal, float zVal)
	: x(xVal)
	, y(yVal)
	, z(zVal)
{

};

FloatVector3::~FloatVector3()
{

}

FloatVector3::FloatVector3(const FloatVector3& vectorToCopy)
{
	x = vectorToCopy.x;
	y = vectorToCopy.y;
	z = vectorToCopy.z;
}

FloatVector3::FloatVector3(const IntVector3& vectorToCopy)
{
	x = vectorToCopy.x;
	y = vectorToCopy.y;
	z = vectorToCopy.z;
}

FloatVector3 FloatVector3::operator+(const FloatVector3& vectorToAdd) const
{
	FloatVector3 returnVector3;

	returnVector3.x = x + vectorToAdd.x;
	returnVector3.y = y + vectorToAdd.y;
	returnVector3.z = z + vectorToAdd.z;

	return returnVector3;
}

FloatVector3 FloatVector3::operator-(const FloatVector3& vectorToSubtract) const
{
	FloatVector3 returnVector3;

	returnVector3.x = x - vectorToSubtract.x;
	returnVector3.y = y - vectorToSubtract.y;
	returnVector3.z = z - vectorToSubtract.z;

	return returnVector3;
}

FloatVector3 FloatVector3::operator+(float scalarToAdd) const
{
	FloatVector3 returnVector3;

	returnVector3.x = x + scalarToAdd;
	returnVector3.y = y + scalarToAdd;
	returnVector3.z = z + scalarToAdd;

	return returnVector3;
}

FloatVector3 FloatVector3::operator-(float scalarToSubtract) const
{
	FloatVector3 returnVector3;

	returnVector3.x = x - scalarToSubtract;
	returnVector3.y = y - scalarToSubtract;
	returnVector3.z = z - scalarToSubtract;

	return returnVector3;
}

FloatVector3 FloatVector3::operator*(float scalarToMultiply) const
{
	FloatVector3 returnVector3;

	returnVector3.x = x * scalarToMultiply;
	returnVector3.y = y * scalarToMultiply;
	returnVector3.z = z * scalarToMultiply;

	return returnVector3;
}

FloatVector3 FloatVector3::operator/(float scalarToDivide) const
{
	FloatVector3 returnVector3;

	returnVector3.x = x / scalarToDivide;
	returnVector3.y = y / scalarToDivide;
	returnVector3.z = z / scalarToDivide;

	return returnVector3;
}

void FloatVector3::operator+=(float scalarToAdd)
{
	x = x + scalarToAdd;
	y = y + scalarToAdd;
	z = z + scalarToAdd;
}

void FloatVector3::operator-=(float scalarToSubtract)
{
	x = x - scalarToSubtract;
	y = y - scalarToSubtract;
	z = z - scalarToSubtract;
}

void FloatVector3::operator*=(float scalarToMultiply)
{
	x = x * scalarToMultiply;
	y = y * scalarToMultiply;
	z = z * scalarToMultiply;
}

void FloatVector3::operator/=(float scalarToDivide)
{
	x = x / scalarToDivide;
	y = y / scalarToDivide;
	z = z / scalarToDivide;
}

float FloatVector3::DotProduct(const FloatVector3& vectorToDoWith) const
{
	float scalarResult;

	scalarResult = (x * vectorToDoWith.x) + (y * vectorToDoWith.y) + (z * vectorToDoWith.z);

	return scalarResult;
}

FloatVector3 FloatVector3::CrossProduct(const FloatVector3 & vectorToDoWith) const
{
	FloatVector3 resultVector;

	resultVector.x = y * vectorToDoWith.z - z * vectorToDoWith.y;
	resultVector.y = z * vectorToDoWith.x - x * vectorToDoWith.z;
	resultVector.z = x * vectorToDoWith.y - y * vectorToDoWith.x;

	return resultVector;
}
