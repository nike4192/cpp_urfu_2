#include "Vector2.h"
#include <cmath>

double Vector2::dot(const Vector2& v) const
{
	return x * v.x + y * v.y;
}
/*
https://threejs.org/docs/index.html#api/en/math/Vector2.cross
Calculates the cross product of this vector and v. Note that a 'cross-product' in 2D is not well-defined.
This function computes a geometric cross-product often used in 2D graphics
*/
double Vector2::cross(const Vector2& v) const
{
	return x * v.y - y * v.x;
}

const Vector2 Vector2::normalize() const
{
	return Vector2(*this) /= length();
}

double Vector2::length() const
{
	return sqrt(x * x + y * y);
}

/* Arithmetic */

Vector2& Vector2::operator+=(const Vector2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vector2& Vector2::operator+=(double s)
{
	x += s;
	y += s;

	return *this;
}

Vector2& Vector2::operator-=(double s)
{
	x -= s;
	y -= s;

	return *this;
}

Vector2& Vector2::operator*=(double s)
{
	x *= s;
	y *= s;

	return *this;
}

Vector2& Vector2::operator/=(double s)
{
	x /= s;
	y /= s;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& v)
{
	return Vector2(*this) += v;
}

Vector2 Vector2::operator-(const Vector2& v)
{
	return Vector2(*this) -= v;
}

Vector2 Vector2::operator+(double s)
{
	return Vector2(*this) += s;
}

Vector2 Vector2::operator-(double s)
{
	return Vector2(*this) -= s;
}

Vector2 Vector2::operator*(double s)
{
	return Vector2(*this) *= s;
}

Vector2 Vector2::operator/(double s)
{
	return Vector2(*this) /= s;
}
