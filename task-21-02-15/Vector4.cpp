#include <cmath>
#include "Vector4.h"

double Vector4::dot(const Vector4& v) const
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}

const Vector4 Vector4::normalize() const
{
	return Vector4(*this) /= this->length();
}

double Vector4::length() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

/* Arithmetic */

Vector4& Vector4::operator+=(const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;

	return *this;
}

Vector4& Vector4::operator-=(const Vector4& v)
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

Vector4 Vector4::operator+(const Vector4& v)
{
	return Vector4(*this) += v;
}

Vector4 Vector4::operator-(const Vector4& v)
{
	return Vector4(*this) -= v;
}

Vector4 Vector4::operator+(double s)
{
	return Vector4(*this) += s;
}

Vector4 Vector4::operator-(double s)
{
	return Vector4(*this) -= s;
}

Vector4 Vector4::operator*(double s)
{
	return Vector4(*this) *= s;
}

Vector4 Vector4::operator/(double s)
{
	return Vector4(*this) /= s;
}
