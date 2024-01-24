#pragma once
#include <stdexcept>
#include <iostream>

class info : public std::logic_error
{
protected:
	double v1, v2;
	info(double a, double b);
public:
	virtual std::string what();
};

class bad_hmean : public info
{
public:
	bad_hmean(double a, double b);
	std::string what();
};

class bad_gmean : public info
{
public:
	bad_gmean(double a, double b);
	std::string what();
};