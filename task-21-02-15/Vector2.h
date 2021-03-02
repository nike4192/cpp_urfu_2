#ifndef Vector2_H
#define Vector2_H

class Vector2
{
public:

	Vector2(double _x, double _y) : x(_x), y(_y) {};

	double getX() const { return x; };
	double getY() const { return y; };

	double length() const;

	double dot(const Vector2& v) const; // dot product
	double cross(const Vector2& v) const; // cross product
	const Vector2 normalize() const;

	/* Arithmetic */

	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator+=(double s);
	Vector2& operator-=(double s);
	Vector2& operator*=(double s);
	Vector2& operator/=(double s);

	Vector2 operator+(const Vector2& v);
	Vector2 operator-(const Vector2& v);
	Vector2 operator+(double s);
	Vector2 operator-(double s);
	Vector2 operator*(double s);
	Vector2 operator/(double s);

private:

	double x, y;

};

#endif
