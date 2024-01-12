#pragma once
// Modify version of strngbad
// Now it's not bad string
#include <iostream>

class StringBad
{
private:
	char* str;
	int len;
	static int num_strings;
public:
	StringBad(const char* s);
	StringBad();
	StringBad(const StringBad& st); // Copy constructor
	~StringBad();
	friend std::ostream& operator<< (std::ostream & os, const StringBad & st);
	StringBad& operator=(const StringBad& st);
};