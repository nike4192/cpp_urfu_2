#ifndef PHYSICALVALUE_H
#define PHYSICALVALUE_H

#include <iostream>
#include <map>

/* 5 Общий интерфейс для классов физических величин */

const enum PHYS_UNITS{ N, Pa, m, J };

class PhysicalValue
{
public:

	enum PHYS_UNITS getUnit() const { return unit; }
	double getValue() const { return value; }
	int getExponent() const { return exponent; }

	/* Arithmetic */

	/* 5.6 Осуществления с ними операций сложения/вычитания/умножения/деления через базовый интерфейс без dynamic_cast */
	PhysicalValue& operator+=(const PhysicalValue& pv);
	PhysicalValue& operator-=(const PhysicalValue& pv);
	PhysicalValue& operator*=(const PhysicalValue& pv);
	PhysicalValue& operator/=(const PhysicalValue& pv);

	PhysicalValue operator+(const PhysicalValue& pv) const;
	PhysicalValue operator-(const PhysicalValue& pv) const;
	PhysicalValue operator*(const PhysicalValue& pv) const;
	PhysicalValue operator/(const PhysicalValue& pv) const;

	PhysicalValue(double _value) : value(_value) {};

	/* 5.4.	Вывод с общего интерфейса величин и их наименований. */
	void print() const;

protected:

	enum PHYS_UNITS unit;
	double value = 0;
	int exponent = 1;

	PhysicalValue(enum PHYS_UNITS _unit, double _value) : unit(_unit), value(_value) {};
};

#endif
