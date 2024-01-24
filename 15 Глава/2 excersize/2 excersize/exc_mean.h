#pragma once
#include <stdexcept>
#include <iostream>

class bad_hmean : public std::logic_error
{
public:
	double v1, v2;

	bad_hmean(double a, double b);
	void what();
};

class bad_gmean : public std::logic_error
{
public:
	double v1, v2;
	bad_gmean(double a, double b);
	std::string what();
};