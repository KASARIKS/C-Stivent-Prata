#include "Plorg.h"

using namespace PLORG;

Plorg::Plorg(std::string name, int ci) {
	if (name.size() > MAXLEN) name.erase(MAXLEN, name.size());
	this->name = name != "" ? name : "<Unknown>";
	this->ci = ci;
}

void Plorg::SetCI(int ci) {
	this->ci = ci;
}

void Plorg::SayInfo() const {
	std::cout << "Plorg info: " << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "CI: " << ci << std::endl;
}