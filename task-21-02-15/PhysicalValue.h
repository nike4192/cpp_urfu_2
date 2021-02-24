#ifndef PHYSICALVALUE_H
#define PHYSICALVALUE_H

enum PHYSICAL_UNITS { N, Pa, m2 };

template<typename T>
class PhysicalValue
{
protected:
	PHYSICAL_UNITS unit;
	T value;

public:
	PhysicalValue(T _value);
};

#endif