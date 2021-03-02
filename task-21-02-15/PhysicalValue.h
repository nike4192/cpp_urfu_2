#ifndef PHYSICALVALUE_H
#define PHYSICALVALUE_H

#include <iostream>
#include <map>

const enum PHYS_UNITS{ N, Pa, m, J };

class PhysicalValue
{
protected:

	enum PHYS_UNITS unit;
	double value = 0;
	int exponent = 1;

	PhysicalValue(enum PHYS_UNITS _unit, double _value) : unit(_unit), value(_value) {};

public:

	enum PHYS_UNITS getUnit() const { return unit; }
	double getValue() const { return value; }
	int getExponent() const { return exponent; }

	/* Arithmetic */

	PhysicalValue& operator+=(const PhysicalValue& pv);
	PhysicalValue& operator-=(const PhysicalValue& pv);
	PhysicalValue& operator*=(const PhysicalValue& pv);
	PhysicalValue& operator/=(const PhysicalValue& pv);

	PhysicalValue operator+(const PhysicalValue& pv);
	PhysicalValue operator-(const PhysicalValue& pv);
	PhysicalValue operator*(const PhysicalValue& pv);
	PhysicalValue operator/(const PhysicalValue& pv);

	PhysicalValue(double _value) : value(_value) {};
	void print() const;
};

#endif
