#ifndef PHYSFORCE_H
#define PHYSFORCE_H

#include "PhysicalValue.h"

class PhysForce : public PhysicalValue
{
public:

	PhysForce(double _value) : PhysicalValue(PHYS_UNITS::N,_value) {};
};

#endif
