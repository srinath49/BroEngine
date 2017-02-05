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

	FloatVector3 operator+(int scalarToAdd) const;
	FloatVector3 operator-(int scalarToSubtract) const;
	FloatVector3 operator*(int scalarToMultiply) const;
	FloatVector3 operator/(int scalarToDivide) const;

	void operator+=(int scalarToAdd);
	void operator-=(int scalarToSubtract);
	void operator*=(int scalarToMultiply);
	void operator/=(int scalarToDivide);

	public:
		float x;
		float y;
		float z;

	
};

#endif#pragma once
