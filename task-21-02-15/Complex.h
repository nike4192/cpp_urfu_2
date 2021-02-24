#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double real;
	double imag;

public:
	Complex(double r, double i);

	double getReal() const;
	double getImag() const;

	Complex conj(); // conjugate

	Complex& operator+=(Complex& c);
	Complex& operator-=(Complex& c);
	Complex& operator*=(Complex& c);
	Complex& operator/=(Complex& c);

	const Complex operator+(Complex& c);
	const Complex operator-(Complex& c);
	const Complex operator*(Complex& c);
	const Complex operator/(Complex& c);

};

#endif