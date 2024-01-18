#include "Port.h"

// Port methods
Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
	strcpy_s(style, 20, st);
	bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, 20, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	if (this != &p)
	{
		delete[] brand;
		brand = new char[strlen(p.brand) + 1];
		strcpy_s(brand, strlen(p.brand) + 1, p.brand);
		strcpy_s(style, 20, p.style);
		bottles = p.bottles;
	}
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-=(int b)
{
	if (bottles >= b) bottles -= b;
	return *this;
}

void Port::Show() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}


// VintagePort methods
VintagePort::VintagePort() : Port()
{
	nickname = new char[5];
	strcpy_s(nickname, 5, "none");
	year = 0; 
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this != &vp)
	{
		Port::operator=(vp);
		delete[] nickname;
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
		year = vp.year;
	}
	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << (const Port&) vp;
	os << ", " << vp.nickname << ", " << vp.year;
	return os;
}