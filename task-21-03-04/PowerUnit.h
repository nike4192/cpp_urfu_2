#pragma once

#include "PhysicalUnit.h"

class PowerUnit : public PhysicalUnit
{
public:

	virtual double getScalarValue()  const { return value; };
	virtual std::string getUnitName() const { return unit; };
	virtual int getExponent() const { return exponent; };

	virtual void setScalarValue(double _value) { value = _value; };
	virtual void setUnitName(std::string _unit) { unit = _unit; };
	virtual void setExponent(int _exponent) { exponent = _exponent; };

	PowerUnit(double _value, int _exponent = 1) : value(_value), exponent(_exponent) {};

private:

	double value = 0;
	int exponent = 1;
	std::string unit = "N";
};

