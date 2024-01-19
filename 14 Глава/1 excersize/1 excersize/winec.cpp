#include "winec.h"

Wine::Wine() : age(0)
{
	
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	years_and_bottles.first().resize(y);
	years_and_bottles.second().resize(y);
	name = l;
	age = y;
	// Initialize valarrays
	for (int i = 0; i < y; ++i)
	{
		years_and_bottles.first()[i] = yr[i];
		years_and_bottles.second()[i] = bot[i];
	}
}

Wine::Wine(const char* l, int y)
{
	years_and_bottles.first().resize(y);
	years_and_bottles.second().resize(y);
	name = l;
	age = y;
	//Initialize valarrays
	for (int i = 0; i < y; ++i) 
	{
		years_and_bottles.first()[i] = 0;
		years_and_bottles.second()[i] = 0;
	}
}

void Wine::GetBottles()
{
	std::cout << "Input data for " << name << " for 4 years: " << std::endl;
	for (int i = 0; i < age; ++i) 
	{
		std::cout << "Input year: ";
		std::cin >> years_and_bottles.first()[i];
		std::cout << "Input number of bottles of this year: ";
		std::cin >> years_and_bottles.second()[i];
	}
}

int Wine::sum()
{
	unsigned long long int sum = 0;
	for (int i = 0; i < age; ++i)
		sum += years_and_bottles.second()[i];
	return sum;
}

void Wine::Show()
{
	const char* spaces = "    ";
	std::cout << "Wine: " << name << std::endl;
	std::cout << spaces << "Year" << spaces << "Bottles" << std::endl;
	for (int i = 0; i < age; ++i)
	{
		std::cout << spaces << years_and_bottles.first()[i] << spaces <<
			years_and_bottles.second()[i] << std::endl;
	}
}
