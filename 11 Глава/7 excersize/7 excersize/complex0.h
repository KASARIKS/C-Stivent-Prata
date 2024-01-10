#pragma once
#include <iostream>
class complex
{
private:
	double real, imaginary;
public:
	explicit complex();
	explicit complex(double real, double imaginary);

	// Math operations	
	complex operator+(complex b) { return complex(this->real + b.real, this->imaginary + b.imaginary); }
	complex operator-(complex b) { return complex(this->real - b.real, this->imaginary - b.imaginary); }
	complex operator*(complex b) 
		{ return complex(this->real * b.real - this->imaginary * b.imaginary, 
			this->real * b.imaginary + this->imaginary * b.real); }
	friend complex operator*(double number, complex b) { return complex(number * b.real, number * b.imaginary); }
	complex operator~() { return complex(this->real, -this->imaginary); }

	// Operations of output and input
	friend std::ostream& operator<< (std::ostream& os, complex num);
	friend std::istream& operator>> (std::istream& os, complex& num);
};