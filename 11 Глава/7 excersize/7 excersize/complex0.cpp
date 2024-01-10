#include "complex0.h"

complex::complex()
{
	real = imaginary = 0;
}

complex::complex(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

std::ostream& operator<<(std::ostream& os, complex num)
{
	os << "(" << num.real << ", " << num.imaginary << "i)";
	return os;
}

std::istream& operator>>(std::istream& os, complex& num)
{
	std::cout << "Real part: ";
	if(!(os >> num.real)) return os;
	std::cout << "Imaginary part: ";
	os >> num.imaginary;
	return os;
}
