#include "Complex.h"

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

Complex Complex::conj() const
{
	return Complex(real, -imag);
}

Complex& Complex::operator+=(const Complex& c)
{
	real += c.real;
	imag += c.imag;

	return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
	real -= c.real;
	imag -= c.imag;

	return *this;
}

Complex& Complex::operator*=(const Complex& c)
{
	double t_real = real * c.real - imag * c.imag;
	double t_imag = real * c.imag + imag * c.real;

	real = t_real;
	imag = t_imag;

	return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
	double denom = c.real * c.real + c.imag * c.imag;

	double t_real = (real * c.real + imag * c.imag) / denom;
	double t_imag = (c.real * imag - real * c.imag) / denom;

	real = t_real;
	imag = t_imag;

	return *this;
}

Complex Complex::operator+(const Complex& c)
{
	return Complex(*this) += c;
}

Complex Complex::operator-(const Complex& c)
{
	return Complex(*this) -= c;
}

Complex Complex::operator*(const Complex& c)
{
	return Complex(*this) *= c;
}

Complex Complex::operator/(const Complex& c)
{
	return Complex(*this) /= c;
}
