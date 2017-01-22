#pragma once

#ifndef _INT_VECTOR_2_H
#define _INT_VECTOR_2_H

class IntVector2
{
public:
	IntVector2(int xVal = 0, int yVal = 0);
	~IntVector2();

	IntVector2(const IntVector2& vectorToCopy);

	IntVector2 operator +(const IntVector2& vectorToAdd) const;
	IntVector2 operator -(const IntVector2& vectorToSubtract) const;
	IntVector2 operator +(int scalarIntToAdd) const;
	IntVector2 operator -(int scalarIntToSubtract) const;
	IntVector2 operator *(int scalarIntToMultiply) const;
	IntVector2 operator /(int scalarIntToDivide) const;

	int DotProduct(const IntVector2& vectorToDotWIth) const;

	/*
	operator	+= vector
	operator	-= vector
	operator	+= scalar
	operator	-= scalar
	operator	*= scalar
	operator	/= scalar

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