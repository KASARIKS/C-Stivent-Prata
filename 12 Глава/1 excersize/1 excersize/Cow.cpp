#include "Cow.h"
#include <cstring>
#include <iostream>

Cow::Cow()
{
	const char* hobby = "Eat grass\0";
	const char* name = "Murka\0";
	this->hobby = new char[strlen(hobby) + 1];
	strcpy_s(this->hobby, strlen(hobby) + 1, hobby);
	strcpy_s(this->name, strlen(name) + 1, name);
	weight = 100;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	this->hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
	strcpy_s(name, strlen(nm) + 1, nm);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	strcpy_s(name, strlen(c.name) + 1, c.name);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{	
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	strcpy_s(name, strlen(c.name) + 1, c.name);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Hobby: " << hobby << std::endl;
	std::cout << "Weight: " << weight << " kilograms" << std::endl;
}
