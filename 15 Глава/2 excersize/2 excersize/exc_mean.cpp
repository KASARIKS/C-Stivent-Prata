#include "exc_mean.h"

// bad_hmean methods
bad_hmean::bad_hmean(double a, double b) : logic_error("Wrong values\n")
{
	v1 = a, v2 = b;
}

void bad_hmean::what()
{
	std::cout << std::string(logic_error::what());
}

// bad_gmean methods
bad_gmean::bad_gmean(double a, double b) : logic_error("Wrong values\n")
{
	v1 = a, v2 = b;
}

std::string bad_gmean::what()
{
	return std::string(logic_error::what());
}

