#include <iostream>
#include <string>

#include "PowerUnit.h"
#include "LengthUnit.h"
#include "CustomException.h"

/* Написать функцию вывода величины в консоль, принимающую в качестве аргумента константную ссылку на величину */
std::ostream& operator<<(std::ostream& os, const PhysicalUnit& pu)
{
	os
		<< pu.getScalarValue()
		<< (pu.getExponent() != 0 ? pu.getUnitName() : "")
		<< (pu.getExponent() != 1 ?
				(pu.getExponent() != 0 ? std::to_string(pu.getExponent()) : "")
			: "");

	return os;
}

int main()
{
	PowerUnit p1(10);
	LengthUnit l1(16, 2);

	try {

		std::cout
			<< std::endl
			<< "Operations with PowerUnit"
			<< std::endl
			<< std::endl;

		std::cout << "p1 + p1: " << p1 + p1 << std::endl;
		std::cout << "p1 - p1: " << p1 - p1 << std::endl;
		std::cout << "p1 * p1: " << p1 * p1 << std::endl;
		std::cout << "p1 / p1: " << p1 / p1 << std::endl;

		std::cout
			<< std::endl
			<< "Operations with LengthUnit"
			<< std::endl
			<< std::endl;

		std::cout << "l1 + l1: " << l1 + l1 << std::endl;
		std::cout << "l1 - l1: " << l1 - l1 << std::endl;
		std::cout << "l1 * l1: " << l1 * l1 << std::endl;
		std::cout << "l1 / l1: " << l1 / l1 << std::endl;

		std::cout
			<< std::endl
			<< "Operations with PowerUnit and LengthUnit"
			<< std::endl
			<< std::endl;

		std::cout << "p1 / l1: " << p1 / l1 << std::endl;
		std::cout << "p1 * l1: " << p1 * l1 << std::endl; // throw error

	}
	catch (const std::exception& err)
	{
		std::cout
			<< "ATTENTION: ERROR "
			<< err.what()
			<< std::endl;
	}
}