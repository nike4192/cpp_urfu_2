#pragma once

#include <iostream>

/* ���� �������� ������� ���������� ������� �� ������ 5 ����������� �������, ������� ������ ������ */
class PhysicalUnit
{
	/* ������� ����� �� ������ ����� ����� */

public:

	/* ������� ���������� �������� �������� � ��� �������� ������ ����� ������������ � ������� ������ */
	virtual double getScalarValue() const = 0;
	virtual std::string getUnitName() const = 0;
	virtual int getExponent() const = 0;

	virtual void setScalarValue(double) = 0;
	virtual void setUnitName(std::string) = 0;
	virtual void setExponent(int) = 0;

	/* ������� �������� ��������/���������/���������/������� ����� ������� ��������� (��������� dynamic_cast) */
	PhysicalUnit& operator+=(const PhysicalUnit& pu);
	PhysicalUnit& operator-=(const PhysicalUnit& pu);
	PhysicalUnit& operator*=(const PhysicalUnit& pu);
	PhysicalUnit& operator/=(const PhysicalUnit& pu);

	const PhysicalUnit& operator+(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator-(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator*(const PhysicalUnit& pu) const;
	const PhysicalUnit& operator/(const PhysicalUnit& pu) const;
};
