#include "PhysicalValue.h"

#include <iostream>
#include <vector>
#include <string>

std::map<PHYS_UNITS, std::string> PHYS_UNITS_MAP
{
	{PHYS_UNITS::N, "N"}, // Newton
	{PHYS_UNITS::Pa, "Pa"}, // Pascal
	{PHYS_UNITS::m, "m"}, // meter

	// Additionaly
	{PHYS_UNITS::J, "J"} // Joule
};

typedef std::pair<PHYS_UNITS, int> phys_value_pair;

typedef std::pair<
	phys_value_pair, // Left product phys value pair
	phys_value_pair> // Right product phys value pair
	derive_key;

std::map<derive_key, phys_value_pair> product_derive_map
{
	{
		{ {PHYS_UNITS::N, 1}, {PHYS_UNITS::m, -2} }, {PHYS_UNITS::Pa, 1} // Pa = N / m2
	},
	{
		{ {PHYS_UNITS::N, 1}, {PHYS_UNITS::m, 1} }, {PHYS_UNITS::J, 1} // J = N * m
	}
};

PhysicalValue& PhysicalValue::operator+=(const PhysicalValue& pv)
{
	if (unit == pv.unit && exponent == pv.exponent)
	{
		value += pv.value;

		return *this;
	}
	else
	{
		throw std::exception("Wrong add");
	}
}

PhysicalValue& PhysicalValue::operator-=(const PhysicalValue& pv)
{
	if (unit == pv.unit && exponent == pv.exponent)
	{
		value -= pv.value;

		return *this;

	}
	else
	{
		throw std::exception("Wrong minus");
	}
}

PhysicalValue& PhysicalValue::operator*=(const PhysicalValue& pv)
{
	if (unit == pv.unit)
	{
		value *= pv.value;
		exponent += pv.exponent; // product rule of exponents

		return *this;
	}
	else
	{
		throw std::exception("Wrong product");
	}
}

PhysicalValue& PhysicalValue::operator/=(const PhysicalValue& pv)
{
	if (unit == pv.unit)
	{
		value /= pv.value;
		exponent -= pv.exponent; // product rule of exponents

		return *this;
	}
	else
	{
		throw std::exception("Wrong devide");
	}
}

PhysicalValue PhysicalValue::operator+(const PhysicalValue& pv) const
{
	return PhysicalValue(unit, value) += pv;
}

PhysicalValue PhysicalValue::operator-(const PhysicalValue& pv) const
{
	return PhysicalValue(unit, value) -= pv;
}

PhysicalValue PhysicalValue::operator*(const PhysicalValue& pv) const
{
	if (unit != pv.unit) {

		derive_key pdk = { {unit, exponent}, {pv.unit, pv.exponent} };

		auto search = product_derive_map.find(pdk);
		if (search != product_derive_map.end())
		{
			auto searchUnit = search->second.first;
			auto searchExponent = search->second.second;

			PhysicalValue rpv(searchUnit, value * pv.value);

			rpv.exponent = searchExponent;

			return rpv;
		}
		else
		{
			throw std::exception("Wrong product");
		}
	}
	else
	{
		return PhysicalValue(*this) *= pv;
	}
}

PhysicalValue PhysicalValue::operator/(const PhysicalValue& pv) const
{
	if (unit != pv.unit) {

		derive_key pdk = { {unit, exponent}, {pv.unit, -pv.exponent} };

		auto search = product_derive_map.find(pdk);
		if (search != product_derive_map.end())
		{
			auto searchUnit = search->second.first;
			auto searchExponent = search->second.second;

			PhysicalValue rpv(searchUnit, value / pv.value);

			rpv.exponent = searchExponent;

			return rpv;
		}
		else
		{
			throw std::exception("Wrong devide");
		}
	}
	else
	{
		return PhysicalValue(*this) *= pv;
	}
}

void PhysicalValue::print() const
{
	std::cout
		<< value
		<< PHYS_UNITS_MAP[unit]
		<< (exponent != 1 ? std::to_string(exponent) : "");
}
