#ifndef Vector2_H
#define Vector2_H

class Vector2
{
public:

	double x, y;

	Vector2(double _x, double _y);

	double length();

	double dot(Vector2& v); // dot product
	double cross(Vector2& v); // cross product
	const Vector2 normalize();

	/* Arithmetic */

	Vector2& operator+=(Vector2& v);
	Vector2& operator-=(Vector2& v);
	Vector2& operator+=(double s);
	Vector2& operator-=(double s);
	Vector2& operator*=(double s);
	Vector2& operator/=(double s);

	const Vector2 operator+(Vector2& v);
	const Vector2 operator-(Vector2& v);
	const Vector2 operator+(double s);
	const Vector2 operator-(double s);
	const Vector2 operator*(double s);
	const Vector2 operator/(double s);

};

#endif