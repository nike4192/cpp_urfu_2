#ifndef Vector4_H
#define Vector4_H

/* 1.2 Класс 4-мерного вектора */

class Vector4
{
public:

	Vector4(double v) { x = y = z = w = v; }; // duplicate value
	Vector4(double _x, double _y, double _z, double _w) : x(_x), y(_y), z(_z), w(_w) {};

	double getX() const { return x; };
	double getY() const { return y; };
	double getZ() const { return z; };
	double getW() const { return w; };

	double length() const;

	double dot(const Vector4& v) const; // dot product
	const Vector4 normalize() const;

	/* Arithmetic */

	Vector4& operator+=(const Vector4& v);
	Vector4& operator-=(const Vector4& v);
	Vector4& operator*=(double s);
	Vector4& operator/=(double s);

	Vector4 operator+(const Vector4& v) const;
	Vector4 operator-(const Vector4& v) const;
	Vector4 operator*(double s) const;
	Vector4 operator/(double s) const;

private:

	double x, y, z, w;
};

#endif
