#ifndef PHYSLENGTH_H
#define PHYSLENGTH_H

#include "PhysicalValue.h"

/* 5.3 Величина длины в метрах */

class PhysLength : public PhysicalValue
{
public:

	PhysLength(double _value) : PhysicalValue(PHYS_UNITS::m, _value) {};
};

#endif
