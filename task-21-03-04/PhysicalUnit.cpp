#include "PhysicalUnit.h"
#include "CustomException.h"

#include "PowerUnit.h"
#include "LengthUnit.h"
#include "PressureUnit.h"

#include <string>
#include <iostream>

PhysicalUnit& PhysicalUnit::operator+=(const PhysicalUnit& pu)
{
	auto leftPup = dynamic_cast<PowerUnit*>(this);
	auto rightPup = dynamic_cast<PowerUnit*>(const_cast<PhysicalUnit*>(&pu));

	auto leftLup = dynamic_cast<LengthUnit*>(this);
	auto rightLup = dynamic_cast<LengthUnit*>(const_cast<PhysicalUnit*>(&pu));

	double left, right;

	if (((leftPup && rightPup) || (leftLup && rightLup)) &&
		(getExponent() == pu.getExponent()))
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		setScalarValue(left + right);

		return *this;
	}
	else
	{
		throw CustomException(getUnitName() + std::to_string(getExponent()) + " and " + pu.getUnitName() + std::to_string(pu.getExponent()) + " cannot be added");
	}
}

PhysicalUnit& PhysicalUnit::operator-=(const PhysicalUnit& pu)
{
	auto leftPup = dynamic_cast<PowerUnit*>(this);
	auto rightPup = dynamic_cast<PowerUnit*>(const_cast<PhysicalUnit*>(&pu));

	auto leftLup = dynamic_cast<LengthUnit*>(this);
	auto rightLup = dynamic_cast<LengthUnit*>(const_cast<PhysicalUnit*>(&pu));

	double left, right;

	if (((leftPup && rightPup) || (leftLup && rightLup)) &&
		(getExponent() == pu.getExponent()))
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		setScalarValue(left - right);

		return *this;
	}
	else
	{
		throw CustomException(getUnitName() + std::to_string(getExponent()) + " and " + pu.getUnitName() + std::to_string(pu.getExponent()) + " cannot be substraction");
	}
}

PhysicalUnit& PhysicalUnit::operator*=(const PhysicalUnit& pu)
{
	auto leftPup = dynamic_cast<PowerUnit*>(this);
	auto rightPup = dynamic_cast<PowerUnit*>(const_cast<PhysicalUnit*>(&pu));

	auto leftLup = dynamic_cast<LengthUnit*>(this);
	auto rightLup = dynamic_cast<LengthUnit*>(const_cast<PhysicalUnit*>(&pu));

	double left, right;

	if ((leftPup && rightPup) || (leftLup && rightLup))
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		setScalarValue(left * right);
		setExponent(getExponent() + pu.getExponent());

		return *this;
	}
	else if (leftPup && rightLup && // Pa = N * m^-2
		(getExponent() / 1 == pu.getExponent() / -2)) // кратные степеням 1 и -2 (Pa2 = N2 * m^-4)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		setScalarValue(left * right);
		setExponent(getExponent());
		setUnitName("Pa");

		return *this;
	}
	else
	{
		throw CustomException(getUnitName() + std::to_string(getExponent()) + " and " + pu.getUnitName() + std::to_string(pu.getExponent()) + " cannot be multiplied");
	}
}

PhysicalUnit& PhysicalUnit::operator/=(const PhysicalUnit& pu)
{
	auto leftPup = dynamic_cast<PowerUnit*>(this);
	auto rightPup = dynamic_cast<PowerUnit*>(const_cast<PhysicalUnit*>(&pu));

	auto leftLup = dynamic_cast<LengthUnit*>(this);
	auto rightLup = dynamic_cast<LengthUnit*>(const_cast<PhysicalUnit*>(&pu));

	double left, right;

	if (leftPup && rightPup)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		setScalarValue(left / right);
		setExponent(getExponent() - pu.getExponent());

		return *this;
	}
	else if (leftPup && rightLup && // Pa = N / m2
		(getExponent() / 1 == pu.getExponent() / 2)) // кратные степеням 1 и 2 (Pa2 = N2 / m4)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		setScalarValue(left / right);
		setExponent(getExponent());
		setUnitName("Pa");

		return *this;
	}
	else
	{
		throw CustomException(getUnitName() + std::to_string(getExponent()) + " and " + pu.getUnitName() + std::to_string(pu.getExponent()) + " cannot be devided");
	}
}

