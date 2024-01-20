#include "wine.h"

Wine::Wine() : age(0)
{

}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	PairArray::first().resize(y);
	PairArray::second().resize(y);
	name = l;
	age = y;
	// Initialize valarrays
	for (int i = 0; i < y; ++i)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}
}

Wine::Wine(const char* l, int y)
{
	PairArray::first().resize(y);
	PairArray::second().resize(y);
	name = l;
	age = y;
	//Initialize valarrays
	for (int i = 0; i < y; ++i)
	{
		PairArray::first()[i] = 0;
		PairArray::second()[i] = 0;
	}
}

void Wine::GetBottles()
{
	std::cout << "Input data for " << name << " for 4 years: " << std::endl;
	for (int i = 0; i < age; ++i)
	{
		std::cout << "Input year: ";
		std::cin >> PairArray::first()[i];
		std::cout << "Input number of bottles of this year: ";
		std::cin >> PairArray::second()[i];
	}
}

int Wine::sum()
{
	unsigned long long int sum = 0;
	for (int i = 0; i < age; ++i)
		sum += PairArray::second()[i];
	return sum;
}

void Wine::Show()
{
	const char* spaces = "    ";
	std::cout << "Wine: " << name << std::endl;
	std::cout << spaces << "Year" << spaces << "Bottles" << std::endl;
	for (int i = 0; i < age; ++i)
	{
		std::cout << spaces << PairArray::first()[i] << spaces <<
			PairArray::second()[i] << std::endl;
	}
}
