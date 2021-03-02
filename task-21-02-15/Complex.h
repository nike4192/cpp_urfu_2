#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:

	Complex(double r, double i);

	double getReal() const;
	double getImag() const;

	Complex conj() const; // conjugate
	
	/* Arithmetic */

	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

private:

	double real = 0;
	double imag = 0;
};

#endif