const PhysicalUnit& PhysicalUnit::operator+(const PhysicalUnit& pu) const
{
	auto constCastLeft = const_cast<PhysicalUnit*>(this);
	auto constCastRight = const_cast<PhysicalUnit*>(&pu);

	auto leftPup = dynamic_cast<PowerUnit*>(constCastLeft);
	auto rightPup = dynamic_cast<PowerUnit*>(constCastRight);

	auto leftLup = dynamic_cast<LengthUnit*>(constCastLeft);
	auto rightLup = dynamic_cast<LengthUnit*>(constCastRight);

	double left, right;

	if (((leftPup && rightPup) && (getExponent() == pu.getExponent())))
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new PowerUnit(left + right, getExponent());

		return *result;
	}
	else if (((leftLup && rightLup) && (getExponent() == pu.getExponent())))
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new LengthUnit(left + right);

		return *result;
	}
	else
	{
		throw CustomException(getUnitName() + std::to_string(getExponent()) + " and " + pu.getUnitName() + std::to_string(pu.getExponent()) + " cannot be added");
	}
}

const PhysicalUnit& PhysicalUnit::operator-(const PhysicalUnit& pu) const
{
	auto constCastLeft = const_cast<PhysicalUnit*>(this);
	auto constCastRight = const_cast<PhysicalUnit*>(&pu);

	auto leftPup = dynamic_cast<PowerUnit*>(constCastLeft);
	auto rightPup = dynamic_cast<PowerUnit*>(constCastRight);

	auto leftLup = dynamic_cast<LengthUnit*>(constCastLeft);
	auto rightLup = dynamic_cast<LengthUnit*>(constCastRight);

	double left, right;

	if (((leftPup && rightPup) && (getExponent() == pu.getExponent())))
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new PowerUnit(left - right, getExponent());

		return *result;
	}
	else if (((leftLup && rightLup) && (getExponent() == pu.getExponent())))
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new LengthUnit(left - right);

		return *result;
	}
	else
	{
		throw CustomException(getUnitName() + std::to_string(getExponent()) + " and " + pu.getUnitName() + std::to_string(pu.getExponent()) + " cannot be substraction");
	}
}

const PhysicalUnit& PhysicalUnit::operator*(const PhysicalUnit& pu) const
{
	auto constCastLeft = const_cast<PhysicalUnit*>(this);
	auto constCastRight = const_cast<PhysicalUnit*>(&pu);

	auto leftPup = dynamic_cast<PowerUnit*>(constCastLeft);
	auto rightPup = dynamic_cast<PowerUnit*>(constCastRight);

	auto leftLup = dynamic_cast<LengthUnit*>(constCastLeft);
	auto rightLup = dynamic_cast<LengthUnit*>(constCastRight);

	double left, right;

	if (leftPup && rightPup)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new PowerUnit(left * right, getExponent() + pu.getExponent());

		return *result;
	}
	else if (leftLup && rightLup)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new LengthUnit(left * right, getExponent() + pu.getExponent());

		return *result;
	}
	else if (leftPup && rightLup && // Pa = N * m^-2
		(getExponent() / 1 == pu.getExponent() / -2)) // кратные степеням 1 и -2 (Pa2 = N2 * m^-4)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new PressureUnit(left * right, getExponent());

		return *result;
	}
	else
	{
		throw CustomException(getUnitName() + std::to_string(getExponent()) + " and " + pu.getUnitName() + std::to_string(pu.getExponent()) + " cannot be multiplied");
	}
}

const PhysicalUnit& PhysicalUnit::operator/(const PhysicalUnit& pu) const
{
	auto constCastLeft = const_cast<PhysicalUnit*>(this);
	auto constCastRight = const_cast<PhysicalUnit*>(&pu);

	auto leftPup = dynamic_cast<PowerUnit*>(constCastLeft);
	auto rightPup = dynamic_cast<PowerUnit*>(constCastRight);

	auto leftLup = dynamic_cast<LengthUnit*>(constCastLeft);
	auto rightLup = dynamic_cast<LengthUnit*>(constCastRight);

	double left, right;

	if (leftPup && rightPup)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new PowerUnit(left / right, getExponent() - pu.getExponent());

		return *result;
	}
	else if (leftLup && rightLup)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new LengthUnit(left / right, getExponent() - pu.getExponent());

		return *result;
	}
	else if (leftPup && rightLup && // Pa = N * m^-2
		(getExponent() / 1 == pu.getExponent() / 2)) // кратные степеням 1 и -2 (Pa2 = N2 * m^-4)
	{
		left = getScalarValue();
		right = pu.getScalarValue();

		auto result = new PressureUnit(left / right, getExponent());

		return *result;
	}
	else
	{
		throw CustomException(getUnitName() + std::to_string(getExponent()) + " and " + pu.getUnitName() + std::to_string(pu.getExponent()) + " cannot be devided");
	}
}
