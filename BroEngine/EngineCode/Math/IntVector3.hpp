#pragma once
#ifndef _INT_VECTOR_3_H
#define _INT_VECTOR_3_H

class FloatVector3;

class IntVector3
{
	public:
		IntVector3();
		IntVector3(int xVal , int yVal , int zVal);
		IntVector3(float xVal, float yVal, float zVal);
		IntVector3(const IntVector3& vectorToCopy);
		IntVector3(const FloatVector3& vectorToCopy);
		~IntVector3();

		IntVector3 operator +(const IntVector3& intVector3ToAdd) const;
		IntVector3 operator -(const IntVector3& intVector3ToSubtract) const;
		IntVector3 operator *(const IntVector3& intVector3ToMultiply) const;
		IntVector3 operator /(const IntVector3& intVector3ToDivide) const;

		IntVector3 operator +(int scalarToAdd) const;
		IntVector3 operator -(int scalarToSubtract) const;
		IntVector3 operator *(int scalarToMultiply) const;
		IntVector3 operator /(int scalarToDivide) const;
		void operator += (int scalarToAdd);
		void operator -= (int scalarToSubtract);
		void operator *= (int scalarToMultiply);
		void operator /= (int scalarToDivide);

		int DotProduct(const IntVector3& vectorToDoWith) const;
		IntVector3 CrossProduct(const IntVector3& vectorToDoWith) const;
		

	public:
		int x;
		int y;
		int z;

};

#endif