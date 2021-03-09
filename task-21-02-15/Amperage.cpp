#include "Amperage.h"

double Amperage::getValue() const
{
	accessCounter++;

	return value;
}
