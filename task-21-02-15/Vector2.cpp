#include "Vector2.h"
#include <cmath>

Vector2::Vector2(double _x, double _y) : x(_x), y(_y) {}

double Vector2::dot(Vector2& v)
{
	return x * v.x + y * v.y;
}
/* https://gamedev.ru/flame/forum/?id=121324
	  | i j k |
AxB = | x y 0 | = ( 0, 0, x*Y - y*X ) ~ x*Y - y*X
	  | X Y 0 |
*/
double Vector2::cross(Vector2& v)
{
	return x * v.y - y * v.x;
}

const Vector2 Vector2::normalize()
{
	return Vector2(*this) /= this->length();
}

double Vector2::length()
{
	return pow(x * x + y * y, 1 / 2);
}

/* Arithmetic */

Vector2& Vector2::operator+=(Vector2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vector2& Vector2::operator-=(Vector2& v)
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

const Vector2 Vector2::operator+(Vector2& v)
{
	return Vector2(*this) += v;
}

const Vector2 Vector2::operator-(Vector2& v)
{
	return Vector2(*this) -= v;
}

const Vector2 Vector2::operator+(double s)
{
	return Vector2(*this) += s;
}

const Vector2 Vector2::operator-(double s)
{
	return Vector2(*this) -= s;
}

const Vector2 Vector2::operator*(double s)
{
	return Vector2(*this) *= s;
}

const Vector2 Vector2::operator/(double s)
{
	return Vector2(*this) /= s;
}