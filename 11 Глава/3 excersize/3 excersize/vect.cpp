#include "vect.h"
#include <cmath>

const double RAD_TO_DEG = 57.2957795130823;

void VECTOR::Vector::set_mag()
{
	mag = sqrt(x * x + y * y);
}

void VECTOR::Vector::set_ang()
{
	if (x == 0.0 && y == 0.0)
		ang = 0.0;
	else
		ang = std::atan2(y, x);
}

void VECTOR::Vector::set_x()
{
	x = mag * std::cos(ang);
}

void VECTOR::Vector::set_y()
{
	y = mag * std::sin(ang);
}

VECTOR::Vector::Vector()
{
	x = y = mag = ang = 0.0;
	mode = 'r';
}

VECTOR::Vector::Vector(double n1, double n2, char form)
{
	mode = form;
	if (form == 'r')
	{
		x = n1, y = n2;
		set_mag(), set_ang();
	}
	else if (mode == 'p')
	{
		mag = n1;
		ang = n2 / RAD_TO_DEG;
		set_x(), set_y();
	}
	else
	{
		x = y = mag = ang = 0.0;
		mode = 'r';
		std::cout << "3rd Vector() argument is wrong! -- vector set to 0" << std::endl;
	}
}

void VECTOR::Vector::set(double n1, double n2, char form)
{
	mode = form;
	if (form == 'r')
	{
		x = n1, y = n2;
		set_mag(), set_ang();
	}
	else if (mode == 'p')
	{
		mag = n1;
		ang = n2 / RAD_TO_DEG;
		set_x(), set_y();
	}
	else
	{
		x = y = mag = ang = 0.0;
		mode = 'r';
		std::cout << "3rd Vector() argument is wrong! -- vector set to 0" << std::endl;
	}
}

VECTOR::Vector VECTOR::Vector::operator+(const Vector& b) const
{
	return Vector(x + b.x, y + b.y);
}

VECTOR::Vector VECTOR::Vector::operator-(const Vector& b) const
{
	return Vector(x - b.x, y - b.y);
}

VECTOR::Vector VECTOR::Vector::operator-() const
{
	return Vector(-x, -y);
}

VECTOR::Vector VECTOR::Vector::operator*(double n) const
{
	return Vector(n * x, n * y);
}

VECTOR::Vector VECTOR::operator*(double n, const Vector& a)
{
	return a * n;
}

std::ostream& VECTOR::operator<<(std::ostream& os, const Vector& v)
{
	if (v.mode == 'r')
		os << "(x,y) = (" << v.x << ", " << v.y << ")";
	else if (v.mode == 'p')
		os << "(m,a) = (" << v.mag << ", " << v.ang * RAD_TO_DEG << ")";
	else
		os << "Object mode is wrong!";
	return os;
}
