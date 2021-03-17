#pragma once

#include <iostream>

/* Есть иерархия классов физических величин из пункта 5 предыдущего задания, имеющих общего предка */
class PhysicalUnit
{
	/* Базовый класс не должен иметь полей */

public:

	/* Функции скалярного значения величины и его названия должны стать абстрактными в базовом классе */
	virtual double getScalarValue() const = 0;
	virtual std::string getUnitName() const = 0;
	virtual int getExponent() const = 0;

	virtual void setScalarValue(double) = 0;
	virtual void setUnitName(std::string) = 0;
	virtual void setExponent(int) = 0;

	/* Описать операции сложения/вычетания/умножения/деления через базовый интерфейс (используя dynamic_cast) */
	PhysicalUnit& operator+=(const PhysicalUnit& pu);
	PhysicalUnit& operator-=(const PhysicalUnit& pu);
	PhysicalUnit& operator*=(const PhysicalUnit& pu);
	PhysicalUnit& operator/=(const PhysicalUnit& pu);

	const PhysicalUnit& operator+(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator-(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator*(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator/(const PhysicalUnit& pu) const;
};
