#include "exc_mean.h"
#include <string>

// bad_hmean methods
bad_hmean::bad_hmean(double a, double b) : info(a, b)
{
}

std::string bad_hmean::what()
{
	std::string msg(info::what());
	msg += "\nName: bad_hmean\nValues: " + std::to_string(v1) + " " + std::to_string(v2) + "\n";
	return msg;
}

// bad_gmean methods
bad_gmean::bad_gmean(double a, double b) : info(a, b)
{
}

std::string bad_gmean::what()
{
	std::string msg(info::what());
	msg += "\nName: bad_gmean\nValues: " + std::to_string(v1) + " " + std::to_string(v2) + "\n";
	return msg;
}

// info methods
info::info(double a, double b) : logic_error("Wrong values!\n")
{
	v1 = a, v2 = b;
}

std::string info::what()
{
	return std::string("Wrong values!\n");
}
