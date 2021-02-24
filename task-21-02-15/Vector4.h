#ifndef Vector4_H
#define Vector4_H

class Vector4
{
public:
	double x, y, z, w;

	Vector4(double v); // duplicate value
	Vector4(double _x, double _y, double _z, double _w);

	double length();

	double dot(Vector4& v); // dot product
	const Vector4 normalize();

	/* Arithmetic */

	Vector4& operator+=(Vector4& v);
	Vector4& operator-=(Vector4& v);
	Vector4& operator+=(double s);
	Vector4& operator-=(double s);
	Vector4& operator*=(double s);
	Vector4& operator/=(double s);

	const Vector4 operator+(Vector4& v);
	const Vector4 operator-(Vector4& v);
	const Vector4 operator+(double s);
	const Vector4 operator-(double s);
	const Vector4 operator*(double s);
	const Vector4 operator/(double s);

};

#endif