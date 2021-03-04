#include "Amperage.h"

double Amperage::getValue()
{
	accessCounter++;

	return value;
}
