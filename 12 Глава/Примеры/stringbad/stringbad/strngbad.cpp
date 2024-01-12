#include "strngbad.h"
#include <cstring>

using std::cout;
int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
	len = std::strlen(s) + 1;
	str = new char[len];
	strcpy_s(str, len, s);
	num_strings++;
	cout << num_strings << ": object \"" << str << "\" is created\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[len];
	strcpy_s(str, len, "C++");
	num_strings++;
	cout << num_strings << ": object \"" << str << "\" is created\n";
}

StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len, st.str);
}

StringBad::~StringBad()
{
	cout << "Object \"" << str << "\" is deleted, ";
	--num_strings;	
	cout << num_strings << " left\n";
	delete[] str;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;
	// My version
	/*StringBad tmp = StringBad(st.str);
	return tmp;*/
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len, st.str);
	return *this;
	// TODO: вставьте здесь оператор return
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
