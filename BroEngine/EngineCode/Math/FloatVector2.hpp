#pragma once

#ifndef _FLOAT_VECTOR_2_H
#define _FLOAT_VECTOR_2_H

class FloatVector2
{
	public:

		FloatVector2(float xVal = 0.0f , float yVal = 0.0f);
		~FloatVector2();

		FloatVector2(const FloatVector2& floatToCopy);

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

	public:

		float x;
		float y;
};

#endif