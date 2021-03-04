#ifndef PHYSFORCE_H
#define PHYSFORCE_H

#include "PhysicalValue.h"

/* 5.1 Величина силы в Ньютонах */

class PhysForce : public PhysicalValue
{
public:

	PhysForce(double _value) : PhysicalValue(PHYS_UNITS::N,_value) {};
};

#endif
