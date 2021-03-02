#ifndef AMPERAGE_H
#define AMPERAGE_H

class Amperage
{
public:

	Amperage(double _value) : value(_value) {};

	double getValue();
	void setValue(double _value) { value = _value; };

	int getAccessCounter() const { return accessCounter; };

private:

	int accessCounter = 0;
	double value = 0;
};

#endif