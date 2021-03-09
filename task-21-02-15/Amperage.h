#ifndef AMPERAGE_H
#define AMPERAGE_H

/* 1.3 Класс величины электрического тока */

class Amperage
{
public:

	Amperage(double _value) : value(_value) {};

	double getValue() const;
	void setValue(double _value) { value = _value; };

	int getAccessCounter() const { return accessCounter; };

private:

	mutable int accessCounter = 0;
	double value = 0;
};

#endif
