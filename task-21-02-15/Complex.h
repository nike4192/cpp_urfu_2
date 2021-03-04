#ifndef COMPLEX_H
#define COMPLEX_H

/* 1.1 Класс комплексного числа */

class Complex
{
public:

	Complex(double r, double i);

	double getReal() const;
	double getImag() const;

	const Complex conj() const; // conjugate
	
	/* Arithmetic */

	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

private:

	double real = 0;
	double imag = 0;
};

#endif
