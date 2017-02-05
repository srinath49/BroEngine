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

FloatVector3 FloatVector3::operator+(int scalarToAdd) const
{
	FloatVector3 returnVector3;

	returnVector3.x = x + scalarToAdd;
	returnVector3.y = y + scalarToAdd;
	returnVector3.z = z + scalarToAdd;

	return returnVector3;
}

FloatVector3 FloatVector3::operator-(int scalarToSubtract) const
{
	FloatVector3 returnVector3;

	returnVector3.y = y - scalarToSubtract;
	returnVector3.z = z - scalarToSubtract;
	returnVector3.x = x - scalarToSubtract;

	return returnVector3;
}

FloatVector3 FloatVector3::operator*(int scalarToMultiply) const
{
	FloatVector3 returnVector3;

	returnVector3.y = y * scalarToMultiply;
	returnVector3.z = z * scalarToMultiply;
	returnVector3.x = x * scalarToMultiply;

	return returnVector3;
}

FloatVector3 FloatVector3::operator/(int scalarToDivide) const
{
	FloatVector3 returnVector3;

	returnVector3.y = y / scalarToDivide;
	returnVector3.z = z / scalarToDivide;
	returnVector3.x = x / scalarToDivide;

	return returnVector3;
}