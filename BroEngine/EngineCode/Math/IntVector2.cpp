#include "IntVector2.hpp"
#include <math.h>

IntVector2::IntVector2(int xVal, int yVal)
	: x(xVal)
	, y(yVal)
{
	
}

IntVector2::~IntVector2()
{

}

IntVector2::IntVector2(const IntVector2& vectorToCopy)
{
	x = vectorToCopy.x;
	y = vectorToCopy.y;
}

IntVector2 IntVector2::operator+(const IntVector2& vectorToAdd) const
{
	IntVector2 returnVector;
	returnVector.x = x + vectorToAdd.x;
	returnVector.y = y + vectorToAdd.y;
	return returnVector;
}

IntVector2 IntVector2::operator-(const IntVector2& vectorToSubtract) const
{
	IntVector2 returnVector;
	returnVector.x = x - vectorToSubtract.x;
	returnVector.y = y - vectorToSubtract.y;
	return returnVector;
}

IntVector2 IntVector2::operator+(int scalarIntToAdd) const
{
	IntVector2 returnVector;
	returnVector.x = x + scalarIntToAdd;
	returnVector.y = y + scalarIntToAdd;
	return returnVector;
}

IntVector2 IntVector2::operator-(int scalarIntToSubtract) const
{
	IntVector2 returnVector;
	returnVector.x = x - scalarIntToSubtract;
	returnVector.y = y - scalarIntToSubtract;
	return returnVector;
}

IntVector2 IntVector2::operator/(int scalarIntToDivide) const
{
	IntVector2 returnVector;
	returnVector.x = x / scalarIntToDivide;
	returnVector.y = y / scalarIntToDivide;
	return returnVector;
}

IntVector2 IntVector2::operator*(int scalarIntToMultiply) const
{
	IntVector2 returnVector;
	returnVector.x = x * scalarIntToMultiply;
	returnVector.y = y * scalarIntToMultiply;
	return returnVector;
}

int IntVector2::DotProduct(const IntVector2& vectorToDotWIth) const
{
	int dotProduct;
	dotProduct = x*vectorToDotWIth.x + y*vectorToDotWIth.y;
	return dotProduct;
}

int IntVector2::GetMagnitudeOfThisVector() const
{
	int magnitude;
	magnitude = sqrtf((x*x + y*y));
	return magnitude;
}

void IntVector2::NormalizeThisVector()
{
	int mag = GetMagnitudeOfThisVector();
	x /= mag;
	y /= mag;
}

IntVector2 IntVector2::GetNormalizedVector() const
{
	IntVector2 normalizedVector;
	int magOfThisVector = GetMagnitudeOfThisVector();
	normalizedVector = *this / magOfThisVector;
	return normalizedVector;
}