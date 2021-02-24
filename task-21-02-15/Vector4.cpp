#include <cmath>
#include "Vector4.h"

Vector4::Vector4(double v)
{
	x = y = z = w = v;
}

Vector4::Vector4(double _x, double _y, double _z, double _w) : x(_x), y(_y), z(_z), w(_w) {}

double Vector4::dot(Vector4& v)
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}

const Vector4 Vector4::normalize()
{
	return Vector4(*this) /= this->length();
}

double Vector4::length()
{
	return sqrt(x * x + y * y + z * z + w * w);
}

/* Arithmetic */

Vector4& Vector4::operator+=(Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;

	return *this;
}

Vector4& Vector4::operator-=(Vector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;

	return *this;
}

Vector4& Vector4::operator+=(double s)
{
	x += s;
	y += s;
	z += s;
	w += s;

	return *this;
}

Vector4& Vector4::operator-=(double s)
{
	x -= s;
	y -= s;
	z -= s;
	w -= s;

	return *this;
}

Vector4& Vector4::operator*=(double s)
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;

	return *this;
}

Vector4& Vector4::operator/=(double s)
{
	x /= s;
	y /= s;
	z /= s;
	w /= s;

	return *this;
}

const Vector4 Vector4::operator+(Vector4& v)
{
	return Vector4(*this) += v;
}

const Vector4 Vector4::operator-(Vector4& v)
{
	return Vector4(*this) -= v;
}

const Vector4 Vector4::operator+(double s)
{
	return Vector4(*this) += s;
}

const Vector4 Vector4::operator-(double s)
{
	return Vector4(*this) -= s;
}

const Vector4 Vector4::operator*(double s)
{
	return Vector4(*this) *= s;
}

const Vector4 Vector4::operator/(double s)
{
	return Vector4(*this) /= s;
}