#pragma once

#ifndef _FLOAT_VECTOR_2_H
#define _FLOAT_VECTOR_2_H

class IntVector2;

class FloatVector2
{
	public:

		FloatVector2();
		FloatVector2(float xVal , float yVal);
		FloatVector2(int xVal , int yVal);
		FloatVector2(const FloatVector2& floatVectorToCopy);
		FloatVector2(const IntVector2& intVectorToCopy);
		~FloatVector2();

		FloatVector2 operator +(const FloatVector2& floatVectorToAdd) const;
		FloatVector2 operator -(const FloatVector2& floatVectorToSubtract) const;

		FloatVector2 operator +(float floatScalarToAdd) const;
		FloatVector2 operator -(float floatScalarToSubtract) const;
		FloatVector2 operator *(float floatScalarToMultiply) const;
		FloatVector2 operator /(float floatScalarToDivide) const;

		void operator +=(float floatScalarToAdd);
		void operator -=(float floatScalarToSubtract);
		void operator *=(float floatScalarToMultiply);
		void operator /=(float floatScalarToDivide);

		float DotProduct(const FloatVector2& vectorToDoWith) const;

	public:

		float x;
		float y;
};

#endif