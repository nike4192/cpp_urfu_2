#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double real = 0;
	double imag = 0;

public:
	Complex(double r, double i);

	double getReal() const;
	double getImag() const;

	Complex conj() const; // conjugate

	Complex& operator+=(Complex& c) const;
	Complex& operator-=(Complex& c) const;
	Complex& operator*=(Complex& c) const;
	Complex& operator/=(Complex& c) const;

	const Complex operator+(Complex& c);
	const Complex operator-(Complex& c);
	const Complex operator*(Complex& c);
	const Complex operator/(Complex& c);

};

#endif
