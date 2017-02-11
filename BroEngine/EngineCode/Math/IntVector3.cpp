#include "FloatVector3.hpp";
#include "IntVector3.hpp";
#include <math.h>

IntVector3::IntVector3()
	: x(0)
	, y(0)
	, z(0)
{
	
};

IntVector3::IntVector3(int xVal , int yVal , int zVal)
	: x(xVal)
	, y(yVal)
	, z(zVal)
{

};

IntVector3::IntVector3(float xVal , float yVal , float zVal)
	: x(xVal)
	, y(yVal)
	, z(zVal)
{

};

IntVector3::~IntVector3()
{

}

IntVector3::IntVector3(const IntVector3& vectorToCopy)
{
	x = vectorToCopy.x;
	y = vectorToCopy.y;
	z = vectorToCopy.z;
}

IntVector3::IntVector3(const FloatVector3& vectorToCopy) //After FloatVector3.hpp created
{
	x = (int)vectorToCopy.x;
	y = (int)vectorToCopy.y;
	z = (int)vectorToCopy.z;
}

IntVector3 IntVector3::operator +(const IntVector3& intVector3ToAdd) const
{
	IntVector3 resultVector3;

	resultVector3.x = x + intVector3ToAdd.x;
	resultVector3.y = y + intVector3ToAdd.y;
	resultVector3.z = z + intVector3ToAdd.z;

	return resultVector3;
}

IntVector3 IntVector3::operator -(const IntVector3& intVector3ToSubtract) const
{
	IntVector3 resultVector3;

	resultVector3.x = x - intVector3ToSubtract.x;
	resultVector3.y = y - intVector3ToSubtract.y;
	resultVector3.z = z - intVector3ToSubtract.z;

	return resultVector3;
}

IntVector3 IntVector3::operator *(const IntVector3& intVector3ToMultiply) const
{
	IntVector3 resultVector3;

	resultVector3.x = x * intVector3ToMultiply.x;
	resultVector3.y = y * intVector3ToMultiply.y;
	resultVector3.z = z * intVector3ToMultiply.z;

	return resultVector3;
}

IntVector3 IntVector3::operator /(const IntVector3& intVector3ToDivide) const
{
	IntVector3 resultVector3;

	resultVector3.x = x / intVector3ToDivide.x;
	resultVector3.y = y / intVector3ToDivide.y;
	resultVector3.z = z / intVector3ToDivide.z;

	return resultVector3;
}

IntVector3 IntVector3::operator +(int scalarToAdd) const
{
	IntVector3 resultVector3;

	resultVector3.x = x + scalarToAdd;
	resultVector3.y = y + scalarToAdd;
	resultVector3.z = z + scalarToAdd;

	return resultVector3;
}

IntVector3 IntVector3::operator -(int scalarToSubtract) const
{
	IntVector3 resultVector3;

	resultVector3.x = x - scalarToSubtract;
	resultVector3.y = y - scalarToSubtract;
	resultVector3.z = z - scalarToSubtract;

	return resultVector3;
}

IntVector3 IntVector3::operator *(int scalarToMultiply) const
{
	IntVector3 resultVector3;

	resultVector3.x = x * scalarToMultiply;
	resultVector3.y = y * scalarToMultiply;
	resultVector3.z = z * scalarToMultiply;

	return resultVector3;
}

IntVector3 IntVector3::operator /(int scalarToDivide) const
{
	IntVector3 resultVector3;

	resultVector3.x = x / scalarToDivide;
	resultVector3.y = y / scalarToDivide;
	resultVector3.z = z / scalarToDivide;

	return resultVector3;
}

void IntVector3::operator+=(int scalarToAdd)
{
	x = x + scalarToAdd;
	y = y + scalarToAdd;
	z = z + scalarToAdd;
}

void IntVector3::operator-=(int scalarToSubtract)
{
	x = x - scalarToSubtract;
	y = y - scalarToSubtract;
	z = z - scalarToSubtract;
}

void IntVector3::operator*=(int scalarToMultiply)
{
	x = x * scalarToMultiply;
	y = y * scalarToMultiply;
	z = z * scalarToMultiply;
}

void IntVector3::operator/=(int scalarToDivide)
{
	x = x / scalarToDivide;
	y = y / scalarToDivide;
	z = z / scalarToDivide;
}