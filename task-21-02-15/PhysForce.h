#pragma once

#include "PhysicalValue.h"

template<typename T>
class PhysForce : PhysicalValue<T>
{
private:
	PHYSICAL_UNITS unit = PHYSICAL_UNITS::N;

public:
	PhysForce(T value);
};