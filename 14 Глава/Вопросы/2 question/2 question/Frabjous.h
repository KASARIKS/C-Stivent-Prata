#pragma once
#include <iostream>
using std::cout;
class Frabjous
{
private:
	char fab[20];
public:
	Frabjous(const char* s = "C++");
	virtual void tell() { cout << fab; }
};

class Gloam
{
private:
	int glip;
	Frabjous fb;
public:
	Gloam(int g = 0, const char* s = "C++");
	Gloam(int g, const Frabjous& f);
	void tell();
};