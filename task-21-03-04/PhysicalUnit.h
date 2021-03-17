#pragma once

#include <iostream>

/* ≈сть иерархи€ классов физических величин из пункта 5 предыдущего задани€, имеющих общего предка */
class PhysicalUnit
{
	/* Ѕазовый класс не должен иметь полей */

public:

	/* ‘ункции скал€рного значени€ величины и его названи€ должны стать абстрактными в базовом классе */
	virtual double getScalarValue() const = 0;
	virtual std::string getUnitName() const = 0;
	virtual int getExponent() const = 0;

	virtual void setScalarValue(double) = 0;
	virtual void setUnitName(std::string) = 0;
	virtual void setExponent(int) = 0;

	/* ќписать операции сложени€/вычетани€/умножени€/делени€ через базовый интерфейс (использу€ dynamic_cast) */
	PhysicalUnit& operator+=(const PhysicalUnit& pu);
	PhysicalUnit& operator-=(const PhysicalUnit& pu);
	PhysicalUnit& operator*=(const PhysicalUnit& pu);
	PhysicalUnit& operator/=(const PhysicalUnit& pu);

	const PhysicalUnit& operator+(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator-(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator*(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator/(const PhysicalUnit& pu) const;
};
