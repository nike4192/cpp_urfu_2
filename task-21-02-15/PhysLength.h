#ifndef PHYSLENGTH_H
#define PHYSLENGTH_H

#include "PhysicalValue.h"

class PhysLength : public PhysicalValue
{
public:

	PhysLength(double _value) : PhysicalValue(PHYS_UNITS::m, _value) {};
};

#endif