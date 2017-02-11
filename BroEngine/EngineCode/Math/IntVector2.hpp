#pragma once

#ifndef _INT_VECTOR_2_H
#define _INT_VECTOR_2_H
class FloatVector2;

class IntVector2
{
public:
	IntVector2();
	IntVector2(int xVal , int yVal);
	IntVector2(float xVal , float yVal);
	IntVector2(const IntVector2& vectorToCopy);
	IntVector2(const FloatVector2& vectorToCopy);
	~IntVector2();

	IntVector2 operator +(const IntVector2& vectorToAdd) const;
	void operator += (const IntVector2& vectorToAdd);
	void operator -= (const IntVector2& vectorToSubtract);
	IntVector2 operator -(const IntVector2& vectorToSubtract) const;
	IntVector2 operator +(int scalarIntToAdd) const;
	void operator +=(int scalarIntToAdd);
	void operator -=(int scalarIntToSubtract);
	void operator *=(int scalarIntToMultiply);
	void operator /=(int scalarIntToDivide);
	IntVector2 operator -(int scalarIntToSubtract) const;
	IntVector2 operator *(int scalarIntToMultiply) const;
	IntVector2 operator /(int scalarIntToDivide) const;

	int DotProduct(const IntVector2& vectorAToDotWIth , const IntVector2& vectorBToDotWIth) const;

	/*
	CrossProduct Returning new Vector
	CrossProduct modifying this vector
	*/

	int				GetMagnitudeOfThisVector() const;
	IntVector2		GetNormalizedVector() const;
	void			NormalizeThisVector();

public:
	int		x;
	int		y;
};


#endif