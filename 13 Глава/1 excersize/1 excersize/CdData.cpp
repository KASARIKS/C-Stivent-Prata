#include "CdData.h"
#include <iostream>

// Cd methods
Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[50];
	label = new char[20];
	strcpy_s(performers, 50, s1);
	strcpy_s(label, 20, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	delete[] performers;
	delete[] label;
	performers = new char[50];
	label = new char[20];
	strcpy_s(performers, 50, d.performers);
	strcpy_s(label, 20, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char[50];
	label = new char[20];
	strcpy_s(performers, 50, "");
	strcpy_s(label, 20, "");
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const
{
	std::cout << "Performance: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
	std::cout << "Selections: " << selections << std::endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[50];
	label = new char[20];
	strcpy_s(performers, 50, d.performers);
	strcpy_s(label, 20, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

// Clasic methods

void Clasic::Report() const
{
	Cd::Report();
	std::cout << "Favorite composition: " << favorite_composition << std::endl;
}

Clasic::Clasic(const char* s1, const char* s2, const char* s3, int n, double x) 
	: Cd(s1, s2, n, x)
{
	favorite_composition = new char[50];
	strcpy_s(favorite_composition, 50, s3);
}

Clasic::Clasic(const Clasic& d) : Cd(d)
{
	delete[] favorite_composition;
	favorite_composition = new char[50];
	strcpy_s(favorite_composition, 50, d.favorite_composition);
}

Clasic::Clasic() : Cd()
{
	favorite_composition = new char[50];
	strcpy_s(favorite_composition, 50, "");
}

Clasic::~Clasic()
{
	delete[] favorite_composition;
}

Clasic& Clasic::operator=(const Clasic& d)
{
	if (this == &d)
		return *this;
	Cd::operator=(d);
	delete[] favorite_composition;
	favorite_composition = new char[50];
	strcpy_s(favorite_composition, 50, d.favorite_composition);
	return *this;
}
