#pragma once

#ifndef _FLOAT_VECTOR_3_H
#define _FLOAT_VECTOR_3_H

class IntVector3;

class FloatVector3
{

public:
	FloatVector3();
	FloatVector3(int xVal , int yVal , int zVal);
	FloatVector3(float xVal , float yVal , float zVal);
	FloatVector3(const FloatVector3& floatVectorToCopy);
	FloatVector3(const IntVector3& intVectorToCopy);
	~FloatVector3();

	FloatVector3 operator+(const FloatVector3& vectorToAdd) const;
	FloatVector3 operator-(const FloatVector3& vectorToSubtract) const;

	FloatVector3 operator+(float scalarToAdd) const;
	FloatVector3 operator-(float scalarToSubtract) const;
	FloatVector3 operator*(float scalarToMultiply) const;
	FloatVector3 operator/(float scalarToDivide) const;

	void operator+=(float scalarToAdd);
	void operator-=(float scalarToSubtract);
	void operator*=(float scalarToMultiply);
	void operator/=(float scalarToDivide);

	float DotProduct(const FloatVector3& vectorToDoWith) const;

	FloatVector3 CrossProduct(const FloatVector3& vectorToDoWith) const;

	public:
		float x;
		float y;
		float z;

	
};

#endif#pragma once
